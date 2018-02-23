/*
 * u8x8_atmega328p.c
 *
 * Created: 2/22/2018 2:18:38 PM
 *  Author: matth
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "u8x8_atmega328p.h"

// (LCD PIN) = DEFINED PIN
// (PSB) = GND
// (R/S) = CS
// (R/W) = SID (DATA OUT/MOSI)
// (E) = SCK
// (RST) = RESET

#define SW_SPI_PORT PORTD
#define SW_SPI_DDR DDRD

#define SW_SPI_CS PORTD2
#define SW_SPI_MOSI PORTD3
#define SW_SPI_SCK PORTD4

#define CONTROL_DDR DDRD
#define CONTROL_PORT PORTD
#define CONTROL_RESET_PIN PORTD5

void InitLCD()
{
	u8g2_Setup_st7920_s_128x64_1(&u8g2, U8G2_R0, u8x8_byte_4wire_sw_spi, u8x8_gpio_and_delay);
	u8g2_InitDisplay(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);
}

uint8_t u8x8_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
	 switch(msg)
	 {
		 case U8X8_MSG_GPIO_AND_DELAY_INIT:	// called once during init phase of u8g2/u8x8
			SW_SPI_DDR |= (1 << SW_SPI_CS) | (1 << SW_SPI_MOSI) | (1 << SW_SPI_SCK); 
			CONTROL_DDR |= (1 << CONTROL_RESET_PIN);
		 break;		
		 case U8X8_MSG_DELAY_10MICRO:		// delay arg_int * 10 micro seconds
		 break;								// not needed, atmega328p is so slow
		 case U8X8_MSG_DELAY_MILLI:			// delay arg_int * 1 milli second
		 break;
		 case U8X8_MSG_GPIO_SPI_CLOCK:
			if(arg_int)
				SW_SPI_PORT |= (1 << SW_SPI_SCK); // CLK = HIGH
			else
				SW_SPI_PORT &= ~(1 << SW_SPI_SCK); // CLK = LOW

		 break;
		 case U8X8_MSG_GPIO_SPI_DATA:
			if(arg_int)
				SW_SPI_PORT |= (1 << SW_SPI_MOSI);
			else
				SW_SPI_PORT &= ~(1 << SW_SPI_MOSI);
		 break;
		 case U8X8_MSG_GPIO_CS:				// CS (chip select) pin: Output level in arg_int
			if(arg_int)
				SW_SPI_PORT |= (1 << SW_SPI_CS);
			else
				SW_SPI_PORT &= ~(1 << SW_SPI_CS);
		 break;
		 case U8X8_MSG_GPIO_DC:				// DC (data/cmd, A0, register select) pin: Output level in arg_int
		 break;
		 case U8X8_MSG_GPIO_RESET:			// Reset pin: Output level in arg_int
			if(arg_int)
				CONTROL_PORT |= (1 << CONTROL_RESET_PIN);
			else
				CONTROL_PORT &= ~(1 << CONTROL_RESET_PIN);
		 break;

		 default:
			u8x8_SetGPIOResult(u8x8, 1);			// default return value
		 break;
	 }
	 return 1;
}
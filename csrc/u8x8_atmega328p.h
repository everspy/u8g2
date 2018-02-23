/*
 * u8x8_atmega328p.h
 *
 * Created: 2/22/2018 6:22:23 PM
 *  Author: matth
 */ 


#ifndef U8X8_ATMEGA328P_H_
#define U8X8_ATMEGA328P_H_

#include "u8g2/u8g2.h"
#include "u8g2/u8x8.h"

u8g2_t u8g2;

void InitLCD();
uint8_t u8x8_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#endif /* U8X8_ATMEGA328P_H_ */
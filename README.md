![https://raw.githubusercontent.com/wiki/olikraus/u8g2/ref/u8g2_logo_transparent_orange.png](https://raw.githubusercontent.com/wiki/olikraus/u8g2/ref/u8g2_logo_transparent_orange.png) 


U8g2: Library for monochrome displays, version 2

U8g2 is a monochrome graphics library for embedded devices. U8g2 supports controller based (for example SSD1306) monochrome OLEDs and LCDs (See the U8g2/U8x8 setup guide for a complete list of supported display controller). 
The Arduino library U8g2 can be installed from the library manager of the Arduino IDE. U8g2 also includes U8x8 library:
 * U8g2
   * Includes all graphics procedures (line/box/circle draw).
   * Supports many fonts. (Almost) no restriction on the font height.
   * Requires some memory in the microcontroller to render the display.
 * U8x8
   * Text output only (character) device.
   * Only fonts allowed with fixed size per character (8x8 pixel).
   * Writes directly to the display. No buffer in the microcontroller required.

 * Note for this forked version
    * Modified to use with the ATmega328P
    * Tested with ST7920
    
[Setup Guide and Reference Manual](https://github.com/olikraus/u8g2/wiki)

Wiring:<br />

RS -> PD2 (CS)<br />
R/W -> PD3 (MOSI)<br />
E -> PD4 (SCK)<br />
RESET -> PD5<br />

These can be changed in the u8x8_atmega328p.c file.
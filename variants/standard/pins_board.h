#ifndef Pins_Board_h
#define Pins_Board_h

#include "pins_arduino.h"

// Tactile Switch (SW)
#define PIN_SW_MODE (INPUT_PULLUP)
#define PIN_SW_1    (0)
#define PIN_SW_2    (1)
#define PIN_SW_3    (2)
#define PIN_SW_4    (3)
#define PIN_SW_5    (4)

// 5-Way Tactile Switch (JOY)
#define PIN_JOY_MODE  (INPUT_PULLUP)
#define PIN_JOY_A     (0)
#define PIN_JOY_B     (4)
#define PIN_JOY_C     (2)
#define PIN_JOY_D     (3)
#define PIN_JOY_PRESS (1)
#define PIN_JOY_UP    (PIN_JOY_A)
#define PIN_JOY_DOWN  (PIN_JOY_D)
#define PIN_JOY_LEFT  (PIN_JOY_C)
#define PIN_JOY_RIGHT (PIN_JOY_B)

// Potentiometers (POT1 and POT2)
#define PIN_POT_1 (A0)
#define PIN_POT_2 (A1)

// 8-channel Darlington Sink Driver (ULN) (ULN2803APG)
#define PIN_ULN_1 (8)
#define PIN_ULN_2 (9)
#define PIN_ULN_3 (10)
#define PIN_ULN_4 (11)
#define PIN_ULN_5 (12)
#define PIN_ULN_6 (13)
#define PIN_ULN_7 (14)
#define PIN_ULN_8 (15)

// RGB LED (RGB)
#define PIN_RGB_R (12)
#define PIN_RGB_G (13)
#define PIN_RGB_B (15)

// Buzzer (BUZ)
#define PIN_BUZ (27) // A3

// Double 7-Segment Display (7LED) (7SEG)
#define PIN_7SEG_A  (31)
#define PIN_7SEG_B  (30)
#define PIN_7SEG_C  (29)
#define PIN_7SEG_D  (28)
#define PIN_7SEG_E  (23)
#define PIN_7SEG_F  (22)
#define PIN_7SEG_G  (21)
#define PIN_7SEG_DP (20)
#define PIN_7SEG_D1 (19)
#define PIN_7SEG_D2 (18)

// LCD 16x2 Parallel (LCD) (4bit mode)
#define PIN_LCD_RS (20)
#define PIN_LCD_RW (21)
#define PIN_LCD_EN (22)
#define PIN_LCD_D4 (28)
#define PIN_LCD_D5 (29)
#define PIN_LCD_D6 (30)
#define PIN_LCD_D7 (31)
#define PIN_LCD_BL (23)

// Clock and calendar with 240 x 8-bit RAM (RTC) (I2C) (PCF8583)
#define PIN_RTC_SDA  (PIN_WIRE_SDA)
#define PIN_RTC_SCL  (PIN_WIRE_SCL)
#define PIN_RTC_ADDR (0b10100000)

// 12-Bit Voltage Output Digital-to-Analog Converter with SPI Interface (DAC) (SPI) (MCP4921)
#define PIN_DAC_SCK  (PIN_SPI_SCK)
#define PIN_DAC_SDI  (PIN_SPI_MOSI)
#define PIN_DAC_VOUT (15)

// 2-Wire Serial Temperature Sensor (TEMP) (I2C) (TCN75AV)
#define PIN_TEMP_SDA  (PIN_WIRE_SDA)
#define PIN_TEMP_SCL  (PIN_WIRE_SCL)
#define PIN_TEMP_ADDR (0b1001111)

#endif // Pins_Board_h

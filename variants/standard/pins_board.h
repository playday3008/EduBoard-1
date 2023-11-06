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

// Potentiometer 1 (POT1)
#define PIN_POT1 (A0)

// Potentiometer 2 (POT2)
#define PIN_POT2 (A1)

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

// RGB LED (RGB)
#define PIN_RGB_R (12)
#define PIN_RGB_G (13)
#define PIN_RGB_B (15)

// 8-channel Darlington Sink Driver (ULN) (ULN2803APG)
#define PIN_ULN_1 (8)
#define PIN_ULN_2 (9)
#define PIN_ULN_3 (10)
#define PIN_ULN_4 (11)
#define PIN_ULN_5 (12)
#define PIN_ULN_6 (13)
#define PIN_ULN_7 (14)
#define PIN_ULN_8 (15)

// LCD 16x2 Parallel (LCD) (4bit mode)
#define PIN_LCD_RS (20)
#define PIN_LCD_RW (21)
#define PIN_LCD_EN (22)
#define PIN_LCD_D4 (28)
#define PIN_LCD_D5 (29)
#define PIN_LCD_D6 (30)
#define PIN_LCD_D7 (31)

// Double 7-Segment Display (7LED) (7SEG)
#define PIN_7SEG_A  (19)
#define PIN_7SEG_B  (30)
#define PIN_7SEG_C  (21)
#define PIN_7SEG_D  (22)
#define PIN_7SEG_E  (31)
#define PIN_7SEG_F  (28)
#define PIN_7SEG_G  (18)
#define PIN_7SEG_DP (20)
#define PIN_7SEG_D1 (23)
#define PIN_7SEG_D2 (29)

// Buzzer (BUZ)
#define PIN_BUZ (27) // A3

// 2-Wire Serial Temperature Sensor (TMP) (I2C) (TCN75AV)
#define PIN_TMP_SDA  (17)
#define PIN_TMP_SCL  (16)
#define PIN_TMP_ADDR (0b1001111)

// 12-Bit Voltage Output Digital-to-Analog Converter with SPI Interface (DAC) (SPI) (MCP4921)
#define PIN_DAC_SCK  (7)
#define PIN_DAC_SDI  (5)
#define PIN_DAC_VOUT (15)

// Clock and calendar with 240 x 8-bit RAM (RTC) (I2C) (PCF8583)
#define PIN_RTC_SDA  (17)
#define PIN_RTC_SCL  (16)
#define PIN_RTC_ADDR (0b1010000)

#endif // Pins_Board_h

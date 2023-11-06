/* Arduino SdFat Library
 * Copyright (C) 2010 by William Greiman
 *
 * This file is part of the Arduino SdFat Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino SdFat Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
#define __AVR__
#if defined(__arm__) // Arduino Due Board follows

#ifndef Sd2PinMap_h
#define Sd2PinMap_h

#include <Arduino.h>

uint8_t const SS_PIN = SS;
uint8_t const MOSI_PIN = MOSI;
uint8_t const MISO_PIN = MISO;
uint8_t const SCK_PIN = SCK;

#endif // Sd2PinMap_h

#elif defined(__AVR__) // Other AVR based Boards follows

// Warning this file was generated by a program.
#ifndef Sd2PinMap_h
#define Sd2PinMap_h
#include <avr/io.h>

//------------------------------------------------------------------------------
/** struct for mapping digital pins */
struct pin_map_t {
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  volatile uint8_t* port;
  uint8_t bit;
};
//------------------------------------------------------------------------------
// Two Wire (aka I2C) ports
uint8_t const SDA_PIN = 17;
uint8_t const SCL_PIN = 16;

// SPI port
uint8_t const SS_PIN = 4;
uint8_t const MOSI_PIN = 5;
uint8_t const MISO_PIN = 6;
uint8_t const SCK_PIN = 7;

static const pin_map_t digitalPinMap[] = {
  {&DDRB, &PINB, &PORTB, 0},  // B0  0
  {&DDRB, &PINB, &PORTB, 1},  // B1  1
  {&DDRB, &PINB, &PORTB, 2},  // B2  2
  {&DDRB, &PINB, &PORTB, 3},  // B3  3
  {&DDRB, &PINB, &PORTB, 4},  // B4  4
  {&DDRB, &PINB, &PORTB, 5},  // B5  5
  {&DDRB, &PINB, &PORTB, 6},  // B6  6
  {&DDRB, &PINB, &PORTB, 7},  // B7  7
  {&DDRD, &PIND, &PORTD, 0},  // D0  8
  {&DDRD, &PIND, &PORTD, 1},  // D1  9
  {&DDRD, &PIND, &PORTD, 2},  // D2 10
  {&DDRD, &PIND, &PORTD, 3},  // D3 11
  {&DDRD, &PIND, &PORTD, 4},  // D4 12
  {&DDRD, &PIND, &PORTD, 5},  // D5 13
  {&DDRD, &PIND, &PORTD, 6},  // D6 14
  {&DDRD, &PIND, &PORTD, 7},  // D7 15
  {&DDRC, &PINC, &PORTC, 0},  // C0 16
  {&DDRC, &PINC, &PORTC, 1},  // C1 17
  {&DDRC, &PINC, &PORTC, 2},  // C2 18
  {&DDRC, &PINC, &PORTC, 3},  // C3 19
  {&DDRC, &PINC, &PORTC, 4},  // C4 20
  {&DDRC, &PINC, &PORTC, 5},  // C5 21
  {&DDRC, &PINC, &PORTC, 6},  // C6 22
  {&DDRC, &PINC, &PORTC, 7},  // C7 23
  {&DDRA, &PINA, &PORTA, 0},  // A0 24
  {&DDRA, &PINA, &PORTA, 1},  // A1 25
  {&DDRA, &PINA, &PORTA, 2},  // A2 26
  {&DDRA, &PINA, &PORTA, 3},  // A3 27
  {&DDRA, &PINA, &PORTA, 4},  // A4 28
  {&DDRA, &PINA, &PORTA, 5},  // A5 29
  {&DDRA, &PINA, &PORTA, 6},  // A6 30
  {&DDRA, &PINA, &PORTA, 7}   // A7 31
};
//------------------------------------------------------------------------------
static const uint8_t digitalPinCount = sizeof(digitalPinMap)/sizeof(pin_map_t);

uint8_t badPinNumber(void)
  __attribute__((error("Pin number is too large or not a constant")));

static inline __attribute__((always_inline))
  uint8_t getPinMode(uint8_t pin) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    return (*digitalPinMap[pin].ddr >> digitalPinMap[pin].bit) & 1;
  } else {
    return badPinNumber();
  }
}
static inline __attribute__((always_inline))
  void setPinMode(uint8_t pin, uint8_t mode) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    if (mode) {
      *digitalPinMap[pin].ddr |= 1 << digitalPinMap[pin].bit;
    } else {
      *digitalPinMap[pin].ddr &= ~(1 << digitalPinMap[pin].bit);
    }
  } else {
    badPinNumber();
  }
}
static inline __attribute__((always_inline))
  uint8_t fastDigitalRead(uint8_t pin) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    return (*digitalPinMap[pin].pin >> digitalPinMap[pin].bit) & 1;
  } else {
    return badPinNumber();
  }
}
static inline __attribute__((always_inline))
  void fastDigitalWrite(uint8_t pin, uint8_t value) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    if (value) {
      *digitalPinMap[pin].port |= 1 << digitalPinMap[pin].bit;
    } else {
      *digitalPinMap[pin].port &= ~(1 << digitalPinMap[pin].bit);
    }
  } else {
    badPinNumber();
  }
}
#endif  // Sd2PinMap_h

#elif defined (__CPU_ARC__)

#if defined (__ARDUINO_ARC__)
// Two Wire (aka I2C) ports
uint8_t const SDA_PIN = 18;
uint8_t const SCL_PIN = 19;

// SPI port
uint8_t const SS_PIN = 10;
uint8_t const MOSI_PIN = 11;
uint8_t const MISO_PIN = 12;
uint8_t const SCK_PIN = 13;

#endif  // Arduino ARC

#else
#error Architecture or board not supported.
#endif

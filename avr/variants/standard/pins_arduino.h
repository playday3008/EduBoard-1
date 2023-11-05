#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define EDU_BOARD_1

// Digital pins
#define NUM_DIGITAL_PINS          (32)

// PWM pins
#define digitalPinHasPWM(p)       ((p) == 3 || (p) == 12 || (p) == 13 || (p) == 15)

// Builtin LED
#if !defined(LED_BUILTIN)
  #define LED_BUILTIN             (0)
#endif
static const uint8_t LED = LED_BUILTIN;

// Analog pins
#define PIN_A0 (24)
#define PIN_A1 (25)
#define PIN_A2 (26)
#define PIN_A3 (27)
#define PIN_A4 (28)
#define PIN_A5 (29)
#define PIN_A6 (30)
#define PIN_A7 (31)
static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
#define NUM_ANALOG_INPUTS           (8)
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)
#define analogPinToChannel(p)       ((p) < NUM_ANALOG_INPUTS ? (p) : (p) >= 24 ? (p) - 24 : -1)

// SPI
#define PIN_SPI_SS    (4)
#define PIN_SPI_MOSI  (5)
#define PIN_SPI_MISO  (6)
#define PIN_SPI_SCK   (7)
static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

// i2c
#define PIN_WIRE_SDA  (17)
#define PIN_WIRE_SCL  (16)
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// Interrupts
#define EXTERNAL_NUM_INTERRUPTS     (3)
#define digitalPinToInterrupt(p)    ((p) == 2 ? 2 : ((p) == 10 ? 0 : ((p) == 11 ? 1 : NOT_AN_INTERRUPT)))

#define PIN_PB0 0
#define PIN_PB1 1
#define PIN_PB2 2
#define PIN_PB3 3
#define PIN_PB4 4
#define PIN_PB5 5
#define PIN_PB6 6
#define PIN_PB7 7
#define PIN_PD0 8
#define PIN_PD1 9
#define PIN_PD2 10
#define PIN_PD3 11
#define PIN_PD4 12
#define PIN_PD5 13
#define PIN_PD6 14
#define PIN_PD7 15
#define PIN_PC0 16
#define PIN_PC1 17
#define PIN_PC2 18
#define PIN_PC3 19
#define PIN_PC4 20
#define PIN_PC5 21
#define PIN_PC6 22
#define PIN_PC7 23
#define PIN_PA0 24
#define PIN_PA1 25
#define PIN_PA2 26
#define PIN_PA3 27
#define PIN_PA4 28
#define PIN_PA5 29
#define PIN_PA6 30
#define PIN_PA7 31

#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
  PB, /* D0 */
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PD, /* D8 */
  PD,
  PD,
  PD,
  PD,
  PD,
  PD,
  PD,
  PC, /* D16 */
  PC,
  PC,
  PC,
  PC,
  PC,
  PC,
  PC,
  PA, /* D24 */
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
  _BV(0), /* D0, port B */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(0), /* D8, port D */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(0), /* D16, port C */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(0), /* D24, port A */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
};

// Timer defs
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER,   /* D0  - PB0 */
  NOT_ON_TIMER,   /* D1  - PB1 */
  NOT_ON_TIMER,   /* D2  - PB2 */
  TIMER0A,        /* D3  - PB3 */
  NOT_ON_TIMER,   /* D4  - PB4 */
  NOT_ON_TIMER,   /* D5  - PB5 */
  NOT_ON_TIMER,   /* D6  - PB6 */
  NOT_ON_TIMER,   /* D7  - PB7 */
  NOT_ON_TIMER,   /* D8  - PD0 */
  NOT_ON_TIMER,   /* D9  - PD1 */
  NOT_ON_TIMER,   /* D10 - PD2 */
  NOT_ON_TIMER,   /* D11 - PD3 */
  TIMER1B,        /* D12 - PD4 */
  TIMER1A,        /* D13 - PD5 */
  NOT_ON_TIMER,   /* D14 - PD6 */
  TIMER2,         /* D15 - PD7 */
  NOT_ON_TIMER,   /* D16 - PC0 */
  NOT_ON_TIMER,   /* D17 - PC1 */
  NOT_ON_TIMER,   /* D18 - PC2 */
  NOT_ON_TIMER,   /* D19 - PC3 */
  NOT_ON_TIMER,   /* D20 - PC4 */
  NOT_ON_TIMER,   /* D21 - PC5 */
  NOT_ON_TIMER,   /* D22 - PC6 */
  NOT_ON_TIMER,   /* D23 - PC7 */
  NOT_ON_TIMER,   /* D24 - PA0 */
  NOT_ON_TIMER,   /* D25 - PA1 */
  NOT_ON_TIMER,   /* D26 - PA2 */
  NOT_ON_TIMER,   /* D27 - PA3 */
  NOT_ON_TIMER,   /* D28 - PA4 */
  NOT_ON_TIMER,   /* D29 - PA5 */
  NOT_ON_TIMER,   /* D30 - PA6 */
  NOT_ON_TIMER    /* D31 - PA7 */
};

#endif // ARDUINO_MAIN

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.

#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial

#endif // Pins_Arduino_h

/*
  Part of the Wiring project - http://wiring.uniandes.edu.co

  Copyright (c) 2004-05 Hernando Barragan

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  Modified 24 November 2006 by David A. Mellis
  Modified 1 August 2010 by Mark Sproul
  Modified 24 April 2017 by MCUdude
*/

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "wiring_private.h"

static void nothing(void) {}

static volatile voidFuncPtr intFunc[EXTERNAL_NUM_INTERRUPTS] = {
#if EXTERNAL_NUM_INTERRUPTS > 8
#warning There are more than 8 external interrupts. Some callbacks may not be initialized.
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 7
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 6
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 5
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 4
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 3
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 2
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 1
    nothing,
#elif EXTERNAL_NUM_INTERRUPTS > 0
    nothing,
#endif
};

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
    if (interruptNum < EXTERNAL_NUM_INTERRUPTS) {
        intFunc[interruptNum] = userFunc;

        // Configure the interrupt mode (trigger on low input, any change,
        // rising edge, or falling edge).  The mode constants were chosen to
        // correspond to the configuration bits in the hardware register, so we
        // simply shift the mode into place.

        // Enable interrupt
        switch (interruptNum) {
            case 0:
                MCUCR = (MCUCR & ~((1 << ISC00) | (1 << ISC01))) |
                        (mode << ISC00);
                GICR |= (1 << INT0);
                break;
            case 1:
                MCUCR = (MCUCR & ~((1 << ISC10) | (1 << ISC11))) |
                        (mode << ISC10);
                GICR |= (1 << INT1);
                break;
            case 2:
                MCUCSR = (MCUCSR & ~((1 << ISC2))) |
                         ((mode & 0x01) << ISC2); // ATmega8535/16/32
                GICR |= (1 << INT2);
                break;
        }
    }
}

void detachInterrupt(uint8_t interruptNum) {
    if (interruptNum < EXTERNAL_NUM_INTERRUPTS) {
        // Disable interrupt
        switch (interruptNum) {
            case 0:
                GICR &= ~(1 << INT0);
                break;
            case 1:
                GICR &= ~(1 << INT1);
                break;
            case 2:
                GICR &= ~(1 << INT2);
                break;
        }
        intFunc[interruptNum] = nothing;
    }
}

#define IMPLEMENT_ISR(vect, interrupt) \
    ISR(vect) {                        \
        intFunc[interrupt]();          \
    }

IMPLEMENT_ISR(INT0_vect, EXTERNAL_INT_0)
IMPLEMENT_ISR(INT1_vect, EXTERNAL_INT_1)

/*
volatile static voidFuncPtr twiIntFunc;

void attachInterruptTwi(void (*userFunc)(void) )
{
  twiIntFunc = userFunc;
}

ISR(TWI_vect)
{
  if(twiIntFunc)
    twiIntFunc();
}
*/

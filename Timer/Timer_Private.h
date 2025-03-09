/*
 * Timer_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0 *((volatile u8 *)0x53)

#define WGM00      6
#define WGM01      3
#define CS00       0
#define CS01       1
#define CS02       2
#define COM00      4
#define COM01      5
#define FOC0       7

#define TIMSK *((volatile u8 *)0x59)

#define OCIE0 1
#define TOIE0 0


#define TIFR  *((volatile u8 *)0x58)

#define OCF0  1
#define TOV0  0


#define TCNT0 *((volatile u8 *)0x52)
#define OCR0  *((volatile u8 *)0x5C)

// Waveform generation modes
#define TIMER0_MODE_NORMAL               0
#define TIMER0_MODE_PWM_PHASE_CORRECT    1
#define TIMER0_MODE_CTC                  2
#define TIMER0_MODE_FAST_PWM             3

// Compare output modes
#define TIMER0_COMPARE_NORMAL            0
#define TIMER0_TOGGLE_OC0                1
#define TIMER0_CLEAR_OC0                 2
#define TIMER0_SET_OC0                   3





// Prescaler options
#define NO_CLOCK_SOURCE                 0
#define NO_PRESCALING                   1
#define PRESCALER_8                     8
#define PRESCALER_64                    64
#define PRESCALER_256                   256
#define PRESCALER_1024                  1024


#define ENABLE  1
#define DISABLE 0

#define       SET_OC0_ON_COMPARE     0
#define       CLEAR_OC0_ON_COMPARE   1
#endif

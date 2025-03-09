/*
 * Timer_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

#define TIMER0_WAVEFORM_GENERATION_MODE  TIMER0_MODE_FAST_PWM

#define TIMER0_COMPARE_OUTPUT_MODE       SET_OC0_ON_COMPARE

#define TIMER0_OVERFLOW_INTERRUPT        ENABLE
#define TIMER0_COMPARE_MATCH_INTERRUPT   DISABLE

#define TIMER0_PRESCALER                 PRESCALER_64

#endif

/*
 * ADC_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADCSR               *((volatile u8*)0x28)
#define ADMUX               *((volatile u8*)0x27)
#define ADCSRA			  *((volatile u8*)0x26)
#define ADCH			  *((volatile u8*)0x25)
#define	ADCL		  *((volatile u8*)0x24)


//voltage reference
#define AREF                    0
#define AVCC                    1
#define INTERNA_2_56            2

// ADJUSTMENT
#define  Left_adjust            0
#define  Right_adjust           1

//ADC Auto Trigger Source

#define FREE_RUNNING_MODE       0
#define ANALOG_COMPARATOR       1
#define EXT0_INT 		        2
#define TMR0_CMP 		        3
#define TMR0_OVF 		        4
#define TMR_CMP_B 		        5
#define TMR1_OVF 		        6
#define TMR1_CAPTURE 	        7

//ADC Prescaler Selections
#define PRE_2	                0
#define PRE_4	                1
#define PRE_8	                2
#define PRE_16	                3
#define PRE_32	                4
#define PRE_64	                5
#define PRE_128	                6

#define ADC_0	0
#define ADC_1	1
#define ADC_2	2
#define ADC_3	3
#define ADC_4	4
#define ADC_5	5
#define ADC_6	6
#define ADC_7	7

#endif

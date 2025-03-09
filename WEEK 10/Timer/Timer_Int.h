/*
 * Timer_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_


ES_t TIMER0_init(void);
ES_t Timer0_setPreload(u8Copy_u8preloadValue);
ES_t Timer0_setASyncDelay(u32 Copy_u32Time,void (*Copy_Pfunc)(void*),void *Copy_pvoidParameter);
ES_t TIMER0_GeneratePWM(u8 Copy_u8DutyCycle);
//ES_t TIMER0_setCompareValue(u8 Copy_u8Value);
ES_t TIMER0_callBack(void (*func)(void),void *Copy_pvidParameter);







#endif /* TIMER_INT_H_ */

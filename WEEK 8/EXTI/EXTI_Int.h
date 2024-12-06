/*
 * EXTI_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef EXTI_INT_H
#define EXTI_INT_H





ES_t  enu_init(EXTI_t * pst);
ES_t  enu_SenseLevel(u8 Copy_ID, u8 Copy_SenseLevel);
ES_t enu_Enable(u8 Copy_ID);
ES_t enu_Disable(u8 Copy_ID);
ES_t enu_CallBack(u8 Copy_ID,void (*Copy_pvoidCallBack)(void));





#endif

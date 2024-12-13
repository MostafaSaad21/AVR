/*
 * ADC_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */


#ifndef ADC_INT_H
#define ADC_INT_H

ES_t enu_ADCinit(void);
ES_t enu_StartConversion(void);

ES_t enu_ADCEnable(void);
ES_t enu_ADCDisable(void);
ES_t enu_INTEnable(void);
ES_t enu_INTDisable(void);
ES_t enu_GetResultSync(u16 *Copy_pu16Result);
ES_t enu_StartConversionAsynch(u16 *Copy_pu16Result, void (*Copy_pvNotificationFunc)(void));



#endif

/*
 * ADC_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */


#include"Stdh_types.h"
#include"ERROR.h"
#include"ADC_Private.h"
#include"ADC_Config.h"

static u16 * ADC_pu16AsynchConversionResult = NULL;
static void (* ADC_pvNotificationFunc)(void)= NULL;

ES_t enu_ADCinit(void)
{
	ES_t local_enumError=ES_NOK;

#if voltage_reference==AREF

	ADMUX &=~(1<<6) ;
	ADMUX &=~(1<<7) ;

#elif voltage_reference==AVCC

	ADMUX |=(1<<6) ;
	ADMUX &=~(1<<7) ;

#elif voltage_reference== INTERNA_2_56

	ADMUX |=(1<<6) ;
	ADMUX |=(1<<7) ;
#else
#error "Error in voltage_reference!!"
#endif

#if  ADC_ADJUSTMENT == Right_adjust
	ADMUX&=~(1<<5);
#elif  ADC_ADJUSTMENT == Left_adjust
	ADMUX|=(1<<5);
#else
#error "Error in Adjustment"
#endif

#if ADC_PRESCALERE == PRE_2
	ADCSRA |=  (1<<0);
	ADCSRA &=~ (1<<1);
	ADCSRA &=~ (1<<2);
#elif ADC_PRESCALERE == PRE_4
	ADCSRA &=~  (1<<0);
	ADCSRA |=   (1<<1);
	ADCSRA &=~  (1<<2);
#elif ADC_PRESCALERE == PRE_8
	ADCSRA |=  (1<<0);
	ADCSRA |=  (1<<1);
	ADCSRA &=~ (1<<2);
#elif ADC_PRESCALERE == PRE_16
	ADCSRA &=~  (1<<0);
	ADCSRA &=~  (1<<1);
	ADCSRA |=   (1<<2);
#elif ADC_PRESCALERE == PRE_32
	ADCSRA |=  (1<<0);
	ADCSRA &=~ (1<<1);
	ADCSRA |=  (1<<2);
#elif ADC_PRESCALERE == PRE_64
	ADCSRA &=~ (1<<0);
	ADCSRA |=  (1<<1);
	ADCSRA |=  (1<<2);
#elif ADC_PRESCALERE == PRE_128
	ADCSRA |=  (1<<0);
	ADCSRA |=  (1<<1);
	ADCSRA |=  (1<<2);
#else
#error "Error in Prescaler Division Factor !!"
#endif


	return local_enumError;
}

ES_t enu_StartConversion(void)
{
	ES_t local_enumError=ES_NOK;

    ADCSRA|=(1<<6);

	 local_enumError=ES_OK;

	return local_enumError;
}
ES_t enu_ADCEnable(void)
{

	ES_t local_enumError=ES_NOK;

       ADCSRA|=(1<<7);

   	 local_enumError=ES_OK;

	return local_enumError;
}
ES_t enu_ADCDisable(void)
{
	ES_t local_enumError=ES_NOK;

	ADCSRA &=~(1<<7);

   	 local_enumError=ES_OK;

	return local_enumError;
}

ES_t enu_INTEnable(void)
{
	ES_t local_enumError=ES_NOK;

    ADCSRA|=(1<<3);

   	 local_enumError=ES_OK;

	return local_enumError;
}
ES_t enu_INTDisable(void)
{
	ES_t local_enumError=ES_NOK;

    ADCSRA &=~(1<<7);

   	 local_enumError=ES_OK;

	return local_enumError;
}


ES_t enu_GetResultSync(u16 *Copy_pu16Result)
{
	ES_t local_enumError=ES_NOK;

	u32 Local_u32TimeoutCounter = 0 ;
		if (Copy_pu16Result != NULL)
		{

			ADMUX &=~ 0x1F;   // Set ADC_0

		    ADCSRA|=(1<<6);  //Start Conversion


				while ( (ADCSRA|=(1<<6) == 0) && (Local_u32TimeoutCounter < ADC_TIMEOUT))
				{
					Local_u32TimeoutCounter++ ;
				}
				if (Local_u32TimeoutCounter == ADC_TIMEOUT)
				{
					local_enumError = ES_NOK ;
				}
				else
				{
					ADCSRA |=(1<<4); //Clear the interrupt flag

					#if ADC_ADJUSTMENT == Right_adjust
						*Copy_pu16Result = (ADCL|(ADCH << 8))  ;

					#elif ADC_ADJUSTMENT == Left_adjust
						*Copy_pu16Result = ADCH<<2 ;
					#else
						#error " Wrong ADC_ADJUSTMENT"

					#endif
				}

				local_enumError = ES_OK ;
			}



		else
		{
			local_enumError = ES_NULLPOINTER ;
		}

	return local_enumError;
}

ES_t enu_StartConversionAsynch(u16 *Copy_pu16Result, void (*Copy_pvNotificationFunc)(void))
{
    ES_t local_enumError = ES_NOK;

    if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
    {

            ADC_pu16AsynchConversionResult = Copy_pu16Result;

            ADC_pvNotificationFunc = Copy_pvNotificationFunc;

            // Set channel is ADC0
            ADMUX &= ~0x1F;

            // Start Conversion
            ADCSRA|=(1<<6);

            // Enable  Interrupt
            ADCSRA|=(1<<7);

            local_enumError = ES_OK;
      }


    else
    {
        local_enumError = ES_NULLPOINTER;
    }

    return local_enumError;
}


void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void)
{
#if ADC_ADJUSTMENT == Right_adjust
					* ADC_pu16AsynchConversionResult = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == Left_adjust
					*ADC_pu16AsynchConversionResult = ADCH ;

               #else
                   #error "Error in Prescaler Division Factor !!"
               #endif

					ADC_pvNotificationFunc() ;

		            // Disable  Interrupt
				    ADCSRA &=~(1<<7);
}


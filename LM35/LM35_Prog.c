#include "Stdh_types.h"
#include "ERROR.h"

#include "../DIO_DRIVER/init.h"
#include "../ADC/ADC_Int.h"

#include "LM35_Int.h"

u8 LM35_u8GetTemp(LM35_CONFIG *lm35, u8 *Copy_u8TempValue)
{
    u8 Local_u8ErrorState = ES_NOK;
    u16 Local_u16ADCResult;
    u16 Local_u16AnalogValue;
    u16 Local_u16ADCReference;

    if ((lm35 != NULL) && (Copy_u8TempValue != NULL))
    {
        Local_u16ADCReference = (lm35->Copy_u8ADCVoltageReference) * 1000;


        enu_GetResultSync( &Local_u16ADCResult);

        if (lm35->Copy_u8ADCResolution == ADC_RESOLUTION_10_BIT)
        {
            Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * (u32)Local_u16ADCReference) / 1024UL);
        }
        else if (lm35->Copy_u8ADCResolution == ADC_RESOLUTION_8_BIT)
        {
            Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * (u32)Local_u16ADCReference) / 256UL);
        }
        else
        {
            Local_u8ErrorState = ES_NOK;
        }

        *Copy_u8TempValue = Local_u16AnalogValue / 10;
    }
    else
    {
        Local_u8ErrorState = ES_NULLPOINTER;
    }

    return Local_u8ErrorState;
}

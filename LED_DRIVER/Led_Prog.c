#include "Led_Config.h"
#include "Stdh_types.h"
#include "Led_Private.h"
#include "init.h"
#include "ERROR.h"


#include"Led_Private.h"

ES_t Intialize (Led_t *copy_Astrct)
{
	ES_t local_enumError=DIO_NOK;
	if(copy_Astrct!=NULL)
	{
		u8 local_itteration=0;
		for(local_itteration=0; local_itteration<Nom_of_Leds; local_itteration++)
		{
		local_enumError= Setpin_Direction(copy_Astrct[local_itteration].Led_Portid, copy_Astrct[local_itteration].Led_Pinid, DIO_U8OUTPUT);//make the pin output

if(copy_Astrct[local_itteration].Led_Connection==SINK)
{
 if(copy_Astrct[local_itteration].Led_Intial==LED_ON)
	{
	 local_enumError=Setpin_value(copy_Astrct[local_itteration].Led_Portid, copy_Astrct[local_itteration].Led_Pinid,DIO_U8LOW);
	}
else if(copy_Astrct[local_itteration].Led_Intial==LED_OFF)
	{
	 local_enumError=Setpin_value(copy_Astrct[local_itteration].Led_Portid, copy_Astrct[local_itteration].Led_Pinid,DIO_U8HIGH);

	}
else
{
	local_enumError=OUT_OF_RANGE;
}

}
else if(copy_Astrct[local_itteration].Led_Connection==SOURCE)
{
 if(copy_Astrct[local_itteration].Led_Intial==LED_ON)
	{
	 local_enumError=Setpin_value(copy_Astrct[local_itteration].Led_Portid, copy_Astrct[local_itteration].Led_Pinid,DIO_U8HIGH);
	}
else if(copy_Astrct[local_itteration].Led_Intial==LED_OFF)
	{
	 local_enumError=Setpin_value(copy_Astrct[local_itteration].Led_Portid, copy_Astrct[local_itteration].Led_Pinid,DIO_U8LOW);

	}

}
else
{
	local_enumError=OUT_OF_RANGE;
}
		}
	}
	else
	{
		 local_enumError=DIO_NULLPOINTER;

	}
    return local_enumError;

}

ES_t Led_TurnOn(Led_t *copy_pstrctLEDID)
{
	ES_t local_enumError=DIO_NOK;
	if(copy_pstrctLEDID!=NULL)
	{
		if(copy_pstrctLEDID->Led_Connection==SINK)
		{
			local_enumError= Setpin_Direction(copy_pstrctLEDID->Led_Portid, copy_pstrctLEDID->Led_Pinid, DIO_U8LOW);

		}
		else if(copy_pstrctLEDID->Led_Connection==SOURCE)
		{
			local_enumError= Setpin_Direction(copy_pstrctLEDID->Led_Portid, copy_pstrctLEDID->Led_Pinid, DIO_U8HIGH);

		}

		else
		{
			local_enumError=OUT_OF_RANGE;
		}

	}
	else
	   {
		 local_enumError=DIO_NULLPOINTER;

	   }
            return local_enumError;
}
ES_t Led_TurnOff(Led_t *copy_pstrctLEDID)
{
	ES_t local_enumError=DIO_NOK;
	if(copy_pstrctLEDID!=NULL)
	{
		if(copy_pstrctLEDID->Led_Connection==SINK)
		{
			local_enumError= Setpin_Direction(copy_pstrctLEDID->Led_Portid, copy_pstrctLEDID->Led_Pinid, DIO_U8HIGH);

		}
		else if(copy_pstrctLEDID->Led_Connection==SOURCE)
		{
			local_enumError= Setpin_Direction(copy_pstrctLEDID->Led_Portid, copy_pstrctLEDID->Led_Pinid, DIO_U8LOW);

		}

		else
		{
			local_enumError=OUT_OF_RANGE;
		}

	}
	else
	   {
		 local_enumError=DIO_NULLPOINTER;

	   }
    return local_enumError;

}




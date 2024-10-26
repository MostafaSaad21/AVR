#include "Stdh_types.h"
#include "ERROR.h"
#include "Switch_private.h"
#include "Switch_config.h"
#include "init.h"

ES_t Switch_init(SW_T *copy_Astrct)
{
	ES_t local_enumError=DIO_NOK;
	u8 local_itteration=0;

	if(copy_Astrct!=NULL)
	{
for(local_itteration=0; local_itteration<SWI_NUM; local_itteration++)
{
	local_enumError= Setpin_Direction(copy_Astrct[local_itteration].PORT_ID,  copy_Astrct[local_itteration].PIN_ID,DIO_U8INPUT);
	local_enumError=	 Setpin_value(copy_Astrct[local_itteration].PORT_ID, copy_Astrct[local_itteration].PIN_ID, copy_Astrct[local_itteration].SWITCH_STATE);

}



	}
	else
	{
		local_enumError=DIO_NULLPOINTER;

	}
	return local_enumError;


}

ES_t Switch_GetState(SW_T *copy_Astrct,u8 *copy_SWState)
{
	ES_t local_enumError=DIO_NOK;

	if(copy_Astrct!=NULL &&copy_SWState!=NULL )
	{

		local_enumError=	GetPin(copy_Astrct->PORT_ID, copy_Astrct->PIN_ID,copy_SWState);


	}
	else
	{
		local_enumError=DIO_NULLPOINTER;

	}
return local_enumError;
}

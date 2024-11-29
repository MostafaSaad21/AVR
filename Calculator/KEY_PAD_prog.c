/*
 * KEY_PAD_prog.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#include "DIO_Int.h"
#include "Stdh_types.h"
#include "ERROR.h"

#include "KEY_PAD_config.h"
#include "KEY_PAD_private.h"



ES_t GetPressedKey (void)
{
u8 Local_u8PressedKey= Not_Pressed,Local_u8CoulmnsIndex,Local_u8RowsIndex,Local_u8PinState;

static u8 Local_u8KPD_Arr[Rows_Num][Coulmns_Num]=KPD_ARR;
static u8 Local_u8KPD_CoulmnsArr[Coulmns_Num] = {C1_Pin  ,C2_Pin  ,C3_Pin  ,C4_Pin  };
static u8 Local_u8KPD_RowsArr[Rows_Num] = { R1_Pin  ,R2_Pin  ,R3_Pin  ,R4_Pin  };

for(Local_u8CoulmnsIndex=0;  Local_u8CoulmnsIndex < Coulmns_Num; Local_u8CoulmnsIndex++)
{
	//ACTIVATE COULMN
	Setpin_value(PORT,Local_u8KPD_CoulmnsArr[Local_u8CoulmnsIndex], DIO_U8LOW);


	for(Local_u8RowsIndex=0; Local_u8RowsIndex < Rows_Num; Local_u8RowsIndex++)
	{

      GetPin(PORT,Local_u8KPD_RowsArr[Local_u8RowsIndex],  &Local_u8PinState);

if(Local_u8PinState==DIO_U8LOW)
{
	Local_u8PressedKey=Local_u8KPD_Arr[ Local_u8RowsIndex][Local_u8CoulmnsIndex];
	//POLLING
	while(Local_u8PinState==DIO_U8LOW)
	{
		GetPin(PORT,Local_u8KPD_RowsArr[Local_u8RowsIndex],  &Local_u8PinState);
	}


	return Local_u8PressedKey ;
}
	}


	//DE ACTIVATE COULMN
		Setpin_value(PORT,Local_u8KPD_CoulmnsArr[Local_u8CoulmnsIndex], DIO_U8HIGH);





}

	return Local_u8PressedKey;
}


/*
 * SEVEN_SEGMENT_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#include "Stdh_types.h"
#include "ERROR.h"
#include "init.h"
#include "SEVEN_SEGMENT_config.h"
#include "SEVEN_SEGMENT_private.h"


SEG_t Array_of_Strct [SEVEN_SEGMENT_Nom]=
{
		{DIO_u8PORTA , DIO_u8PIN0 ,
		 DIO_u8PORTA , DIO_u8PIN1 ,
		 DIO_u8PORTA , DIO_u8PIN2 ,
		 DIO_u8PORTA , DIO_u8PIN3,
		 DIO_u8PORTA , DIO_u8PIN4,
		 DIO_u8PORTA , DIO_u8PIN5,
		 DIO_u8PORTA , DIO_u8PIN6 ,
		 NOT_CONNECTED , NOT_CONNECTED ,
		 NOT_CONNECTED , NOT_CONNECTED ,
		 CMN_CATHODE
		} ,

		{DIO_u8PORTB , DIO_u8PIN0 ,
		 DIO_u8PORTB , DIO_u8PIN1 ,
		 DIO_u8PORTB , DIO_u8PIN2,
		 DIO_u8PORTB , DIO_u8PIN3 ,
		 DIO_u8PORTB , DIO_u8PIN4 ,
		 DIO_u8PORTB , DIO_u8PIN5 ,
		 DIO_u8PORTB , DIO_u8PIN6 ,
		 NOT_CONNECTED , NOT_CONNECTED ,
		 NOT_CONNECTED , NOT_CONNECTED ,
		 CMN_ANODE
		}
};

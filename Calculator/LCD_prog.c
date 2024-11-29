/*
 * LCD_prog.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#include "Stdh_types.h"
#include "ERROR.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include "util/delay.h"
#include "DIO_Int.h"


ES_t LCD_enuInit(void)
{

	ES_t  local_enumError=DIO_NOK;
	_delay_ms(35);
	Setpin_Direction(RS_port,RS_pin,DIO_U8OUTPUT);
	Setpin_Direction(RW_port,RW_pin,DIO_U8OUTPUT);
	Setpin_Direction(EN_port,EN_pin,DIO_U8OUTPUT);

	 Setpin_Direction(D7_port,D7_pin,DIO_U8OUTPUT);
	 Setpin_Direction(D6_port,D6_pin,DIO_U8OUTPUT);
	 Setpin_Direction(D5_port,D5_pin,DIO_U8OUTPUT);
	 Setpin_Direction(D4_port,D4_pin,DIO_U8OUTPUT);

 #if    LCD_Mode==EIGHT_BITS

	 Setpin_Direction(D3_port,D3_pin,DIO_U8OUTPUT);
	 Setpin_Direction(D2_port,D2_pin,DIO_U8OUTPUT);
	 Setpin_Direction(D1_port,D1_pin,DIO_U8OUTPUT);
	 Setpin_Direction(D0_port,D0_pin,DIO_U8OUTPUT);

		 LCD_invidSendCommand ( 0x38);
#elif    LCD_Mode==FOUR_BITS

		 LCD_invidSendCommand (0x28);

#endif

_delay_ms(1);
LCD_invidSendCommand(0x0f);  //DISPLAY

_delay_ms(1);
LCD_invidSendCommand(0x01);  //CLEAR
_delay_ms(2);
LCD_invidSendCommand(0x06); //ENTRY MODE


	return local_enumError;
}

ES_t LCD_enuSendData(u8 copy_u8Data)
{
	ES_t local_enumError=DIO_NOK;
	 Setpin_value( RS_port,RS_pin,DIO_U8HIGH);  // RS DATA

            LCD_Latch( copy_u8Data) ;


	return local_enumError;
}

ES_t LCD_enuSendCommand(u8 copy_u8Command)
{
	ES_t local_enumError=DIO_NOK;

	 Setpin_value( RS_port,RS_pin,DIO_U8LOW);  // RS COMMAND

	   LCD_Latch(copy_u8Command) ;


	return local_enumError;
}

static inline void LCD_invidSendCommand (u8 copy_u8Command)
{
	 Setpin_value( RS_port,RS_pin,DIO_U8LOW);  // RS=0
		 Setpin_value( EN_port, EN_pin,DIO_U8LOW);  //EN=0

		 Setpin_value(RW_pin, RW_port, DIO_U8LOW);  //WRITE=0

		 Setpin_value(D7_port,D7_pin,(copy_u8Command>>7)&1);
		 Setpin_value(D6_port,D6_pin,(copy_u8Command>>6)&1);
		 Setpin_value(D5_port,D5_pin,(copy_u8Command>>5)&1);
		 Setpin_value(D4_port,D4_pin,(copy_u8Command>>4)&1);
		 Setpin_value(D3_port,D3_pin,(copy_u8Command>>3)&1);
		 Setpin_value(D2_port,D2_pin,(copy_u8Command>>2)&1);
		 Setpin_value(D1_port,D1_pin,(copy_u8Command>>1)&1);
		 Setpin_value(D0_port,D0_pin,(copy_u8Command>>0)&1);

	     Setpin_value(EN_port,EN_pin,DIO_U8HIGH);
	   _delay_ms(10);
	    Setpin_value(EN_port,EN_pin,DIO_U8LOW);
}
static void LCD_Latch(u8 copy_u8Data)
		{
	Setpin_value( EN_port, EN_pin,DIO_U8LOW);  //EN=0

		 Setpin_value(RW_pin, RW_port, DIO_U8LOW);  //WRITE=0

		 Setpin_value(D7_port,D7_pin,(copy_u8Data>>7)&1);
		 Setpin_value(D6_port,D6_pin,(copy_u8Data>>6)&1);
		 Setpin_value(D5_port,D5_pin,(copy_u8Data>>5)&1);
		 Setpin_value(D4_port,D4_pin,(copy_u8Data>>4)&1);
		 Setpin_value(D3_port,D3_pin,(copy_u8Data>>3)&1);
		 Setpin_value(D2_port,D2_pin,(copy_u8Data>>2)&1);
		 Setpin_value(D1_port,D1_pin,(copy_u8Data>>1)&1);
		 Setpin_value(D0_port,D0_pin,(copy_u8Data>>0)&1);

	     Setpin_value(EN_port,EN_pin,DIO_U8HIGH);
	   _delay_ms(10);
	    Setpin_value(EN_port,EN_pin,DIO_U8LOW);

		}



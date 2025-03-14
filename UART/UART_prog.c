/*
 * USART_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#include "Stdh_types.h"
#include "ERROR.h"

#include "UART_private.h"
#include "UART_config.h"



ES_t UART_Int()
{
	u8 Local_u8UCSRC = 0 ;
	u16 Local_u16UBRR = (u16)((F_CPU / (16 * Baud_Rate)) - 1) ;

		UBRRH = (u8)(Local_u16UBRR >> 8) ;
		UBRRL = (u8)Local_u16UBRR ;

#if Transmitter_Enable ==Enable
UCSRB |=(1<<TXEN);
#elif Transmitter_Enable ==Disable
UCSRB &=~(1<<TXEN);
#endif

#if Reciever_Enable ==Enable
UCSRB |=(1<<RXEN);
#elif Reciever_Enable ==Disable
UCSRB &=~(1<<RXEN);
#endif


#if Parity_Mode == Disable
UCSRC&=~(1<<UPM0);
UCSRC&=~(1<<UPM1);


	#elif Parity_Mode == Even_Parity
UCSRC&=~(1<<UPM0);
UCSRC|=(1<<UPM1);

	#elif Parity_Mode == Odd_Parity
UCSRC|=(1<<UPM0);
UCSRC|=(1<<UPM1);
	#else
		#error "Wrong USART_PARITY_MODE config"
	#endif

	#if STOP_Bit == STOP_1_Bit

UCSRC&=~(1<<USBS);
	#elif STOP_BIT == STOP_2_Bits
UCSRC|=(<<USBS);
	#else
		#error "Wrong USART_STOP_BIT config"
	#endif





#if Character_Size == Data_5_Bits

UCSRB &=~(1<<UCSZ2) ;
UCSRC &=~(1<<UCSZ1);
UCSRC &=~(1<<UCSZ0);

#elif Character_Size== Data_6_Bits

UCSRB &=~(1<<UCSZ2) ;
UCSRC &=~(1<<UCSZ1);
UCSRC |=(1<<UCSZ0);

#elif Character_Size== Data_7_Bits

UCSRB &=~(1<<UCSZ2) ;
UCSRC |=(1<<UCSZ1);
UCSRC &=~(1<<UCSZ0);

#elif Character_Size== Data_8_Bits

UCSRC |=(1<<URSEL);

UCSRB &=~(1<<UCSZ2) ;
UCSRC |=(1<<UCSZ1);
UCSRC |=(1<<UCSZ0);

#elif Character_Size== Data_9_Bits

UCSRB |=(1<<UCSZ2) ;
UCSRC |=(1<<UCSZ1);
UCSRC |=(1<<UCSZ0);
#endif

#if Mode_Select==Asynchronous_Operation

UCSRC &=~(1<<UMSEl);

    #if Double_Speed==Enable

Local_u16UBRR /= 2 ;
    UCSRA |=(1<<U2X);
    #elif Double_Speed==Disable

     UCSRA &=~(1<<U2X);

#endif

#elif Mode_Select ==Synchronous_Operation

Local_u16UBRR /= 8 ;
UCSRC |=(1<<UMSEl);

#endif
UCSRC|=(1<<URSEL);
UCSRC= Local_u8UCSRC ;

}
ES_t UART_SendCharData(u8 SendData)
{
	ES_t Localerrorstate=ES_NOK;

while(!((UCSRA>>UDRE)&1));
	   UDR= SendData ;
	   Localerrorstate=ES_OK;
	return Localerrorstate;

}
ES_t UART_RecieveCharData(u8 *RecieveData)

{

ES_t Localerrorstate=ES_NOK;

while(!((UCSRA>>RXC)&1));

      *RecieveData=UDR;

 Localerrorstate=ES_OK;

return Localerrorstate;
}

ES_t UART_SendStringData(const u8 *PCStr)
{
	ES_t Localerrorstate=ES_NOK;
	u8 index=0;
	while(PCStr[index]!='\0')
	{
		Localerrorstate=UART_SendCharData(PCStr[index]);
		index++;
	}
	return Localerrorstate;
}


ES_t UART_RecieveStringData(u8 * PCStr,u32 BufferSize)
{

	ES_t Localerrorstate=ES_NOK;
	u32 index=0;
	while(index < BufferSize)
	{
		Localerrorstate=UART_RecieveCharData(&PCStr[index]);
		index++;

	}
	return Localerrorstate;

}

/*
 * SPI_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */
/*
 * SPI_Prog.c
 *
 * Created on: ??/??/????
 * Author: MostafaSaad
 */

#include "Stdh_types.h"
#include "ERROR.h"

#include "SPI_Private.h"
#include "SPI_Config.h"

ES_t SPI_Init(void)
{
    /* Data Order */
    #if Data_Order == LSB
        SPCR |= (1 << DORD);
    #elif Data_Order == MSB
        SPCR &= ~(1 << DORD);
    #else
        #error "WRONG Data Order Configuration!"
    #endif

    /* Master/Slave Select */
    #if Master_Slave_Select == Master
        SPCR |= (1 << MSTR);
    #elif Master_Slave_Select == Slave
        SPCR &= ~(1 << MSTR);
    #else
        #error "WRONG Master/Slave Configuration!"
    #endif

    /* Clock Polarity */
    #if Clock_Polarity == Falling
        SPCR |= (1 << CPOL);
    #elif Clock_Polarity == Rising
        SPCR &= ~(1 << CPOL);
    #else
        #error "WRONG Clock Polarity Configuration!"
    #endif

    /* Clock Phase */
    #if Clock_Phase == Setup
        SPCR |= (1 << CPHA);
    #elif Clock_Phase == Sample
        SPCR &= ~(1 << CPHA);
    #else
        #error "WRONG Clock Phase Configuration!"
    #endif

    /* Clock Rate */
    #if ClockRate_Select == Frequency_div_128
        SPCR |= (1 << SPR1) | (1 << SPR0);
        SPSR &= ~(1 << SPI2X);
    #elif ClockRate_Select == Frequency_div_64
        SPCR |= (1 << SPR1);
        SPCR &= ~(1 << SPR0);
        SPSR &= ~(1 << SPI2X);
    #elif ClockRate_Select == Frequency_div_32
        SPCR |= (1 << SPR1);
        SPCR &= ~(1 << SPR0);
        SPSR |= (1 << SPI2X);
    #elif ClockRate_Select == Frequency_div_16
        SPCR &= ~(1 << SPR1);
        SPCR |= (1 << SPR0);
        SPSR &= ~(1 << SPI2X);
    #elif ClockRate_Select == Frequency_div_8
        SPCR &= ~(1 << SPR1);
        SPCR |= (1 << SPR0);
        SPSR |= (1 << SPI2X);
    #elif ClockRate_Select == Frequency_div_4
        SPCR &= ~(1 << SPR1);
        SPCR &= ~(1 << SPR0);
        SPSR &= ~(1 << SPI2X);
    #else
        #error "WRONG Clock Rate Configuration!"
    #endif

    /* SPI Interrupt */
    #if Interrupt_Mode == Enable
        SPCR |= (1 << SPIE);
    #elif Interrupt_Mode == Disable
        SPCR &= ~(1 << SPIE);
    #endif

    /* Enable SPI */
    #if SPI_Mode == Enable
        SPCR |= (1 << SPE);
    #elif SPI_Mode == Disable
        SPCR &= ~(1 << SPE);
    #endif

    return ES_OK;
}

ES_t SPI_Transceiver(u8 TransmitData, u8 *ReceiveData)
{
    if (ReceiveData != NULL)
    {
        SPDR = TransmitData;
        while (!(SPSR & (1 << SPIF)));
        *ReceiveData = SPDR;
        return ES_OK;
    }
    return ES_NULLPOINTER;
}


ES_t SPI_BufferTranceiver (u8 * TransmitData , u8 * ReceiveData , u8 BufferSize)
{
	ES_t LocalErrorState = ES_NOK ;
	u8 Local_Counter = 0 ;
	if ((TransmitData != NULL) && (ReceiveData != NULL))
	{
		while (Local_Counter < BufferSize)
		{
			SPI_Transceiver(TransmitData[Local_Counter] , &ReceiveData[Local_Counter]) ;
			Local_Counter++ ;
		}
		LocalErrorState=ES_OK;
	}
	else
	{
		LocalErrorState =ES_NULLPOINTER  ;
	}
	return LocalErrorState ;
}

/*
 * SPI_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

ES_t SPI_Int(void);
ES_t SPI_Tranceiver(u8 TransmitData,u8 *ReceiveData);
ES_t SPI_BufferTranceiver (u8 * TransmitData , u8 * ReceiveData , u8 BufferSize)





#endif


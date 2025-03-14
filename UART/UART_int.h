/*
 * UART_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef UART_INT_H_
#define UART_INT_H_



ES_t UART_Int(void);
ES_t UART_SendCharData(u8 SendData);
ES_t UART_RecieveCharData(u8 *RecieveData);
ES_t UART_SendStringData(const u8 *PCStr);
ES_t UART_RecieveStringData(u8 * PCStr,u32 BufferSize);








#endif /* UART_INT_H_ */

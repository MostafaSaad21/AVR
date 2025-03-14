/*
 * UART_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define F_CPU                                8000000UL
#define Baud_Rate                            9600UL

#define Parity_Mode                          Disable
#define STOP_Bit                             STOP_1_Bit
#define Double_Speed                         Disable

#define Transmitter_Enable                   Enable
#define Reciever_Enable                      Enable

#define Character_Size                       Data_5_Bits

#define Mode_Select                          Asynchronous_Operation



#endif /* UART_CONFIG_H_ */

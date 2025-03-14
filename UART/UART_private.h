/*
 * UART_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define UDR   *((volatile u8 *)0x2C)
#define UCSRA *((volatile u8 *)0x2B)

#define RXC            7
#define UDRE           5
#define PE             2
# define U2X           1

#define UCSRB *((volatile u8 *)0x2A)

#define RXEN           4
#define TXEN           3
#define  UCSZ2         2

#define REB8           1
#define TXB8           0

#define UCSRC *((volatile u8 *)0x40)

#define URSEL          7
#define UMSEl          6

#define UPM1           5
#define UPM0           4

#define USBS           3

#define  UCSZ1         2
#define  UCSZ0         1

#define UBRRH *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)





#define Enable         0
#define Disable        1

#define Even_Parity    2
#define Odd_Parity     3

# define Data_5_Bits    0
# define Data_6_Bits    1
# define Data_7_Bits    2
# define Data_8_Bits    3
# define Data_9_Bits    4


# define Asynchronous_Operation   0
# define Synchronous_Operation    1

#define STOP_2_Bits               0
#define STOP_1_Bit                1


#endif /* UART_PRIVATE_H_ */

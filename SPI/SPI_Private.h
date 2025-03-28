/*
 * SPI_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR     *((volatile u8 *)0x2D)

#define SPIE               7
#define SPE                6
#define DORD               5
#define MSTR               4
#define CPOL               3
#define CPHA               2
#define SPR1               1
#define SPR0               0






#define SPSR    *((volatile u8 *)0x2E)

#define SPIF               7
#define SPI2X              0

#define SPDR     *((volatile u8 *)0x2F)

#define Enable             1
#define Disable            0

#define MSB                1
#define LSB                0


#define Master             1
#define Slave              0


#define Falling            1
#define Rising             0

#define Setup              1
#define Sample             0


#define Frequeny_div_128   6
#define Frequeny_div_64    5
#define Frequeny_div_32    4
#define Frequeny_div_16    3
#define Frequeny_div_8     2
#define Frequeny_div_4     1
#define Frequeny_div_2     0









#endif /* SPI_PRIVATE_H_ */

/*
 * I2C_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define TWBR    *((volatile u8 *)0x20)
#define TWDR    *((volatile u8 *)0x23)

#define TWAR    *((volatile u8 *)0x22)

#define TWGCE    0



#define TWSR    *((volatile u8 *)0x21)

#define TWPS1    1
#define TWPS0    0


#define TWCR    *((volatile u8 *)0x56)

#define TWINT   7
#define TWEA     6
#define TWSTA   5
#define TWSTO   4
#define TWEN    2


#define PrescalerValue_1     1
#define PrescalerValue_4     2
#define PrescalerValue_16    3
#define PrescalerValue_64    4

#define Enable 1
#define Disable 0





#endif /* I2C_PRIVATE_H_ */

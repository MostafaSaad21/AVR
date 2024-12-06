/*
 * EXTI_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define GICR        *((volatile u8*)0x5B)
#define GIFR      *((volatile u8*)0x5A)

#define MCUCSR    *((volatile u8*)0x54)
#define MCUCR     *((volatile u8*)0x55)




#define Disable                0
#define Enable                 1

#define rising_edg             1
#define falling_edge           2
#define any_change             3
#define low_level              4


#endif

#ifndef INIT_H
#define INIT_H
#include "Stdh_types.h"
#include "ERROR.h"
#define DIO_u8PORTA      0
#define DIO_u8PORTB      1
#define DIO_u8PORTC      2
#define DIO_u8PORTD      3

#define DIO_u8PIN0       0
#define DIO_u8PIN1       1
#define DIO_u8PIN2       2
#define DIO_u8PIN3       3
#define DIO_u8PIN4       4
#define DIO_u8PIN5       5
#define DIO_u8PIN6       6
#define DIO_u8PIN7       7

#define   DIO_U8INPUT    0
#define   DIO_U8OUTPUT   1

#define   DIO_U8LOW      0
#define   DIO_U8HIGH     1

#define   DIO_U8FLOAT    0
#define   DIO_U8PULL_UP  1

ES_t DIO_init(void);
ES_t Setport_Direction(u8 copy_u8_PortId, u8 copy_u8_value);
ES_t Setport_value(u8 copy_u8_PortId, u8 copy_u8_value);
ES_t TogglePort(u8 copy_u8_PortId);
ES_t GetPort(u8 copy_u8_PortId, u8 *copy_pu8_value);
ES_t Setpin_Direction(u8 copy_u8_PortId, u8 copy_u8_PIN_Id, u8 copy_u8_value);
ES_t Setpin_value(u8 copy_u8_PortId, u8 copy_u8_PIN_Id, u8 copy_u8_value);
ES_t TogglePIN(u8 copy_u8_PortId, u8 copy_u8_PIN_Id);
ES_t GetPin(u8 copy_u8_PortId, u8 copy_u8_PIN_Id, u8 *copy_pu8_value);



#endif

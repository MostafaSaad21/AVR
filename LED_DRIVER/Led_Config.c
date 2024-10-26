#include "Led_Config.h"
#include "Stdh_types.h"
#include "Led_Private.h"
#include "init.h"



Led_t Astrct_led[Nom_of_Leds]={ { DIO_u8PORTA ,DIO_u8PIN0,SINK,LED_ON},
		                        { DIO_u8PORTB ,DIO_u8PIN5,SOURCE,LED_OFF},
		                        { DIO_u8PORTC ,DIO_u8PIN3,SINK,LED_ON}


};

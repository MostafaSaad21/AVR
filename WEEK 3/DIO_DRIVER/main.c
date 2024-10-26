#include "init.h"
#include <util/delay.h>


int main(void)
{

    DIO_init();

    while(1)
   {

    	Setpin_value(DIO_u8PORTA, DIO_u8PIN0 , DIO_U8LOW );
    	    	 Setpin_value(DIO_u8PORTA, DIO_u8PIN0 ,DIO_U8HIGH);
    	    	 _delay_ms(150);
    	    	 Setpin_value(DIO_u8PORTA, DIO_u8PIN1 ,DIO_U8HIGH);
    	    	 _delay_ms(150);

    	    	 Setpin_value(DIO_u8PORTA, DIO_u8PIN2 ,DIO_U8HIGH);
    	    	 _delay_ms(150);

    	    	 Setpin_value(DIO_u8PORTA, DIO_u8PIN3 ,DIO_U8HIGH);
    	    	 _delay_ms(150);

    	    	 Setpin_value(DIO_u8PORTA, DIO_u8PIN4 ,DIO_U8HIGH);
    	    	 _delay_ms(150);

    	    	 Setpin_value(DIO_u8PORTA, DIO_u8PIN5 ,DIO_U8HIGH);
    	    	 _delay_ms(150);




    	    	 Setpin_value(DIO_u8PORTA, DIO_u8PIN5 ,DIO_U8LOW);
    	    	    	    	 _delay_ms(150);
                 Setpin_value(DIO_u8PORTA, DIO_u8PIN4 ,DIO_U8LOW);
                   _delay_ms(150);
                   Setpin_value(DIO_u8PORTA, DIO_u8PIN3 ,DIO_U8LOW);
                      	    	    	    	 _delay_ms(150);
                                 Setpin_value(DIO_u8PORTA, DIO_u8PIN2 ,DIO_U8LOW);
                                     _delay_ms(150);
                                     Setpin_value(DIO_u8PORTA, DIO_u8PIN1 ,DIO_U8LOW);
                                        	    	    	    	 _delay_ms(150);
                                                   Setpin_value(DIO_u8PORTA, DIO_u8PIN0 ,DIO_U8LOW);
                                                       _delay_ms(150);
   }
    return 0;
}

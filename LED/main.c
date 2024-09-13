#include <util/delay.h>

typedef unsigned char u8;
#define DDRA  *((u8*)0x3A)
#define PORTA  *((u8*)0x3B)

int main(void)
{

	while(1)
	{
		DDRA|=(1<<4);   
			PORTA|=(1<<4);   
		    _delay_ms(1000);  
		    PORTA&=~(1<<4);
		    _delay_ms(1000);

	}
return 0;
}


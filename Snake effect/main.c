#include <util/delay.h>

typedef unsigned char u8;
#define DDRA  *((u8*)0x3A)
#define PORTA  *((u8*)0x3B)

int main(void)
{

	while(1)
	{
		for(int i=0; i<=7; i++)
		{
		DDRA|=(1<<i);   
		PORTA|=(1<<i);   
	    _delay_ms(500); 
		}
		for(int i=7; i>=0; i--)
		{
		    PORTA&=~(1<<i);
		    _delay_ms(500);
		}
	}
return 0;
}


#include <util/delay.h>
typedef unsigned char u8;
#define DDRA  *((u8*)0x3A)
#define PORTA  *((u8*)0x3B)
#define DDRB  *((u8*)0x37)
#define PORTB  *((u8*)0x38)
#define  PINA *((volatile u8*)0x39)
#define  PINB *((volatile u8*)0x36)

int main(void)
{

	DDRA=0xff;
	PORTA=0;
	DDRB=0;
	PORTB=0xff;
	while(1)
	{
	if(((PINB>>0)&1)==0)
	{
		PORTA|=(1<<0);
	}
		else if(((PINB>>1)&1)==0)
		{
				PORTA|=(1<<1);
					}
			else if(((PINB>>2)&1)==0)
		{
			PORTA|=(1<<0);
			PORTA|=(1<<1);

		}
		else
		{
			PORTA&=~(1<<0);
			PORTA&=~(1<<1);
		}

		}
return 0;
}


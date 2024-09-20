#include <util/delay.h>
typedef unsigned char u8;
#define DDRA  *((u8*)0x3A)
#define PORTA  *((u8*)0x3B)
#define DDRB  *((u8*)0x37)
#define PORTB  *((u8*)0x38)
#define PINA *((volatile u8*)0x39)
#define PINB *((volatile u8*)0x36)

int main(void)
{
    u8 segment[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}, count = 0;

    DDRB = 0xFF;
    PORTB = 0;

    DDRA = 0x00;
    PORTA = 0xFF;

    while(1)
    {
        PORTB = segment[count];


        if (((PINA >> 0) & 1) == 0)
        {
            if (count < 9)
            {
                count++;
                PORTB = segment[count];
                while (((PINA >> 0) & 1) == 0);

            }

        }

        else if (((PINA >> 1) & 1) == 0)
        {
            if (count > 0)
            {
                count--;
                PORTB = segment[count];
                 while (((PINA >> 1) & 1) == 0);

            }

        }
    }

    return 0;
}

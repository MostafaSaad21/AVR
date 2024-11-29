#include"Stdh_types.h"
#include"ERROR.h"
#include"Calc.h"
#include"LCD_int.h"
#include"LCD_private.h"
#include "LCD_config.h"
#include"KEY_PAD_int.h"
#include"KEY_PAD_private.h"
#include "KEY_PAD_config.h"
#include "util/delay.h"
#include "DIO_Int.h"



int main(void) {
    Calc_Start();

    char infix[25] = "";
    char postfix[25] = "";
    int index = 0;
    s32 result = 0;
    u8 local_ValueKey;

    while (1)
    {
        local_ValueKey = GetPressedKey();
        if (local_ValueKey != Not_Pressed) {
            if (local_ValueKey >= '0' && local_ValueKey <= '9') {

                infix[index++] = local_ValueKey;
                LCD_enuSendData(local_ValueKey);
            }
            else if (local_ValueKey == '+' || local_ValueKey == '-' ||
                     local_ValueKey == '*' || local_ValueKey == '/' ||
                     local_ValueKey == '(' || local_ValueKey == ')')
            {

                infix[index++] = local_ValueKey;
                LCD_enuSendData(local_ValueKey);
            }
            else if (local_ValueKey == '=')
            {

                LCD_enuSendData('=');
                infix[index] = '\0';
                if (Calc_InfixToPostfix(infix, postfix) == DIO_OK)
                {
                    if (Calc_EvaluatePostfix(postfix, &result) == DIO_OK)
                    {
                        LCD_enuSendCommand(0x01);

                        char digits[10];
                        int i = 0;
                        do {
                            digits[i++] = (result % 10) + '0';
                            result /= 10;
                        } while (result > 0);

                        while (i > 0) {
                            LCD_enuSendData(digits[--i]);
                        }
                    } else {
                        LCD_enuSendCommand(0xC0);
                        Calc_Error();
                    }

                }
                else
                {
                    LCD_enuSendCommand(0xC0);
                    Calc_Error();
                }

                index = 0;
            }
            else if (local_ValueKey == 'c') {
                index = 0;
                LCD_enuSendCommand(0x01);
            }
        }
    }

    return 0;
}

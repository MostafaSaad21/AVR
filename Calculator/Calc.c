#include "Stdh_types.h"
#include "ERROR.h"
#include "LCD_int.h"
#include "KEY_PAD_int.h"
#include "stack.h"
#include "util/delay.h"
#include "DIO_Int.h"

ES_t Calc_Start() {
    DIO_init();
    LCD_enuInit();

    LCD_enuSendData('W');
    LCD_enuSendData('E');
    LCD_enuSendData('L');
    LCD_enuSendData('C');
    LCD_enuSendData('O');
    LCD_enuSendData('M');
    LCD_enuSendData('E');
    LCD_enuSendData('!');

    _delay_ms(900);
    LCD_enuSendCommand(0x01);
    return DIO_OK;
}

ES_t Calc_Error() {
    LCD_enuSendData('E');
    LCD_enuSendData('R');
    LCD_enuSendData('R');
    LCD_enuSendData('O');
    LCD_enuSendData('R');
    return DIO_OK;
}

ES_t Calc_ErrorDivision() {
    LCD_enuSendData('D');
    LCD_enuSendData('I');
    LCD_enuSendData('V');
    LCD_enuSendData('I');
    LCD_enuSendData('S');
    LCD_enuSendData('I');
    LCD_enuSendData('O');
    LCD_enuSendData('N');
    LCD_enuSendData('E');
    LCD_enuSendData('R');
    LCD_enuSendData('R');
    LCD_enuSendData('O');
    LCD_enuSendData('R');
    return DIO_OK;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

ES_t Calc_InfixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initialize(&stack);

    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        if (ch >= '0' && ch <= '9') {
            while (infix[i] >= '0' && infix[i] <= '9') {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
        } else if (ch == '(') {
            push(&stack, ch);
            i++;
        } else if (ch == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top - 1] != '(') {
                pop(&stack, &ch);
                postfix[j++] = ch;
                postfix[j++] = ' ';
            }
            pop(&stack, &ch);
            i++;
        } else {
            while (!isEmpty(&stack) && precedence(stack.arr[stack.top - 1]) >= precedence(ch)) {
                pop(&stack, &ch);
                postfix[j++] = ch;
                postfix[j++] = ' ';
            }
            push(&stack, ch);
            i++;
        }
    }

    while (!isEmpty(&stack)) {
        pop(&stack, &ch);
        postfix[j++] = ch;
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
    return DIO_OK;
}

ES_t Calc_EvaluatePostfix(char *postfix, s32 *result) {
    Stack stack;
    initialize(&stack);

    int i = 0;
    char ch;
    s32 op1, op2, num;

    while (postfix[i] != '\0') {
        ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            num = 0;
            while (postfix[i] >= '0' && postfix[i] <= '9') {
                num = num * 10 + (postfix[i++] - '0');
            }
            push(&stack, num);
        } else if (ch == ' ') {
            i++;
        } else {
            pop(&stack, &op2);
            pop(&stack, &op1);

            switch (ch) {
                case '+':
                    push(&stack, op1 + op2);
                    break;
                case '-':
                    push(&stack, op1 - op2);
                    break;
                case '*':
                    push(&stack, op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        push(&stack, op1 / op2);
                    } else {
                        return DIO_NOK;
                    }
                    break;
                default:
                    return DIO_NOK;
            }
            i++;
        }
    }

    if (!isEmpty(&stack)) {
        pop(&stack, result);
        if (isEmpty(&stack)) {
            return DIO_OK;
        }
    }

    return DIO_NOK;
}

/*
 * Calc.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef CALC_H_
#define CALC_H_




ES_t Calc_Start (void);
//ES_t Calculation (s16 Num1 , u8  operation,  s16 Num2);

ES_t Calc_Error ();
ES_t Calc_ErrorDivision ();
int precedence(char op) ;
ES_t Calc_InfixToPostfix(const char *infix, char *postfix);
ES_t Calc_EvaluatePostfix(const char *postfix, s32 *result);

Calc_HandleInput();





#endif

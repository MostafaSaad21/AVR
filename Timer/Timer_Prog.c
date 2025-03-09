
#include"Stdh_types.h"
#include"ERROR.h"
#include "Intterupt.h"
#include"Timer_Private.h"
#include"Timer_Config.h"

static void (*TIMER0_Pfunc)(void*) = NULL;
static void *TIMER0_PvoidParameter = NULL;


static u32 TIMER0_Num_OVF = 0;
static u32 TIMER0_Preload = 0;




ES_t TIMER0_init(void) {
    ES_t local_errorstate = ES_OK;

#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_MODE_NORMAL

    TCCR0 &= ~(1 << WGM00);
    TCCR0 &= ~(1 << WGM01);

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_MODE_PWM_PHASE_CORRECT
    TCCR0 &= ~(1 <<WGM01);
       TCCR0 |= (1 << WGM00);


    #if TIMER0_COMPARE_OUTPUT_MODE == CLEAR_OC0_ON_COMPARE
        TCCR0 &= ~(1 << COM00);
        TCCR0 |= (1 << COM01);

    #elif TIMER0_COMPARE_OUTPUT_MODE == SET_OC0_ON_COMPARE
        TCCR0 |= (1 << COM00);
           TCCR0 &= ~(1 << COM01);

    #endif

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_MODE_CTC

    TCCR0 |= (1 << WGM00);
    TCCR0 &= ~(1 << WGM01);

    #if TIMER0_COMPARE_OUTPUT_MODE == TOGGLE_OC0_ON_COMPARE

        TCCR0 |= (1 << COM00);
        TCCR0 &= ~(1 << COM01);
    #elif TIMER0_COMPARE_OUTPUT_MODE == CLEAR_OC0_ON_COMPARE

        TCCR0 &= ~(1 << COM00);
        TCCR0 |= (1 << COM01);
    #elif TIMER0_COMPARE_OUTPUT_MODE == SET_OC0_ON_COMPARE

        TCCR0 |= (1 << COM00);
        TCCR0 |= (1 << COM01);

    #endif

#elif TIMER0_WAVEFORM_GENERATION_MODE == FAST_PWM

    TCCR0 |= (1 << WGM00);
    TCCR0 |= (1 << WGM01);
    #if TIMER0_COMPARE_OUTPUT_MODE == CLEAR_OC0_ON_COMPARE

        TCCR0 &= ~(1 << COM00);
        TCCR0 |= (1 << COM01);
    #elif TIMER0_COMPARE_OUTPUT_MODE == SET_OC0_ON_COMPARE

        TCCR0 |= (1 << COM00);
        TCCR0 |= (1 << COM01);

    #endif

#endif

 #if TIMER0_INTERRUPT_ENABLE == OCIE0

        TIMSK |= (1 << OCIE0);
#elif TIMER0_INTERRUPT_ENABLE == TOIE0

        TIMSK |= (1 << TOIE0);
#else

        TIMSK &= ~(1 << OCIE0);
    TIMSK &= ~(1 << TOIE0);
#endif


    #if TIMER0_PRESCALER == NO_CLOCK_SOURCE
    // No clock source (timer stopped)
    TCCR0 &= ~(1 << CS00);
    TCCR0 &= ~(1 << CS01);
    TCCR0 &= ~(1 << CS02);
#elif TIMER0_PRESCALER == NO_PRESCALING

    TCCR0 |= (1 << CS00);
    TCCR0 &= ~(1 << CS01);
    TCCR0 &= ~(1 << CS02);
#elif TIMER0_PRESCALER == PRESCALER_8

    TCCR0 &= ~(1 << CS00);
    TCCR0 |= (1 << CS01);
    TCCR0 &= ~(1 << CS02);
#elif TIMER0_PRESCALER == PRESCALER_64

    TCCR0 |= (1 << CS00);
    TCCR0 |= (1 << CS01);
    TCCR0 &= ~(1 << CS02);
#elif TIMER0_PRESCALER == PRESCALER_256

    TCCR0 &= ~(1 << CS00);
    TCCR0 &= ~(1 << CS01);
    TCCR0 |= (1 << CS02);
#elif TIMER0_PRESCALER == PRESCALER_1024
    // Prescaler 1024
    TCCR0 |= (1 << CS00);
    TCCR0 &= ~(1 << CS01);
    TCCR0 |= (1 << CS02);
#else

    local_errorstate = ES_NOK;
#endif


    return local_errorstate;
}

ES_t TIMER0_enuSetPreload(u8 Copy_u8PreloadValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	TCNT0 = Copy_u8PreloadValue;
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_t TIMER0_enuSetOutputCompareRegister(u8 Copy_u8OCRValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	OCR0 = Copy_u8OCRValue;
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}





ES_t TIMER0_enuSetASyncDelay(u32 Copy_u8Time, void (*func)(void), void *Copy_pvidParameter)
{
    ES_t local_errorstate = ES_NOK;
    if (func != NULL)
    {
        TIMER0_Pfunc = func;
        TIMER0_PvoidParameter = Copy_pvidParameter;
        local_errorstate = ES_OK;
    }
    else
    {
        local_errorstate = ES_NULLPOINTER;
    }
    f32 overflowTime = (256.0 * TIMER0_PRESCALER) / F_CPU;
    f32 NumOVF = Copy_u8Time / overflowTime;
    if (NumOVF - (u32)NumOVF != 0.0)
    {
        u32 NumOVF_int = (u32)NumOVF + 1;
        NumOVF = NumOVF - (u32)NumOVF;
        u8 preload = 256 * (1 - NumOVF);
        TIMER0_Num_OVF = NumOVF_int;
        TIMER0_Preload = preload;
        TCNT0 = preload;
    }
    else
    {
    	TIMER0_Num_OVF = (u32)NumOVF;
    }
    TIMSK |= (1 << TOIE0);
    return local_errorstate;
}
ES_t TIMER0_callBack(void (*func)(void), void *Copy_pvidParameter)
{

    ES_t local_errorstate = ES_NOK;
    if (func != NULL)
    {
        TIMER0_Pfunc = func;
        TIMER0_PvoidParameter = Copy_pvidParameter;
        local_errorstate = ES_OK;
    }
    else
    {
        local_errorstate = ES_NULLPOINTER;
    }
    return local_errorstate;
}


ES_t TIMER0_GeneratePWM(u8 Copy_u8DutyCycle)
{
    ES_t local_errorstate = ES_NOK;

#if TIMER0_WAVEFORM_GENERATION_MODE == FAST_PWM
#if TIMER0_COMPARE_OUTPUT_MODE == SET_OC0_ON_COMPARE
    local_u8CompareValue = (Copy_u8DutyCycle * 256) / 100;

#elif TIMER0_COMPARE_OUTPUT_MODE == CLEAR_OC0_ON_COMPARE
    local_u8CompareValue = 256 - ((Copy_u8DutyCycle * 256) / 100);
#endif

#elif TIMER0_WAVEFORM_GENERATION_MODE == PWM_PHASE_CORRECT
#if TIMER0_COMPARE_OUTPUT_MODE ==SET_OC0_ON_COMPARE
    local_u8CompareValue = (Copy_u8DutyCycle * 256) / 100;
#elif TIMER0_COMPARE_OUTPUT_MODE == CLEAR_OC0_ON_COMPARE
    local_u8CompareValue = 256 - ((Copy_u8DutyCycle * 256) / 100);
#endif
#endif


    local_errorstate = ES_OK;
    return local_errorstate;
}

ISR(VECT_TIMER0_OVF)
{
    if (TIMER0_Pfunc != NULL)
    {
         static u32 Countes = 0;
    	Countes++;
    	 if (Countes == TIMER0_Num_OVF)
         {
             TCNT0 = TIMER0_Preload;
             Countes   = 0;

}
    }
}


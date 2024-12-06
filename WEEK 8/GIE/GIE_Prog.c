#include"Stdh_types.h"
#include "ERROR.h"
#include "GIE_Private.h"

ES_t GIE_enuEnable(void)
{
	SREG |=(1<<7);
}

ES_t GIE_enuDisable(void)
{
		SREG &=~(1<<7);
}

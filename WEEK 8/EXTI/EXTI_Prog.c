/*
 * EXTI_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */
#include"Stdh_types.h"
#include"ERROR.h"
#include"EXTI_Private.h"
#include"EXTI_Config.h"

static void (*EXTI_CallBack[3]) (void) = { NULL } ;
ES_t  enu_init(EXTI_t *Copy_pstrEXTIConfig)
{
	ES_t local_enumError=ES_NOK;

     if(Copy_pstrEXTIConfig!=NULL)
{
    	u8 Local_u8Ittirator;
    	 for(Local_u8Ittirator=0; Local_u8Ittirator<3; Local_u8Ittirator++)
    	{
    		if(Copy_pstrEXTIConfig[Local_u8Ittirator].State==Enable)
    		{
              switch(Local_u8Ittirator)
              {

              case 0:
            	  GICR |=(1<<6);
              	MCUCR &= ~((1 << 0) | (1 << 1) );

       switch(Copy_pstrEXTIConfig[Local_u8Ittirator].Sense_Level)
       {
       case rising_edg:

   		MCUCR |= (1 << 0);
   		MCUCR |= (1 << 1);
			break;

       case falling_edge:

		MCUCR |= (1 << 1);
		break;

       case any_change:
   		MCUCR |= (1 << 0) ;

			break;
       case low_level:
    		MCUCR &= ~(1 << 0);
    		MCUCR &= ~(1 << 1);

			break;

       default:
      local_enumError=OUT_OF_RANGE;

       }
         break;

       case 1:
              	  GICR |=(1<<7);
                	MCUCR &= ~((1 << 2) | (1 << 3) );

         switch(Copy_pstrEXTIConfig[Local_u8Ittirator].Sense_Level)
         {
         case rising_edg:

     		MCUCR |= (1 << 2);
     		MCUCR |= (1 << 3);
  			break;

         case falling_edge:

  		MCUCR |= (1 << 3);
  		break;

         case any_change:
     		MCUCR |= (1 << 2) ;

  			break;
         case low_level:
      		MCUCR &= ~(1 << 2);
      		MCUCR &= ~(1 << 3);

  			break;

         default:
        local_enumError=OUT_OF_RANGE;

         }
           break;

         case 2:
                	  GICR |=(1<<5);
                	  MCUCSR &= ~(1 << 6);
           switch(Copy_pstrEXTIConfig[Local_u8Ittirator].Sense_Level)
           {
           case rising_edg:
                  MCUCSR |= (1 << 6);
                  break;

              case falling_edge:

                  MCUCSR &= ~(1 << 6);
                  break;


           default:
          local_enumError=OUT_OF_RANGE;

           }
             break;


                default:
                	return local_enumError;

              }

    		}

    	}
}
     else
     {
    	 local_enumError= ES_NULLPOINTER;
     }
     return local_enumError;
}

ES_t  enu_SenseLevel(u8 Copy_ID, u8 Copy_SenseLevel)
{
	ES_t local_enumError=ES_NOK;

	if(Copy_ID<3)
	{

	 if(Copy_ID==0)
	   {
		 MCUCR &= ~((1 << 0) | (1 << 1) );

		switch(Copy_SenseLevel)
		   {
		 case rising_edg:

		   		MCUCR |= (1 << 0);
		   		MCUCR |= (1 << 1);
					break;

		       case falling_edge:

				MCUCR |= (1 << 1);
				break;

		       case any_change:
		   		MCUCR |= (1 << 0) ;

					break;
		       case low_level:
		    		MCUCR &= ~(1 << 0);
		    		MCUCR &= ~(1 << 1);

					break;

		       default:
		      local_enumError=OUT_OF_RANGE;
		    }
	   }
	 if(Copy_ID==1)
	 {
	 MCUCR &= ~((1 << 2) | (1 << 3) );

	          switch(Copy_SenseLevel)
	          {
	          case rising_edg:

	      		MCUCR |= (1 << 2);
	      		MCUCR |= (1 << 3);
	   			break;

	          case falling_edge:

	   		MCUCR |= (1 << 3);
	   		break;

	          case any_change:
	      		MCUCR |= (1 << 2) ;

	   			break;
	          case low_level:
	       		MCUCR &= ~(1 << 2);
	       		MCUCR &= ~(1 << 3);

	   			break;

	          default:
	         local_enumError=OUT_OF_RANGE;

	          }
	}


	 if(Copy_ID==2)
	 	 	   {
		 MCUCSR &= ~(1 << 6);
		           switch(Copy_SenseLevel)
		           {
		           case rising_edg:
		                  MCUCSR |= (1 << 6);
		                  break;

		              case falling_edge:

		                  MCUCSR &= ~(1 << 6);
		                  break;


		           default:
		          local_enumError=OUT_OF_RANGE;

		           }
	 	 	   }
}
	else
	{
		local_enumError=OUT_OF_RANGE;
	}


return local_enumError;
}
ES_t enu_Enable(u8 Copy_ID)
{
	ES_t local_enumError=ES_NOK;
	if(Copy_ID <3)
	{
	switch(Copy_ID)
	   {
		case 0:
			GICR |=(1<<6);
			break;
		case 1:
					GICR |=(1<<7);
					break;
		case 2:
					GICR |=(1<<5);
					break;
		default:
			local_enumError=OUT_OF_RANGE;
	     }
	}
	else
	{
		local_enumError=OUT_OF_RANGE;

	}

	return local_enumError;
}
ES_t enu_Disable(u8 Copy_ID)
{
	ES_t local_enumError=ES_NOK;
if(Copy_ID <3)
{
	switch(Copy_ID)
		{
			case 0:
				GICR &=~(1<<6);
				break;
			case 1:
						GICR &=~(1<<7);
						break;
			case 2:
						GICR &=~(1<<5);
						break;
			default:
				local_enumError=OUT_OF_RANGE;
		}
}
     else
         {
	      local_enumError=OUT_OF_RANGE;
         }

return local_enumError;

}

ES_t enu_CallBack(u8 Copy_ID,void (*Copy_pvoidCallBack)(void))
{
	ES_t local_enumError=ES_NOK;
	if(Copy_pvoidCallBack!= NULL)
	{
		if(Copy_ID<3)
		{
			EXTI_CallBack[Copy_ID] = Copy_pvoidCallBack ;


		}
		else
		{
			local_enumError=OUT_OF_RANGE;
		}
	}
	else
			{
				local_enumError=OUT_OF_RANGE;
			}

	return local_enumError;
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( EXTI_CallBack[0] != NULL ){

		EXTI_CallBack[0]();

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if( EXTI_CallBack[1] != NULL ){

		EXTI_CallBack[1]();

	}

}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{

	if( EXTI_CallBack[2] != NULL ){

		EXTI_CallBack[2]();

	}

}

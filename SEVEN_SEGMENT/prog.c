#include "Stdh_types.h"
#include "private.h"
#include "ERROR.h"
#include "config.h"


ES_t DIO_init(void)
 {
	ES_t local_enumError=DIO_NOK;

	    DDRA= CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR);
	    DDRB= CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR);
	    DDRC= CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR);
	    DDRD= CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR);

	    PORTA= CONC(PORTA_PIN7_VAL,PORTA_PIN6_VAL,PORTA_PIN5_VAL,PORTA_PIN4_VAL,PORTA_PIN3_VAL,PORTA_PIN2_VAL,PORTA_PIN1_VAL,PORTA_PIN0_VAL);
		PORTB= CONC(PORTB_PIN7_VAL,PORTB_PIN6_VAL,PORTB_PIN5_VAL,PORTB_PIN4_VAL,PORTB_PIN3_VAL,PORTB_PIN2_VAL,PORTB_PIN1_VAL,PORTB_PIN0_VAL);
		PORTC= CONC(PORTC_PIN7_VAL,PORTC_PIN6_VAL,PORTC_PIN5_VAL,PORTC_PIN4_VAL,PORTC_PIN3_VAL,PORTC_PIN2_VAL,PORTC_PIN1_VAL,PORTC_PIN0_VAL);
		PORTD= CONC(PORTD_PIN7_VAL,PORTD_PIN6_VAL,PORTD_PIN5_VAL,PORTD_PIN4_VAL,PORTD_PIN3_VAL,PORTD_PIN2_VAL,PORTD_PIN1_VAL,PORTD_PIN0_VAL);
		local_enumError=DIO_OK;


	 return local_enumError;

 }

ES_t Setport_Direction(u8 copy_u8_PortId,u8 copy_u8_value)
{
		ES_t local_enumError=DIO_NOK;

     if(copy_u8_PortId<=DIO_PORTD)
     {
    	 switch(copy_u8_PortId)
    	 {
    	 case DIO_PORTA:
    		 DDRA=copy_u8_value;
    		 break;
    	 case DIO_PORTB:
    		 DDRB=copy_u8_value;

    	    		 break;
    	 case DIO_PORTC:
    		 DDRC=copy_u8_value;

    	    		 break;
    	 case DIO_PORTD:
    		 DDRD=copy_u8_value;

    	    		 break;
    	 }

 		ES_t local_enumError=DIO_OK;


     }

     else
     {
    		ES_t local_enumError=OUT_OF_RANGE;

     }




		 return local_enumError;

}
ES_t Setport_value(u8 copy_u8_PortId,u8 copy_u8_value)
{

			ES_t local_enumError=DIO_NOK;

	     if(copy_u8_PortId<=DIO_PORTD)
	     {
	    	 switch(copy_u8_PortId)
	    	 {
	    	 case DIO_PORTA:
	    		 PORTA=copy_u8_value;
	    		 break;
	    	 case DIO_PORTB:
	    		 PORTB=copy_u8_value;

	    	    		 break;
	    	 case DIO_PORTC:
	    		 PORTC=copy_u8_value;

	    	    		 break;
	    	 case DIO_PORTD:
	    		PORTD=copy_u8_value;

	    	    		 break;
	    	 }

	 		ES_t local_enumError=DIO_OK;


	     }

	     else
	     {
	    		ES_t local_enumError=OUT_OF_RANGE;

	     }




			 return local_enumError;


}
        ES_t TogglePort(u8 copy_u8_PortId)

		{
					ES_t local_enumError=DIO_NOK;

			     if(copy_u8_PortId<=DIO_PORTD)
			     {
			    	 switch(copy_u8_PortId)
			    	 {
			    	 case DIO_PORTA:
			    		 PORTA=~PORTA;
			    		 break;

			    	 case DIO_PORTB:
			    		 PORTB=~PORTB;

			    	    		 break;
			    	 case DIO_PORTC:
			    		 PORTC=~PORTC;

			    	    		 break;
			    	 case DIO_PORTD:
			    		PORTD=~PORTD;

			    	    		 break;
			    	 }

			 		ES_t local_enumError=DIO_OK;


			     }

			     else
			     {
			    		ES_t local_enumError=OUT_OF_RANGE;

			     }
			 return local_enumError;

	}

	ES_t GetPort(u8 copy_u8_PortId,u8 *copy_pu8_value)
{
		ES_t local_enumError=DIO_NOK;
if(copy_pu8_value!=NULL)
{
	   if(copy_u8_PortId<=DIO_PORTD)
	   {
		   switch(copy_u8_PortId)
		   {
		   case DIO_PORTA:
			   *copy_pu8_value=PINA;
			   break;

		       case DIO_PORTB:
		  			   *copy_pu8_value=PINB;
		  			  break;

		  			   case DIO_PORTC:
		  				   *copy_pu8_value=PINC;
		  				   break;

		  				   case DIO_PORTD:
		  					   *copy_pu8_value=PIND;
		  					   break;

		   }

			ES_t local_enumError=DIO_OK;

	   }
	   else
	   {
			ES_t local_enumError=OUT_OF_RANGE;

	   }

}
else
{
	ES_t local_enumError=DIO_NULLPOINTER;
}

			 return local_enumError;

}

	ES_t Setpin_Direction(u8 copy_u8_PortId,u8 copy_u8_PIN_Id,u8 copy_u8_value)
{
		ES_t local_enumError=DIO_NOK;
		if(copy_u8_PortId<=DIO_PORTD &&copy_u8_PIN_Id<=DIO_PIN7&&copy_u8_value<=OUTPUT)
		{
			switch(copy_u8_PortId)
					   {
		 case DIO_PORTA:
			 DDRA &=~(1<<copy_u8_PIN_Id);
			 DDRA |=(copy_u8_value<<copy_u8_PIN_Id);
	 	                break;
	     case DIO_PORTB:
	    	  DDRB &=~(1<<copy_u8_PIN_Id);
	    				 DDRB |=(copy_u8_value<<copy_u8_PIN_Id);
	  	            break;
	     case DIO_PORTC:
	    	 DDRC &=~(1<<copy_u8_PIN_Id);
	    				 DDRC |=(copy_u8_value<<copy_u8_PIN_Id);
	 	 			   break;

	    case DIO_PORTD:
	    	 DDRD &=~(1<<copy_u8_PIN_Id);
	    				 DDRD |=(copy_u8_value<<copy_u8_PIN_Id);
					   break;

					   }

			ES_t local_enumError=DIO_OK;

		}
		else
		{
			ES_t local_enumError=OUT_OF_RANGE;

		}


			 return local_enumError;

}
	ES_t Setpin_value(u8 copy_u8_PortId,u8 copy_u8_PIN_Id,u8 copy_u8_value)
{
		ES_t local_enumError=DIO_NOK;
					if(copy_u8_PortId<=DIO_PORTD &&copy_u8_PIN_Id<=DIO_PIN7&&copy_u8_value<=OUTPUT)
					{
						switch(copy_u8_PortId)
								   {
					 case DIO_PORTA:
						 PORTA &=~(1<<copy_u8_PIN_Id);
						 PORTA |=(copy_u8_value<<copy_u8_PIN_Id);
				 	                break;
				     case DIO_PORTB:
				    	 PORTB &=~(1<<copy_u8_PIN_Id);
				    	 PORTB |=(copy_u8_value<<copy_u8_PIN_Id);
				  	            break;
				     case DIO_PORTC:
				    	 PORTC &=~(1<<copy_u8_PIN_Id);
				    	 PORTC |=(copy_u8_value<<copy_u8_PIN_Id);
				 	 			   break;

				    case DIO_PORTD:
				    	PORTD &=~(1<<copy_u8_PIN_Id);
				    	PORTD |=(copy_u8_value<<copy_u8_PIN_Id);
								   break;

								   }

						ES_t local_enumError=DIO_OK;

					}
					else
					{
						ES_t local_enumError=OUT_OF_RANGE;

					}


						 return local_enumError;

			}

	ES_t TogglePIN(u8 copy_u8_PortId,u8  copy_u8_PIN_Id)
				{
					ES_t local_enumError=DIO_NOK;

					if(copy_u8_PortId<=DIO_PORTD &&copy_u8_PIN_Id<=DIO_PIN7)
					{

						 switch(copy_u8_PortId)
		   	 {
					  case DIO_PORTA:
					 	 PORTA ^=(1<<copy_u8_PIN_Id);
					 	 break;

					  case DIO_PORTB:
					 	 PORTB ^=(1<<copy_u8_PIN_Id);

					     		 break;
					  case DIO_PORTC:
					 	 PORTC ^=(1<<copy_u8_PIN_Id);

					     		 break;
					  case DIO_PORTD:
					 	PORTD ^=(1<<copy_u8_PIN_Id);

					     		 break;
	     }

						ES_t local_enumError=DIO_OK;
					}
					else
					{
				ES_t local_enumError=OUT_OF_RANGE;

				}

					return local_enumError;

}
	ES_t GetPin(u8 copy_u8_PortId,u8 copy_u8_PIN_Id,u8 *copy_pu8_value)
{
		ES_t local_enumError=DIO_NOK;
          if(copy_pu8_value!=NULL)
 {
        	  if(copy_u8_PortId<=DIO_PORTD&&copy_u8_PIN_Id<=DIO_PIN7)
        	  {
        			 switch(copy_u8_PortId)
        			   	 {
        						  case DIO_PORTA:
        							  *copy_pu8_value=((PINA>>copy_u8_PIN_Id)&1);
        						 	 break;

        						  case DIO_PORTB:
        							  *copy_pu8_value=((PINB>>copy_u8_PIN_Id)&1);

        						     		 break;
        						  case DIO_PORTC:
        							  *copy_pu8_value=((PINC>>copy_u8_PIN_Id)&1);

        						     		 break;
        						  case DIO_PORTD:
        							  *copy_pu8_value=((PIND>>copy_u8_PIN_Id)&1);

        						     		 break;
        		     }


					ES_t local_enumError=DIO_OK;
        	  }
 else
        	  {
    	ES_t local_enumError=OUT_OF_RANGE;


        	  				}

}

else
					{
				ES_t local_enumError=DIO_NULLPOINTER;

				}


					 return local_enumError;

}


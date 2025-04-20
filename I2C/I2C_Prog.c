/*
 * I2C_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#include "Stdh_types.h"
#include "ERROR.h"

#include "I2C_Private.h"
#include "I2c_Config.h"




ES_t I2C_InitMaster(u8 MasterAddress)
{

	ES_t LocalErrorState=ES_NOK;

	TWBR = (u8)(((F_CPU/SCL_Freq)-16)/(2*PrescalerValue));


#if PrescalerValue ==PrescalerValue_1


	TWSR &=~(1<<TWPS1);
	TWSR &=~(1<<TWPS0);

#elif PrescalerValue ==PrescalerValue_4

	TWSR &=~(1<<TWPS1);
	TWSR |=(1<<TWPS0);
#elif	PrescalerValue ==PrescalerValue_16

	TWSR |=(1<<TWPS1);
	TWSR &=~(1<<TWPS0);

#elif PrescalerValue ==PrescalerValue_64

	TWSR |=(1<<TWPS1);
	TWSR |=(1<<TWPS0);
#endif

#if ACK== Enable
	TWCR |= (1<<TWEA);

#elif  ACK== Disable
	TWCR &=~ (1<<TWEA);


#endif

	if(MasterAddress != 0)
		{
			TWAR = (MasterAddress << 1);
	#if GeneralCall == Enable
			TWAR |= (1<<TWGCE);
	#else
			TWAR &= ~(1<<TWGCE);
	#endif
		}

	TWCR |= (1<<TWEN);

return LocalErrorState;
}
ES_t I2C_InitSlave(u8 SlaveAddress)
{
	ES_t LocalErrorState = ES_NOK;

	// Set  Address
	TWAR = (SlaveAddress << 1);

#if GeneralCall == Enable
	TWAR |= (1<<TWGCE);
#else
	TWAR &= ~(1<<TWGCE);
#endif

#if ACK == Enable
	TWCR |= (1<<TWEA);
#else
	TWCR &= ~(1<<TWEA);
#endif

	TWCR |= (1<<TWEN);

	return LocalErrorState;
}

ES_t I2C_StartCondition()
{
	ES_t LocalErrorState=ES_NOK;

//Start Condition
	TWCR |=(1<<TWSTA);

//clear falg
	TWCR|= (1<<TWINT);

	 while (!(TWCR & (1 << TWINT))); //Untill The Flag Is Set

	 if((TWSR &0xF8)==0x08)
	 {
		 LocalErrorState=ES_OK;
	 }


	return LocalErrorState;

}
ES_t I2C_RepeatStarCondition()
{
	ES_t LocalErrorState=ES_NOK;

	//Start Condition
		TWCR |=(1<<TWSTA);

	//clear falg
		TWCR|= (1<<TWINT);

		 while (!(TWCR & (1 << TWINT))); //Untill The Flag Is Set

		 if((TWSR &0xF8)==0x10)
		 {
			 LocalErrorState=ES_OK;
		 }


		return LocalErrorState;
}
ES_t I2C_StopCondition()
{
	ES_t LocalErrorState=ES_NOK;

	//Stop condition
	TWCR |=(1<<TWSTO);

	//clear falg
	TWCR|= (1<<TWINT);


return LocalErrorState;
}

ES_t I2C_SendSlaveAddress(u8 SlaveAddress, u8 Read_Write)
{
	ES_t LocalErrorState=ES_NOK;

		TWDR = (( SlaveAddress<<1)|Read_Write) ;

       TWCR &=~(1<<TWSTA);

      TWCR|= (1<<TWINT);
   	 while (!(TWCR & (1 << TWINT)));

		if((TWSR & 0xF8) == 0x18 && Read_Write==0  )
		{

			LocalErrorState = ES_OK;
		}

		else if((TWSR & 0xF8)==0x40 && Read_Write==1)
		{
			LocalErrorState = ES_OK;
		}


return LocalErrorState;
}


ES_t I2C_MasterSendData(u8 SendData)
{

	ES_t LocalErrorState=ES_NOK;

   TWDR=SendData;


   	TWCR|= (1<<TWINT);

   	 while (!(TWCR & (1 << TWINT)));

   	 if((TWSR &0xF8)==0x28)
   			 {
   				 LocalErrorState=ES_OK;
   			 }
return LocalErrorState;
}

ES_t I2C_MasterReaceiveData(u8 *ReaceiveData)
{
	ES_t LocalErrorState=ES_NOK;

	*ReaceiveData=TWDR;


	   	TWCR|= (1<<TWINT);

	   	 while (!(TWCR & (1 << TWINT)));

	   	 if((TWSR & 0xF8)==0x50)
	   			 {
	   				 LocalErrorState=ES_OK;
	   			 }
	return LocalErrorState;


}





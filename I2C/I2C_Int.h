/*
 * I2C_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_


ES_t I2C_InitMaster(u8 MasterAddress)
ES_t I2C_InitSlave(u8 SlaveAddress);

ES_t I2C_StartCondition();
ES_t I2C_RepeatStarCondition();
ES_t I2C_StopCondition();

ES_t I2C_SendSlaveAddress(u8 SlaveAddress, u8 Read_Write)
ES_t I2C_MasterSendData(u8 SendData);
ES_t I2C_MasterReaceiveData(u8 *ReaceiveData);







#endif /* I2C_INT_H_ */

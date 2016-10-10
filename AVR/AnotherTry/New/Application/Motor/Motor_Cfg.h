/*
 * Motor_Cfg.h
 *
 * Created: 20.09.2016 22:08:24
 *  Author: AP
 */ 


#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_


#define MOTOR_NUMBER_OF_MOTOR                ((uint8_t)MOTOR_MOTOR_QUANTITY)

typedef enum
{
	MOTOR_MOTOR_01       = 0x00,
	MOTOR_MOTOR_02             ,
	MOTOR_MOTOR_QUANTITY       ,
	
}Motor_Names_t;



#endif /* MOTOR_CFG_H_ */
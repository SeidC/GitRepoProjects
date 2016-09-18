/*
 * Motor.h
 *
 * Created: 18.09.2016 15:35:49
 *  Author: AP02
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "TLE5206.h"
#include "Adc.h"

#define MOTOR_NUMBER_OF_MOTOR                ((uint8_t)MOTOR_MOTOR_QUANTITY)

typedef enum 
{
   MOTOR_MOTOR_01       = 0x00,
   MOTOR_MOTOR_02             ,
   MOTOR_MOTOR_QUANTITY       ,                   
   
}Motor_Names_t;

typedef struct 
{
   Adc_Channel_t     motorAdcChannel;
   TLE5206_Device_t  motorBridge;
}Motor_Config_t;





#endif /* MOTOR_H_ */
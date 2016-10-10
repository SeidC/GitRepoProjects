/*
 * TLE5206.h
 *
 * Created: 15.09.2016 21:33:17
 *  Author: AP02
 */ 


#ifndef TLE5206_H_
#define TLE5206_H_
#include "Io.h"
#include "Pwm.h"

#define TLE5206_IO_INPUT_1                            0u
#define TLE5206_IO_INPUT_2                            1u

#define TLE5206_DEFAULT_LEFT_DIRECTION                TLE5206_IO_INPUT_2

#define TLE5206_NUMBER_OF_DEVICES                     ((uint8_t)TLE5206_DEVICE_QUANTITY)


typedef enum 
{
   TLE5206_BRIDGE_00             = 0x00,
   TLE5206_BRIDGE_01                   ,
   TLE5206_DEVICE_QUANTITY
}TLE5206_Device_t;

typedef struct 
{
   Io_Config_t   input1;
   Io_Config_t   input2;
   Io_Config_t   errorFlag;
   Io_Config_t	 enable;
   Pwm_Channel_t channel;
   Pwm_Config_t channelConfig;
}TLE5206_IoConfig_t; 


typedef enum 
{
	TLE5206_INPUT_01			= 0x00,
	TLE5206_INPUT_02			= 0x01,
	TLE5206_EMERGENCY_STOP		= 0x02,
	TLE5206_NORMAL_STOP			= 0x03,	
	
}TLE5206_Input_t;


void TLE5206_Init(void);
void TLE5206_SetInput(TLE5206_Device_t device, TLE5206_Input_t input);
void TLE5206_Disable(TLE5206_Device_t device);
void TLE5206_Enable(TLE5206_Device_t device);
void TLE5206_SetDutyCycle(TLE5206_Device_t device, uint8_t dutyCycle);
void TLE5206_ActivatePwm(TLE5206_Device_t device);
void TLE5206_DeactivatePwm(TLE5206_Device_t device);

#endif /* TLE5206_H_ */
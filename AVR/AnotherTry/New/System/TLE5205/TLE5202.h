/*
 * TLE5202.h
 *
 * Created: 15.09.2016 21:33:17
 *  Author: AP02
 */ 


#ifndef TLE5202_H_
#define TLE5202_H_
#include "Io.h"
#include "Pwm.h"

#define TLE5205_IO_INPUT_1                            0u
#define TLE5205_IO_INPUT_2                            1u

#define TLE5202_DEFAULT_LEFT_DIRECTION                TLE5205_IO_INPUT_2

#define TLE5205_NUMBER_OF_DEVICES                     ((uint8_t)TLE5202_DEVICE_QUANTITY)


typedef enum 
{
   TLE5202_DEVICE_00             = 0x00,
   TLE5202_DEVICE_01                   ,
   TLE5202_DEVICE_QUANTITY
}TLE5202_Device_t;

typedef struct 
{
   Io_Config_t   input1;
   Io_Config_t   input2;
   Io_Config_t   errorFlag;
   Io_Config_t	 enable;
   Pwm_Channel_t channel;
   Pwm_Config_t channelConfig;
}TLE5202_IoConfig_t; 


typedef enum 
{
	TLE5205_LEFT_DIRECTION		= 0x00,
	TLE5205_RIGTH_DIRECTION		= 0x01,
   TLE5205_EMERGENCY_STOP     = 0x02,
   TLE5205_STOP               = 0x03,
	
}TLE5202_Direction_t;


void TLE5202_Init(void);
Io_Config_t* TLE5205_GetIoByDirection(TLE5202_Device_t device, TLE5202_Direction_t direction);
void TLE5205_SetDirection(TLE5202_Device_t device, TLE5202_Direction_t direction);
void TLE5205_Disable(TLE5202_Device_t device);
void TLE5205_Enable(TLE5202_Device_t device);
void TLE5205_SetDutyCycle(TLE5202_Device_t device, uint8_t dutyCycle);

#endif /* TLE5202_H_ */
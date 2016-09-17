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

#define TLE5205_NUMBER_OF_DEVICES                  ((uint8_t)TLE5202_DEVICE_QUANTITY)


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
   Pwm_Channel_t channel;
   
}TLE5202_IoConfig_t; 


void TLE5202_Init(void);

#endif /* TLE5202_H_ */
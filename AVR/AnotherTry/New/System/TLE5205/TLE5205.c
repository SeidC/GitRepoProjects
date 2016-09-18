/*
 * TLE5205.c
 *
 * Created: 15.09.2016 21:32:58
 *  Author: AP02
 */ 

#include "TLE5202.h"

 #define TLE5205_GetDevice(device)                          \
         ((TLE5202_IoConfig_t*)&TLE5202_config[device])

TLE5202_IoConfig_t TLE5202_config[TLE5205_NUMBER_OF_DEVICES] = 
            {
               {
                  .input1			= {IO_PORT_C,IO_PIN_0},
                  .input2			= {IO_PORT_C,IO_PIN_1},
				      .enable			= {IO_PORT_C,IO_PIN_2},
                  .errorFlag		= {IO_PORT_D,IO_PIN_2},
                  .channelConfig	= {PWM_PHASE_CORRECT,PWM_NON_INVERTED,PWM_PRESCALER_0},
				      .channel			= PWM_CHANNEL_0,				  
               },
               
               {
                  .input1			= {IO_PORT_C,IO_PIN_6},
                  .input2			= {IO_PORT_C,IO_PIN_7},
				      .enable			= {IO_PORT_C,IO_PIN_5},
                  .errorFlag		= {IO_PORT_D,IO_PIN_3},
                  .channelConfig	= {PWM_PHASE_CORRECT,PWM_NON_INVERTED,PWM_PRESCALER_0},
				      .channel			= PWM_CHANNEL_2
               },               
            };            
            
            
            
void TLE5202_Init(void)
{
   uint8_t i = 0;
   Io_Port_t port1,port2,port3,port4;
   Io_Pin_t  pin1,pin2,pin3,pin4;
   Pwm_Channel_t channel;
   
   for(i = 0; i < TLE5205_NUMBER_OF_DEVICES; i++)
   {
		port1 = TLE5202_config[i].input1.port;
		pin1  = TLE5202_config[i].input1.pin;
		
		port2 = TLE5202_config[i].input2.port;
		pin2  = TLE5202_config[i].input2.pin;
		
		port3 = TLE5202_config[i].errorFlag.port;
		pin3  = TLE5202_config[i].errorFlag.pin;
		
		port4 = TLE5202_config[i].enable.port;
		pin4  = TLE5202_config[i].enable.pin;
		
		channel = TLE5202_config[i].channel;
		
		Io_Configure(port1,pin1,IO_OUTPUT);
		Io_Configure(port2,pin2,IO_OUTPUT);
		Io_Configure(port3,pin3,IO_INPUT);
		Io_Configure(port4,pin4,IO_OUTPUT);
		
		Io_SetPinStatus(port1,pin1,LOW);
		Io_SetPinStatus(port2,pin2,LOW);
		Io_SetPinStatus(port3,pin3,HIGH);
		
		Pwm_Init(channel,&TLE5202_config[i].channelConfig);		
		Pwm_SetDutyCycle(channel,0);
   }
     
   return;
}

void TLE5205_Enable(TLE5202_Device_t device)
{
	Io_Port_t port;
	Io_Pin_t pin;
	port = TLE5202_config[device].enable.port;
	pin  = TLE5202_config[device].enable.pin;
	
	Io_SetPinStatus(port,pin,HIGH);
	
}

void TLE5205_Disable(TLE5202_Device_t device)
{
	Io_Port_t port;
	Io_Pin_t pin;
	port = TLE5202_config[device].enable.port;
	pin  = TLE5202_config[device].enable.pin;
	
	Io_SetPinStatus(port,pin,LOW);
}


void TLE5205_SetDirection(TLE5202_Device_t device, TLE5202_Direction_t direction)
{
   Io_Config_t *left, *right;
   
   left  = TLE5205_GetIoByDirection(device,TLE5205_LEFT_DIRECTION);
   right = TLE5205_GetIoByDirection(device,TLE5205_RIGTH_DIRECTION);
   
   if(direction == TLE5205_LEFT_DIRECTION)
   {
      Io_SetPinStatus(left->port,left->pin,HIGH);
      Io_SetPinStatus(right->port,right->pin,LOW);
   }
   else if(direction == TLE5205_RIGTH_DIRECTION)
   {
      Io_SetPinStatus(left->port,left->pin,LOW);
      Io_SetPinStatus(right->port,right->pin,HIGH);
   }
   else if(direction == TLE5205_EMERGENCY_STOP)
   {
      Io_SetPinStatus(left->port,left->pin,HIGH);
      Io_SetPinStatus(right->port,right->pin,HIGH);   
   }
   else if(direction == TLE5205_STOP)
   {
      Io_SetPinStatus(left->port,left->pin,LOW);
      Io_SetPinStatus(right->port,right->pin,LOW);
   }
   else
   {
      /*--- Do Nothing ---*/
   }
   return;
}


Io_Config_t* TLE5205_GetIoByDirection(TLE5202_Device_t device, TLE5202_Direction_t direction)
{
   Io_Config_t *cfg; 
   if(TLE5202_DEFAULT_LEFT_DIRECTION == TLE5205_IO_INPUT_1)
   {
      if(direction == TLE5205_LEFT_DIRECTION)
      {
         cfg = &(TLE5205_GetDevice(device).input1);
      }  
      else
      {
         cfg = &(TLE5205_GetDevice(device).input2);
      } 
   }
   else if(TLE5202_DEFAULT_LEFT_DIRECTION == TLE5205_IO_INPUT_2)
   {
     if(direction == TLE5205_LEFT_DIRECTION)
     {
        cfg = &(TLE5205_GetDevice(device).input2);
     }
     else
     {
        cfg = &(TLE5205_GetDevice(device).input1);
     } 
   }
   return cfg;
}


void TLE5205_SetDutyCycle(TLE5202_Device_t device, uint8_t dutyCycle)
{
   TLE5202_IoConfig_t *cfg; 
   cfg = TLE5205_GetDevice(device);
   Pwm_SetDutyCycle(cfg->channel,dutyCycle);
}
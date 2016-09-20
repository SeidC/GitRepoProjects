/*
 * TLE5206.c
 *
 * Created: 15.09.2016 21:32:58
 *  Author: AP02
 */ 

#include "TLE5206.h"

 #define TLE5206_GetDevice(device)                          \
         ((TLE5206_IoConfig_t*)&TLE5206_config[device])

TLE5206_IoConfig_t TLE5206_config[TLE5206_NUMBER_OF_DEVICES] = 
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
            
            
            
void TLE5206_Init(void)
{
   uint8_t i = 0;
   Io_Port_t port1,port2,port3,port4;
   Io_Pin_t  pin1,pin2,pin3,pin4;
   Pwm_Channel_t channel;
   
   for(i = 0; i < TLE5206_NUMBER_OF_DEVICES; i++)
   {
		port1 = TLE5206_config[i].input1.port;
		pin1  = TLE5206_config[i].input1.pin;
		
		port2 = TLE5206_config[i].input2.port;
		pin2  = TLE5206_config[i].input2.pin;
		
		port3 = TLE5206_config[i].errorFlag.port;
		pin3  = TLE5206_config[i].errorFlag.pin;
		
		port4 = TLE5206_config[i].enable.port;
		pin4  = TLE5206_config[i].enable.pin;
		
		channel = TLE5206_config[i].channel;
		
		Io_Configure(port1,pin1,IO_OUTPUT);
		Io_Configure(port2,pin2,IO_OUTPUT);
		Io_Configure(port3,pin3,IO_INPUT);
		Io_Configure(port4,pin4,IO_OUTPUT);
		
		Io_SetPinStatus(port1,pin1,LOW);
		Io_SetPinStatus(port2,pin2,LOW);
		Io_SetPinStatus(port3,pin3,HIGH);
		
		Pwm_Init(channel,&TLE5206_config[i].channelConfig);		
		Pwm_SetDutyCycle(channel,0);
   }
     
   return;
}

void TLE5206_Enable(TLE5206_Device_t device)
{
	Io_Port_t port;
	Io_Pin_t pin;
	port = TLE5206_config[device].enable.port;
	pin  = TLE5206_config[device].enable.pin;
	
	Io_SetPinStatus(port,pin,HIGH);
	
}

void TLE5206_Disable(TLE5206_Device_t device)
{
	Io_Port_t port;
	Io_Pin_t pin;
	port = TLE5206_config[device].enable.port;
	pin  = TLE5206_config[device].enable.pin;
	
	Io_SetPinStatus(port,pin,LOW);
}


void TLE5206_SetInput(TLE5206_Device_t device, TLE5206_Input_t input)
{
	TLE5206_IoConfig_t *config =  TLE5206_GetDevice(device);
	if (input == TLE5206_INPUT_01)
	{
		Io_SetPinStatus(config->input1.port,config->input1.pin,HIGH);
		Io_SetPinStatus(config->input2.port,config->input2.pin,LOW);
	}
	else if (input == TLE5206_INPUT_02)
	{
		Io_SetPinStatus(config->input1.port,config->input1.pin,LOW);
		Io_SetPinStatus(config->input2.port,config->input2.pin,HIGH);
	}
	else if (input == TLE5206_EMERGENCY_STOP)
	{
		Io_SetPinStatus(config->input1.port,config->input1.pin,HIGH);
		Io_SetPinStatus(config->input2.port,config->input2.pin,HIGH);
	}
	else 
	{
		Io_SetPinStatus(config->input1.port,config->input1.pin,LOW);
		Io_SetPinStatus(config->input2.port,config->input2.pin,LOW);
	}
   return;
}


void TLE5206_SetDutyCycle(TLE5206_Device_t device, uint8_t dutyCycle)
{
   TLE5206_IoConfig_t *cfg; 
   cfg = TLE5206_GetDevice(device);
   Pwm_SetDutyCycle(cfg->channel,dutyCycle);
}


/*
 * Pwm.h
 *
 * Created: 08.09.2016 19:52:56
 *  Author: AP
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "CommonTypes.h"

typedef enum
{
   PWM_CHANNEL_0              = 0x00u,
   PWM_CHANNEL_2           
}Pwm_Channel_t;

typedef enum 
{
   PWM_PRESCALER_0            = 0,
   PWM_PRESCALER_8            = 1,
   PWM_PRESCALER_64           = 2,
   PWM_PRESCALER_256          = 3,
   PWM_PRESCALER_1024         = 4,  
   
}Pwm_Prescaler_t;

typedef enum
{
   PWM_STOP    = 0x00,
   PWM_START         ,
   
}Pwm_Status_t;

typedef enum
{
   PWM_PHASE_CORRECT    = 0x01u,
   PWM_FAST_PWM         = 0x03u
   
}Pwm_Mode_t;


typedef enum 
{
   PWM_PIN_NOT_USED  = 0x00,
   PWM_RESERVED            ,
   PWM_INVERTED            ,
   PWM_NON_INVERTED        ,
   
}Pwm_OutputPin_t;


typedef struct
{
	Pwm_Mode_t mode;
	Pwm_OutputPin_t outputPin;
	Pwm_Prescaler_t prescaler;
	
}Pwm_Config_t;



void Pwm_TogglePwm(Pwm_Channel_t channel, Pwm_Status_t status);

void Pwm_Stop(Pwm_Channel_t channel);

void Pwm_Start(Pwm_Channel_t channel);

void Pwm_SetPwmFrequenze(Pwm_Channel_t channel, Pwm_Prescaler_t prescaler);

void Pwm_ConfigureOutputPin(Pwm_Channel_t channel, Pwm_OutputPin_t pinCfg);

void Pwm_SetPwmMode(Pwm_Channel_t channel, Pwm_Mode_t mode);

void Pwm_SetDutyCycle(Pwm_Channel_t channel, uint8_t dutyCycle);

void Pwm_Init(Pwm_Channel_t channel, Pwm_Config_t* config);

#endif /* PWM_H_ */
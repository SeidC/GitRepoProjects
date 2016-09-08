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



void Pwm_TogglePwm(Pwm_Status_t status);

void Pwm_Stop(void);

void Pwm_Start(void);

void Pwm_SetPwmFrequenze(Pwm_Prescaler_t prescaler);

void Pwm_ConfigureOutputPin(Pwm_OutputPin_t pinCfg);

void Pwm_SetPwmMode(Pwm_Mode_t mode);

#endif /* PWM_H_ */
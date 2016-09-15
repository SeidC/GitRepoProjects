/*
 * Pwm0.h
 *
 * Created: 08.09.2016 19:52:56
 *  Author: AP
 */ 


#ifndef PWM0_H_
#define PWM0_H_

#include "CommonTypes.h"


typedef enum 
{
   PWM0_PRESCALER_0            = 0,
   PWM0_PRESCALER_8            = 1,
   PWM0_PRESCALER_64           = 2,
   PWM0_PRESCALER_256          = 3,
   PWM0_PRESCALER_1024         = 4,  
   
}Pwm0_Prescaler_t;

typedef enum
{
   PWM0_STOP    = 0x00,
   PWM0_START         ,
   
}Pwm0_Status_t;

typedef enum
{
   PWM0_PHASE_CORRECT    = 0x01u,
   PWM0_FAST_PWM0         = 0x03u
   
}Pwm0_Mode_t;


typedef enum 
{
   PWM0_PIN_NOT_USED  = 0x00,
   PWM0_RESERVED            ,
   PWM0_INVERTED            ,
   PWM0_NON_INVERTED        ,
   
}Pwm0_OutputPin_t;



void Pwm0_TogglePwm0(Pwm0_Status_t status);

void Pwm0_Stop(void);

void Pwm0_Start(void);

void Pwm0_SetPwm0Frequenze(Pwm0_Prescaler_t prescaler);

void Pwm0_ConfigureOutputPin(Pwm0_OutputPin_t pinCfg);

void Pwm0_SetPwm0Mode(Pwm0_Mode_t mode);

void Pwm0_SetDutyCycle(uint8_t dutyCycle);

#endif /* PWM0_H_ */
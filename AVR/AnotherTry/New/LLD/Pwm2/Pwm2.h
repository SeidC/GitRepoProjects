/*
 * Pwm2.h
 *
 * Created: 08.09.2016 19:52:56
 *  Author: AP
 */ 


#ifndef PWM2_H_
#define PWM2_H_

#include "CommonTypes.h"


typedef enum 
{
   PWM2_PRESCALER_0            = 0,
   PWM2_PRESCALER_8            = 1,
   PWM2_PRESCALER_64           = 2,
   PWM2_PRESCALER_256          = 3,
   PWM2_PRESCALER_1024         = 4,  
   
}Pwm2_Prescaler_t;

typedef enum
{
   PWM2_STOP    = 0x00,
   PWM2_START         ,
   
}Pwm2_Status_t;

typedef enum
{
   PWM2_PHASE_CORRECT    = 0x01u,
   PWM2_FAST_PWM2         = 0x03u
   
}Pwm2_Mode_t;


typedef enum 
{
   PWM2_PIN_NOT_USED  = 0x00,
   PWM2_RESERVED            ,
   PWM2_INVERTED            ,
   PWM2_NON_INVERTED        ,
   
}Pwm2_OutputPin_t;



void Pwm2_TogglePwm2(Pwm2_Status_t status);

void Pwm2_Stop(void);

void Pwm2_Start(void);

void Pwm2_SetPwm2Frequenze(Pwm2_Prescaler_t prescaler);

void Pwm2_ConfigureOutputPin(Pwm2_OutputPin_t pinCfg);

void Pwm2_SetPwm2Mode(Pwm2_Mode_t mode);

void Pwm2_SetDutyCycle(uint8_t dutyCycle);

#endif /* PWM2_H_ */
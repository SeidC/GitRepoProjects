/*
 * New.c
 *
 * Created: 08.09.2016 19:49:00
 * Author : AP
 */ 

#include <avr/io.h>
#include "Pwm.h"
#include "Adc.h"


int main(void)
{
   
   Pwm_SetPwmMode(PWM_PHASE_CORRECT);
   Pwm_ConfigureOutputPin(PWM_INVERTED);
   Pwm_SetPwmFrequenze(PWM_PRESCALER_0);
   Pwm_TogglePwm(PWM_START);
   Pwm_SetDutyCycle(75);
   sei();
   Adc_Init();
   Adc_ToggleAdc(ADC_ENABLE);
   Adc_ToggleContinouseConversion(ADC_CHANNEL_0,ADC_ENABLE);
    /* Replace with your application code */
    while (1) 
    {
		
    }
}


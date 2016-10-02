/*
 * New.c
 *
 * Created: 08.09.2016 19:49:00
 * Author : AP
 */ 

#include <avr/io.h>
#include "TLE5206.h"
#include "Adc.h"

#define ADC_MAX 1023u
uint16_t dutyCycle;
uint16_t adcValue;
uint32_t calc;
int main(void)
{
    //uint16_t adcValue;
	//uint16_t dutyCycle;
    Adc_Init();
	Adc_ToggleAdc(ADC_ENABLE);
	Adc_ToggleContinouseConversion(ADC_CHANNEL_0,ADC_ENABLE);
	TLE5206_Init();
	TLE5206_SetInput(TLE5206_BRIDGE_00,TLE5206_INPUT_01);
    TLE5206_Enable(TLE5206_BRIDGE_00);
	TLE5206_ActivatePwm(TLE5206_BRIDGE_00);
	/* Replace with your application code */
    while (1) 
    {
		adcValue = Adc_Read(ADC_CHANNEL_0);
		calc = (uint32_t)adcValue * 100;
		dutyCycle = calc / ADC_MAX;
		TLE5206_SetDutyCycle(TLE5206_BRIDGE_00,(uint8_t)dutyCycle);
		
    }
}


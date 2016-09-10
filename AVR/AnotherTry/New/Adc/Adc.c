/*
 * Adc.c
 *
 * Created: 10.09.2016 00:56:29
 *  Author: AP
 */ 
#include "Adc.h"


vuin16_t Adc_adcValues[ADC_NUMBER_OF_CHANNELS];




void Adc_Init(void)
{
     uint8 i;
     
     for(i = 0; i < ADC_NUMBER_OF_CHANNELS; i++)
     {
        Adc_adcValues[i] = 0u;
     }
   
     ADMUX  = ADC_MUX_REGISTER_CONFIG;
     ADCSRA = ADC_ADCSRA_REGISTER_CONFIG; 
   
}


void Adc_SetChannel(Adc_Channel_t channel)
{
   
}


uint16_t Adc_Read(Adc_Channel_t channel)
{
   uint16_t ret = 0;
   if(channel < ADC_NUMBER_OF_CHANNELS)
   {
      ret = Adc_adcValues[(uint8_t)channel];
   }
   
   return ret;
}
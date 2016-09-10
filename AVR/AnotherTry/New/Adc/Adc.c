/*
 * Adc.c
 *
 * Created: 10.09.2016 00:56:29
 *  Author: AP
 */ 
#include "Adc.h"
#include <avr/interrupt.h>


#define ADC_CHANNEL_BITS            0x07


vuin16_t Adc_adcValues[ADC_NUMBER_OF_CHANNELS];
bool Adc_interruptFinished;

ISR(ADC_vect)
{
   
   
   
   Adc_interruptFinished = TRUE;   
}


void Adc_Init(void)
{
     uint8_t i;
     
     for(i = 0; i < ADC_NUMBER_OF_CHANNELS; i++)
     {
        Adc_adcValues[i] = 0u;
     }
     Adc_interruptFinished = FALSE;
   
     ADMUX  = ADC_MUX_REGISTER_CONFIG;
     ADCSRA = ADC_ADCSRA_REGISTER_CONFIG; 
}


void Adc_StartSingleConversion(Adc_Channel_t channel, bool waitUntilFinished)
{
   uint8_t reg;
   
   reg = (ADCSRA & ~(ADC_CHANNEL_BITS));
   reg |= (uint8_t)channel;
   ADCSRA = reg;
   /*Check if ADC is Enabled. If it isn't enabled do nothing*/
   if((ADCSRA & (1 << ADEN)) != 0)
   {
      /*Start Conversion...*/
      ADCSRA |= (1 << ADSC);
      /*If it should be waited until finished enter If clause*/
      if(waitUntilFinished == TRUE)
      {
         /*Wait until finished*/
         while((ADCSRA & (1 << ADIF)) == 0 );     
      }
   }   
   return;   
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

Adc_Channel_t Adc_GetCurrentChannel(void)
{
   return (ADCSRA & ADC_CHANNEL_BITS);
}


void Adc_ToggleAdc(Adc_Status_t status)
{
   if (status == ADC_ENABLE)
   {
      ADCSRA |= (1 << ADEN);
   }
   else
   {
      ADCSRA &= ~(1 << ADEN);
   }
   return;
}

void Adc_ToggleContinouseConversion(Adc_Status_t status)
{
   if(status == ADC_ENABLE)
   {
      ADCSRA |= (1 << ADATE);
   }
   else
   {
      ADCSRA &= ~(1 << ADATE);   
   }
   return;
}

bool Adc_IsConverstionFinished(void)
{
   bool ret = FALSE;
   if((ADCSRA & (1 << ADIE) == 0))
   {
       ret = Adc_interruptFinished;
       Adc_interruptFinished = FALSE;
   }
   else 
   {
      ret = (bool)(ADCSRA & (1 << ADIF) >> ADIF);
      ADCSRA |= (1 << ADIF),
   }
   return ret;
}
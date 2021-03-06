/*
 * Adc.c
 *
 * Created: 10.09.2016 00:56:29
 *  Author: AP
 */ 
#include "Adc.h"
#include <avr/interrupt.h>


typedef enum 
{
	ADC_INTERRUPT_FINISHED			= 0x00,
	ADC_INTERRUPT_SINGEL_CHANNEL		  ,
	ADC_NUMBER_OF_INTERRUPT_FLAGS		
	
}Adc_InterruptFlags_t;

#define ADC_CHANNEL_BITS            0x1F




volatile uint16_t Adc_adcValues[ADC_NUMBER_OF_CHANNELS];

volatile bool Adc_interruptFlags[ADC_NUMBER_OF_INTERRUPT_FLAGS];



ISR(ADC_vect)
{
   Adc_Channel_t currChannel;
   
   currChannel = Adc_GetCurrentChannel(); 
   Adc_adcValues[currChannel] =  ADCW; 
   if((ADCSRA & (1 << ADATE)) != 0)
   {
      if(Adc_interruptFlags[ADC_INTERRUPT_SINGEL_CHANNEL] == FALSE)
      {
         if(currChannel < ADC_NUMBER_OF_CHANNELS)
         {
            Adc_SetChannel(currChannel + 1);
         }
         else
         {
            Adc_SetChannel(ADC_CHANNEL_0);
         }        
      }  
   }   
   Adc_interruptFlags[ADC_INTERRUPT_FINISHED] = TRUE;   
}


void Adc_Init(void)
{
     uint8_t i;
     
     Adc_interruptFlags[ADC_INTERRUPT_FINISHED] = FALSE;
   
     ADMUX  = ADC_MUX_REGISTER_CONFIG;
     ADCSRA = ADC_ADCSRA_REGISTER_CONFIG; 
     
     Adc_ToggleAdc(ADC_ENABLE);
     Adc_StartSingleConversion(ADC_CHANNEL_0,FALSE);    
     (void)ADCW; 
     
     for(i = 0; i < ADC_NUMBER_OF_CHANNELS; i++)
     {
        Adc_adcValues[i] = 0u;
     }
     Adc_ToggleAdc(ADC_DISABLE);
     
     if (ADC_ENABLE_INTERRUPT == TRUE)
     {
        sei();
     }
     
     return;
}

void Adc_SetChannel(Adc_Channel_t channel)
{
   uint8_t reg;
   if(channel != ADC_ALL_CHANNELS)
   {
      reg = (ADMUX & ~(ADC_CHANNEL_BITS));
      reg |= (uint8_t)channel;
      ADMUX = reg;
   }   
}

void Adc_StartSingleConversion(Adc_Channel_t channel, bool waitUntilFinished)
{
   if(channel != ADC_ALL_CHANNELS)
   {
      Adc_SetChannel(channel);
      /*Check if ADC is Enabled. If it isn't enabled do nothing*/
      if((ADCSRA & (1 << ADEN)) != 0)
      {
         /*Start Conversion...*/
         ADCSRA |= (1 << ADSC);
         /*If it should be waited until finished enter If clause*/
         if(waitUntilFinished == TRUE)
         {
            Adc_DisableAdcInterrupt();
            /*Wait until finished*/
            while((ADCSRA & (1 << ADSC))) {}
			   Adc_adcValues[channel] =  ADCW;
            Adc_EnableAdcInterrupt();		
         }
      }
   }      
   return;   
}


uint16_t Adc_Read(Adc_Channel_t channel)
{
   uint16_t ret = 0;
   if((channel < ADC_NUMBER_OF_CHANNELS) && 
      (channel != ADC_ALL_CHANNELS))
   {
      ret = Adc_adcValues[(uint8_t)channel];
   }
   return ret;
}


Adc_Channel_t Adc_GetCurrentChannel(void)
{
   return (ADMUX & ADC_CHANNEL_BITS);
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

void Adc_ToggleContinouseConversion(Adc_Channel_t channel, Adc_Status_t status)
{
   Adc_Channel_t ch;
   if(status == ADC_ENABLE)
   {
      if(channel == ADC_ALL_CHANNELS)
      {
         Adc_interruptFlags[ADC_INTERRUPT_SINGEL_CHANNEL] = FALSE;
         ch = ADC_CHANNEL_0;
      }
      else
      {
         ch = channel;
		 Adc_interruptFlags[ADC_INTERRUPT_SINGEL_CHANNEL] = TRUE;
      }
      Adc_SetChannel(ch);
      ADCSRA |= (1 << ADATE) | (1 << ADSC);
	  Adc_ToggleAdc(ADC_ENABLE);
   }
   else
   {
      ADCSRA &= ~(1 << ADATE) & ~(1 << ADSC); 
	  Adc_ToggleAdc(ADC_DISABLE);
      Adc_interruptFlags[ADC_INTERRUPT_SINGEL_CHANNEL] = FALSE;
   }
   return;
}

bool Adc_IsConverstionFinished(void)
{
   bool ret = FALSE;
   if((ADCSRA & (1 << ADIE)) == 0)
   {
       ret = Adc_interruptFlags[ADC_INTERRUPT_FINISHED];
       Adc_interruptFlags[ADC_INTERRUPT_FINISHED] = FALSE;
   }
   else 
   {
      ret = (bool)(ADCSRA & (1 << ADIF) >> ADIF);
      ADCSRA |= (1 << ADIF);
   }
   return ret;
}

ADC_INLINE void Adc_EnableAdcInterrupt(void)
{
   ADCSRA |= (1 << ADIE);
   return;
}

ADC_INLINE void Adc_DisableAdcInterrupt(void)
{
   ADCSRA &= ~(1 << ADIE);
   return;
}
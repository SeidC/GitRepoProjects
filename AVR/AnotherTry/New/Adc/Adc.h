/*
 * Adc.h
 *
 * Created: 10.09.2016 00:56:12
 *  Author: AP
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "CommonTypes.h"

#define ADC_NUMBER_OF_CHANNELS				0x07u
#define ADC_ENABLE_INTERRUPT              TRUE

/*--- Configuration Flags for the ADC MUX Register ------------------------------------------------------*/
#define ADC_MUX_REF_AREF				      0x00u
#define ADC_MUX_REF_INTERNAL_AVCC		   0x40u
#define ADC_MUX_REF_INTERNAL_256V		   0xC0u
#define ADC_MUX_LEFT_ADJUST					0x20u
#define ADC_MUX_RIGHT_ADJUT					0x00u

/*--- Configuration Value which will be use to initialize the ADC Mux Register---------------------------*/
#define ADC_MUX_REGISTER_CONFIG				ADC_MUX_REF_AREF     |  \
											         ADC_MUX_RIGHT_ADJUT


#define ADC_ADCSRA_PRESCALER_2				0x01u
#define ADC_ADCSRA_PRESCALER_4				0x02u
#define ADC_ADCSRA_PRESCALER_8				0x03u
#define ADC_ADCSRA_PRESCALER_16				0x04u
#define ADC_ADCSRA_PRESCALER_32				0x05u
#define ADC_ADCSRA_PRESCALER_64				0x06u
#define ADC_ADCSRA_PRESCALER_128			   0x07u

#if ADC_ENABLE_INTERRUPT == TRUE 
   #define ADC_ADCSRA_INTERRUPT_ENABLE       (1 << ADIE)
#else 
   #define ADC_ADCSRA_INTERRUPT_ENABLE        0x00
#endif

#define ADC_ADCSRA_REGISTER_CONFIG			ADC_ADCSRA_PRESCALER_2        |   \
                                          ADC_ADCSRA_INTERRUPT_ENABLE


typedef enum 
{
   ADC_CHANNEL_0     = 0x00,
   ADC_CHANNEL_1     = 0x01,
   ADC_CHANNEL_2     = 0x02,
   ADC_CHANNEL_3     = 0x03,
   ADC_CHANNEL_4     = 0x04,
   ADC_CHANNEL_5     = 0x05,
   ADC_CHANNEL_6     = 0x06,
   ADC_CHANNEL_7     = 0x07,
   
}Adc_Channel_t;

typedef enum 
{
   ADC_DISABLE       = 0x00u,
   ADC_ENABLE        = 0x01u
}Adc_Status_t;

void Adc_Init(void);


uint16_t Adc_Read(Adc_Channel_t channel);

void Adc_ToggleContinouseConversion(Adc_Status_t status);

void Adc_ToggleAdc(Adc_Status_t status);

Adc_Channel_t Adc_GetCurrentChannel(void);

bool Adc_IsConverstionFinished(void);

void Adc_ToggleContinouseConversion(Adc_Status_t status);

void Adc_ToggleAdc(Adc_Status_t status);

void Adc_StartSingleConversion(Adc_Channel_t channel, bool waitUntilFinished);

#if (ADC_ENABLE_INTERRUPT == FALSE)
      #error "Interrupt has to be enabled. Manual ADC coversation is not supported"
#endif

#endif /* ADC_H_ */
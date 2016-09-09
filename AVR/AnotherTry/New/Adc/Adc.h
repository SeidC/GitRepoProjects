/*
 * Adc.h
 *
 * Created: 10.09.2016 00:56:12
 *  Author: AP
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "CommonTypes.h"

#define ADC_NUMBER_OF_CHANNELS				0x07


#define ADC_MUX_REF_AREF				    0x00
#define ADC_MUX_REF_AVCC					0x40
#define ADC_MUX_REF_INTERNAL				0xC0

#define ADC_MUX_LEFT_ADJUST					0x20
#define ADC_MUX_RIGHT_ADJUT					0x00



#define ADC_MUX_REGISTER_CONFIG				ADC_MUX_REF_AREF     |  \
											ADC_MUX_RIGHT_ADJUT


#define ADC_ADCSRA_PRESCALER_2				0x01
#define ADC_ADCSRA_PRESCALER_4				0x02
#define ADC_ADCSRA_PRESCALER_8				0x03
#define ADC_ADCSRA_PRESCALER_16				0x04
#define ADC_ADCSRA_PRESCALER_32				0x05
#define ADC_ADCSRA_PRESCALER_64				0x06
#define ADC_ADCSRA_PRESCALER_128			0x07



#define ADC_ADCSRA_REGISTER_CONFIG			ADC_ADCSRA_PRESCALER_2


#endif /* ADC_H_ */
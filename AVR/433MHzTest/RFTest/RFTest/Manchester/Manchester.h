/*
 * Manchester.h
 *
 * Created: 09.10.2016 00:57:23
 *  Author: AP02
 */ 


#ifndef MANCHESTER_H_
#define MANCHESTER_H_

#include "avr/io.h"

#define MANCHESTER_BIPHASE_L                0x00
#define MANCHESTER_IEEE_802_3               0x01


#define MANCHESTER_CODING_TYPE              MANCHESTER_IEEE_802_3


#define MANCHESTER_FALLING_EDGE             0b10


#define MANCHESTER_RISING_EDGE              0b01

#if(MANCHESTER_CODING_TYPE == MANCHESTER_IEEE_802_3)

    #define MANCHESTER_SET_PARAMETER_FOR_ZERO(data)               \
        (*data->ticks|= (MANCHESTER_FALLING_EDGE << data->sizeOfTicks))


    #define MANCHESTER_SET_PARAMETER_FOR_ONE(data)                \
        (*data->ticks|= (MANCHESTER_RISING_EDGE << data->sizeOfTicks))

#else
    #define MANCHESTER_SET_PARAMETER_FOR_ZERO(data)               \
        (*data->ticks|= (MANCHESTER_RISING_EDGE << data->sizeOfTicks))


    #define MANCHESTER_SET_PARAMETER_FOR_ONE(data)                \
        (*data->ticks|= (MANCHESTER_FALLING_EDGE << data->sizeOfTicks))
#endif



#define MANCHESTER_CALCULATE_DATA_SIZE(msgSize)                \
    (msgSize * 2)


#define MANCHESTER_GET_NUMBER_OF_TICKS(data)					\
		(*data.sizeOfTicks)

#define MANCHESTER_GET_BIT(val,bit)								\
		(((val & (1 << bit)) >> bit))

typedef struct  
{
   uint8_t* ticks;
   uint8_t sizeOfTicks;
   uint8_t tickPos;
}Manchester_t;


void Manchester_EncodeChar(char p, Manchester_t *encodedData);


uint8_t Manchester_GetTick(Manchester_t* encodedData);

void Manchester_SetTickPosToStart(Manchester_t* encodedData);


#endif /* MANCHESTER_H_ */



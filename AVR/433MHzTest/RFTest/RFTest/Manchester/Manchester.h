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

    #define MANCHESTER_SET_PARAMETER_FOR_ZERO(data,index)               \
        (data->ticks[index]|= (MANCHESTER_FALLING_EDGE << data->tickPos))


    #define MANCHESTER_SET_PARAMETER_FOR_ONE(data,index)                \
        (data->ticks[index]|= (MANCHESTER_RISING_EDGE << data->tickPos))

#else
    #define MANCHESTER_SET_PARAMETER_FOR_ZERO(data,index)               \
        (data->ticks[index]|= (MANCHESTER_RISING_EDGE << data->tickPos))


    #define MANCHESTER_SET_PARAMETER_FOR_ONE(data,index)                \
        (data->ticks[index]|= (MANCHESTER_FALLING_EDGE << data->tickPos))
#endif



#define MANCHESTER_CALCULATE_DATA_SIZE(bufferPtr)                \
    (sizeof(bufferPtr))


#define MANCHESTER_GET_NUMBER_OF_TICKS(data)					\
    ((data)->sizeOfTicks)

#define MANCHESTER_GET_BIT(val,bit)								\
        ((val & (1 << (bit))) >> (bit))

#define MANCHESTER_CALCULATE_TICK_INDEX(data)                   \
        ((data)->sizeOfTicks / 16)

typedef struct  
{
   uint16_t* ticks;
   uint8_t sizeOfTicks;
   uint8_t tickPos;
}Manchester_t;


void Manchester_EncodeChar(char p, Manchester_t *encodedData);

uint8_t Manchester_GetTick(Manchester_t* encodedData);

void Manchester_SetTickPosToStart(Manchester_t* encodedData);

char Manchester_DecodeChar(Manchester_t *dataToDecode);

uint8_t Manchester_GetValueForEdge(uint8_t edge);

void Manchester_EncodeString(char* str,uint8_t strLen, Manchester_t* encodedData);

void Manchester_DecodeString(char* str,uint8_t strLen, Manchester_t* dataToDecode);

#endif /* MANCHESTER_H_ */



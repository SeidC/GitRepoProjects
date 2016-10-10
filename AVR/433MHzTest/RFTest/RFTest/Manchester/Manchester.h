/*
 * Manchester.h
 *
 * Created: 09.10.2016 00:57:23
 *  Author: AP02
 */ 


#ifndef MANCHESTER_H_
#define MANCHESTER_H_

#include "avr/io.h"

#define MANCHESTER_FALLING_EDGE(data)               \
    {                                               \
        data->ticks[data->sizeOfTicks]     = 1;     \
        data->ticks[data->sizeOfTicks + 1] = 0;     \
    }


#define MANCHESTER_RISING_EDGE(data)                \
    {                                               \
        data->ticks[data->sizeOfTicks]     = 0;     \
        data->ticks[data->sizeOfTicks + 1] = 1;     \
    }

#define MANCHESTER_CALCULATE_DATA_SIZE(msgSize)     \
    (msgSize * 8 * 2)


typedef struct  
{
   uint8_t* ticks;
   uint8_t sizeOfTicks;
}Manchester_t;


void Manchester_EncodeChar(char p, Manchester_t *encodedData);


#endif /* MANCHESTER_H_ */



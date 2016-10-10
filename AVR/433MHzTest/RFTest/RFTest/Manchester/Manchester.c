/*
 * Manchester.c
 *
 * Created: 09.10.2016 00:57:10
 *  Author: AP02
 */ 

#include "Manchester.h"

#define GET_CURRENT_TICKS(data)							\
		(data->sizeOfTicks)

#define INCREMENT_TICKS(data)							\
		(data->sizeOfTicks += 2)


void Manchester_EncodeChar(char p, Manchester_t *encodedData)
{
    uint8_t i;
    uint8_t current ;
	
	for(i = 0; i < 8; i++)
	{
        current = ((p & (1 << i)) >> i);
		if (current == 1)
		{
            MANCHESTER_SET_PARAMETER_FOR_ONE(encodedData);
		}
		else
		{
            MANCHESTER_SET_PARAMETER_FOR_ZERO(encodedData);
		}
		INCREMENT_TICKS(encodedData);
	} 
    return;
}

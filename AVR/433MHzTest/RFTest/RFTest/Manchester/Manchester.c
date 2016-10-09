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
		(data->sizeOfTicks++)


void Manchester_EncodeChar(char p, Manchester_t *encodedData)
{
	uint8_t i, ticks = 0;
	uint8_t last,current ;
	
	for(i = 0; i < 8; i++)
	{
		ticks = GET_CURRENT_TICKS(encodedData);
		current = (p & (1 << i) >> i);
		if (last & current)
		{
			
		}
		else
		{
			
		}
		INCREMENT_TICKS(encodedData);
	} 
}
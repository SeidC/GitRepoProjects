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

#define SET_TICK_POSITION(data)							\
		(data->tickPos = 0)


void Manchester_EncodeChar(char p, Manchester_t *encodedData)
{
    uint8_t i;
    uint8_t current ;
	   
	for(i = 0; i < 8; i++)
	{
        current = MANCHESTER_GET_BIT(p,i);
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
	SET_TICK_POSITION(encodedData);
    return;
}


uint8_t Manchester_GetTick(Manchester_t* encodedData)
{
	uint8_t tick = 0;
	if(tick < encodedData->sizeOfTicks)
	{
		tick = MANCHESTER_GET_BIT(*encodedData->ticks,encodedData->tickPos);
		encodedData->tickPos++;
	}
	return tick;
}


void Manchester_SetTickPosToStart(Manchester_t* encodedData)
{
    encodedData->tickPos = 0;
    return;
}


char Manchester_DecodeChar(Manchester_t *dataToDecode)
{
    uint8_t i = 0, edge = 0, bitValue = 0;
    uint8_t ret = 0;

    for(i = 0; i < 16; i += 2)
    {
        edge |= MANCHESTER_GET_BIT(*dataToDecode->ticks,i);
        edge |= MANCHESTER_GET_BIT(*dataToDecode->ticks,i);
        bitValue = Manchester_GetValueForEdge(edge);
        ret |= (bitValue << (i/2));
    }
    return (char)ret;
}

uint8_t Manchester_GetValueForEdge(uint8_t edge)
{
   uint8_t ret = 0;
   if (MANCHESTER_CODING_TYPE == MANCHESTER_IEEE_802_3)
   {
      (edge == MANCHESTER_FALLING_EDGE) ? ret = 0 : ret = 1;
   }
   else
   {
     (edge == MANCHESTER_FALLING_EDGE) ? ret = 1 : ret = 0;
   }
   return ret;
}
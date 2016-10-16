/*
 * Manchester.c
 *
 * Created: 09.10.2016 00:57:10
 *  Author: AP02
 */ 

#include "Manchester.h"

#define GET_CURRENT_TICKS(data)                                 \
        (data->tickPos)

#define SET_TICK_POSITION(data,value)							\
        (data->tickPos = value)

#define RESET_SIZE_OF_TICKS(data)                                   \
        (data->sizeOfTicks = 0;

#define SET_SIZE_OF_TICKS(data,value)                           \
        (data->sizeOfTicks = value)

#define INCREMENT_TICK_POS(data)                               \
        (data->tickPos += 2)


void Manchester_EncodeChar(char p, Manchester_t *encodedData)
{
    uint8_t i;
    uint8_t current;

    SET_TICK_POSITION(encodedData,0);

	for(i = 0; i < 8; i++)
	{
        current = MANCHESTER_GET_BIT(p,i);
        if (current == 1)
        {
            MANCHESTER_SET_PARAMETER_FOR_ONE(encodedData,0);
        }
        else
        {
            MANCHESTER_SET_PARAMETER_FOR_ZERO(encodedData,0);
        }
        INCREMENT_TICK_POS(encodedData);
	} 
    SET_SIZE_OF_TICKS(encodedData,GET_CURRENT_TICKS(encodedData));
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
        edge |=(MANCHESTER_GET_BIT(*dataToDecode->ticks,i+1) << 1);
        bitValue = Manchester_GetValueForEdge(edge);
        ret |= (bitValue << (i/2));
        edge = 0;
    }
    return (char)ret;
}

uint8_t Manchester_GetValueForEdge(uint8_t edge)
{
   uint8_t ret = 0;
   if (MANCHESTER_CODING_TYPE == MANCHESTER_IEEE_802_3)
   {
      (edge == MANCHESTER_FALLING_EDGE) ? (ret = 0) : (ret = 1);
   }
   else
   {
     (edge == MANCHESTER_FALLING_EDGE) ? (ret = 1) : (ret = 0);
   }
   return ret;
}


void Manchester_EncodeString(char* str,uint8_t strLen, Manchester_t* encodedData)
{
    uint8_t i = 0,j = 0,bit = 0, maxTicks = 0;


    SET_TICK_POSITION(encodedData,0);

    for(j = 0; j < strLen; j++)
    {
        for(i = 0; i < 8; i++)
        {
            bit = MANCHESTER_GET_BIT(str[j],i);
            if (bit == 1)
            {
                MANCHESTER_SET_PARAMETER_FOR_ONE(encodedData,j);
            }
            else
            {
                MANCHESTER_SET_PARAMETER_FOR_ZERO(encodedData,j);
            }
            INCREMENT_TICK_POS(encodedData);
        }
        maxTicks = GET_CURRENT_TICKS(encodedData) + MANCHESTER_GET_NUMBER_OF_TICKS(encodedData);
        SET_SIZE_OF_TICKS(encodedData,maxTicks);
        SET_TICK_POSITION(encodedData,0);
    }
    return;
}


void Manchester_DecodeString(char* str,uint8_t strLen, Manchester_t* dataToDecode)
{
    uint8_t i = 0, j = 0, edge = 0, bitValue = 0;

    for(j = 0; j < strLen; j++)
    {
        for(i = 0; i < 16; i += 2)
        {
            edge |= MANCHESTER_GET_BIT(dataToDecode->ticks[j],i);
            edge |=(MANCHESTER_GET_BIT(dataToDecode->ticks[j],i+1) << 1);
            bitValue = Manchester_GetValueForEdge(edge);
            str[j]|= (bitValue << (i/2));
            edge = 0;
        }
    }
    return;
}

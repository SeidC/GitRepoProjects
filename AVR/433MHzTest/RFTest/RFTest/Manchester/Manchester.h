/*
 * Manchester.h
 *
 * Created: 09.10.2016 00:57:23
 *  Author: AP02
 */ 


#ifndef MANCHESTER_H_
#define MANCHESTER_H_
#include "avr/io.h"


typedef struct  
{
   uint8_t* ticks;
   uint8_t sizeOfTicks;
}Manchester_t;


#define MANCHESTER_PREPARE_DATA()

void Manchester_EncodeChar(char p, Manchester_t *encodedData);


#endif /* MANCHESTER_H_ */
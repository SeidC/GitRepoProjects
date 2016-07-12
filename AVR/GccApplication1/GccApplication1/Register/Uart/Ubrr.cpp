/* 
* Ubrr.cpp
*
* Created: 11.07.2016 22:08:55
* Author: AP
*/


#include "Ubrr.h"

// default constructor
Ubrr::Ubrr(value uint8_t * ubrrPtr)
{
    setRegister(ubrrPtr);
} //Ubrr

// default destructor
Ubrr::~Ubrr()
{
} //~Ubrr

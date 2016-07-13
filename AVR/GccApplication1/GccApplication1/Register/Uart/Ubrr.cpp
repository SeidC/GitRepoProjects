/* 
* Ubrr.cpp
*
* Created: 11.07.2016 22:08:55
* Author: AP
*/


#include "Ubrr.h"

// default constructor
Ubrr::Ubrr(volatile uint8_t* ubrrHPtr, volatile uint8_t* ubrrLPtr)
{
    setRegister(ubrrHPtr,ubrrLPtr);

} //Ubrr

// default destructor
Ubrr::~Ubrr()
{
} //~Ubrr

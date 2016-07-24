/* 
* Ubrr.cpp
*
* Created: 11.07.2016 22:08:55
* Author: AP
*/


#include "Ubrr.h"

// default constructor
Ubrr::Ubrr(vuint8_t* ubrrHPtr, vuint8_t* ubrrLPtr)
{
    setRegister(ubrrHPtr,ubrrLPtr);

} //Ubrr

// default destructor
Ubrr::~Ubrr()
{
} //~Ubrr

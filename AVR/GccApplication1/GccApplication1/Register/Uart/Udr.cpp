/* 
* Udr.cpp
*
* Created: 11.07.2016 22:08:10
* Author: AP
*/


#include "Udr.h"

// default constructor
Udr::Udr(volatile uint8_t* udrPtr)
{
    setRegister(udrPtr);
} //Udr

// default destructor
Udr::~Udr()
{
} //~Udr

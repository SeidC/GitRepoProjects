/* 
* Ucsrc.cpp
*
* Created: 11.07.2016 22:08:34
* Author: AP
*/


#include "Ucsrc.h"

// default constructor
Ucsrc::Ucsrc(vuint8_t* ucsrcPtr)
{
    setRegister(ucsrcPtr);
} //Ucsrc

// default destructor
Ucsrc::~Ucsrc()
{
} //~Ucsrc

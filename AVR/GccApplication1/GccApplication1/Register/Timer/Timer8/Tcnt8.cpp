/* 
* Tcnt8.cpp
*
* Created: 17.07.2016 00:14:56
* Author: AP
*/


#include "Tcnt8.h"

Tcnt8::Tcnt8()
{

} //Tcnt8


// default constructor
Tcnt8::Tcnt8(vuint8_t* tcntPtr)
{
    setRegister(tcntPtr);
} //Tcnt8

// default destructor
Tcnt8::~Tcnt8()
{
} //~Tcnt8


uint16_t Tcnt8::getTime(void)
{
    return getValue();
}



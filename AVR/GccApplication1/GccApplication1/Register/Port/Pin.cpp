/* 
* Pin.cpp
*
* Created: 08.07.2016 20:59:25
* Author: AP02
*/


#include "Pin.h"

Pin::Pin()
{
   
} //Pin

// default constructor
Pin::Pin(vuint8_t* pinPtr)
{
    setRegister(pinPtr);
} //Pin

// default destructor
Pin::~Pin()
{
} //~Pin


Pin::PinStatus_e Pin::getPin(Pin::Pin_e pin)
{
    return (Pin::PinStatus_e)this->getBit((BaseTypes::Bits_e)pin);
}
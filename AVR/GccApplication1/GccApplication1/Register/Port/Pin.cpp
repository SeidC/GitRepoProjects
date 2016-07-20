/* 
* Pin.cpp
*
* Created: 08.07.2016 20:59:25
* Author: AP02
*/


#include "Pin.h"

// default constructor
Pin::Pin(volatile uint8_t* pinPtr)
{
} //Pin

// default destructor
Pin::~Pin()
{
} //~Pin


BaseTypes::BitStatus_e Pin::getPin(Pin::Pin_e pin)
{
    return (BaseTypes::BitStatus_e)getBit((BaseTypes::Bits_e)pin);
}
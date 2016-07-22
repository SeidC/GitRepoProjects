/* 
* Port.cpp
*
* Created: 08.07.2016 20:59:14
* Author: AP02
*/


#include "Port.h"

// default constructor
Port::Port(vuint8_t* portPtr)
{
    setRegister(portPtr);
    setBits(0x00);
} //Port

// default destructor
Port::~Port()
{
} //~Port

 void Port::setPin(Port::Pin_e pin,Port::PinStatus_e status)
 {
    if(status == Port::PIN_HIGH)
    {
        setBit((BaseTypes::Bits_e)pin);
    }
    else
    {
        resetBit((BaseTypes::Bits_e)pin);
    }
 }
 
 void Port::setPullUp(Pin_e pin,PullUpStatus_e status)
 {
     if(status == Port::PULL_UP_ENABLE)
     {
         setBit((BaseTypes::Bits_e)pin);
     }
     else
     {
         resetBit((BaseTypes::Bits_e)pin);
     }
 }
 
 
 void Port::setPinsHigh(uint8_t pinMask)
 {
     setBits(pinMask);
 }
 
 void Port::setPinsLow(uint8_t pinMask)
 {
     resetBits(pinMask);
 }
/* 
* Port.cpp
*
* Created: 08.07.2016 20:59:14
* Author: AP02
*/


#include "Port.h"

// default constructor
 Port::Port()
 {
    
 }

Port::Port(vuint8_t* portPtr)
{
    this->setRegister(portPtr);
    this->setBits(0x00);
} //Port

// default destructor
Port::~Port()
{
} //~Port

 void Port::setPort(Port::Port_e pin,Port::PortStatus_e status)
 {
    if(status == Port::PORT_HIGH)
    {
        this->setBit((BaseTypes::Bits_e)pin);
    }
    else
    {
        this->resetBit((BaseTypes::Bits_e)pin);
    }
 }
  
 
void Port::setPortsHigh(uint8_t pinMask)
{
   this->setBits(pinMask);
}
 
void Port::setPortsLow(uint8_t pinMask)
{
   this->resetBits(pinMask);
}
 
Port::PortStatus_e Port::getPort(Port::Port_e port)
{
   return (Port::PortStatus_e) this->getBit((BaseTypes::Bits_e)port);
}
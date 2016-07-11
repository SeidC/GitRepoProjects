/* 
* Port.cpp
*
* Created: 08.07.2016 20:59:14
* Author: AP02
*/


#include "Port.h"

// default constructor
Port::Port(volatile uint8_t* portPtr)
{
    setRegister(portPtr);
} //Port

// default destructor
Port::~Port()
{
} //~Port

 void Port::setOutput(BaseTypes::Bits_e bit,BaseTypes::BitStatus_e status)
 {
    if(status == BaseTypes::BIT_HIGH)
    {
        setBit(bit);
    }
    else
    {
        resetBit(bit);
    }
 }
 
 void Port::setPullUp(BaseTypes::Bits_e bit,BaseTypes::BitStatus_e status)
 {
     if(status == BaseTypes::BIT_HIGH)
     {
         setBit(bit);
     }
     else
     {
         resetBit(bit);
     }
 }
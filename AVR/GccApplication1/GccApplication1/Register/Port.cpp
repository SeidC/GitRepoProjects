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
} //Port

// default destructor
Port::~Port()
{
} //~Port



void Port::setRegister(volatile uint8_t *reg)
{
    port.byte = reg;
}

void Port::setBit(BaseTypes::Bits_e bit)
{
   SET_BIT(*port.byte,bit);
}

void Port::setBits(uint8_t bits)
{
    SET_BITS(*port.byte,bits);   
}

 BaseTypes::BitRegister_t* Port::getRegister(void)
 {
     return &port;
 }
 
 void Port::setOutput(BaseTypes::Bits_e bit,BaseTypes::boolean status)
 {
     
     
 }
 void Port::setPullUp(BaseTypes::Bits_e bit,BaseTypes::boolean status)
 {
     
 }
/* 
* Pin.cpp
*
* Created: 08.07.2016 20:59:25
* Author: AP02
*/


#include "Pin.h"

// default constructor
Pin::Pin()
{
} //Pin

// default destructor
Pin::~Pin()
{
} //~Pin


void Pin::setRegister(volatile uint8_t *reg)
{
    pin.byte = reg;
}


 void Pin::setBit(BaseTypes::Bits_e bit)
 {
     SET_BIT(*(pin.byte),bit);
 }
 
 
 void Pin::setBits(uint8_t bits)
 {
     SET_BITS(*(pin.byte),bits);
 }
 
 BaseTypes::BitRegister_t* Pin::getRegister(void)
 {
     return &pin;
 }
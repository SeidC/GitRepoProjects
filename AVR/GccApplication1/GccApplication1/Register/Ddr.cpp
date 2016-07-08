/* 
* Ddr.cpp
*
* Created: 08.07.2016 20:58:57
* Author: AP02
*/


#include "Ddr.h"

// default constructor
Ddr::Ddr()
{
} //Ddr

// default destructor
Ddr::~Ddr()
{
} //~Ddr


void Ddr::setRegister(volatile uint8_t *reg)
{
    ddr.byte = reg;
}

void Ddr::setBit(BaseTypes::Bits_e bit)
{
    SET_BIT(*ddr.byte,bit);
}

void Ddr::setBits(uint8_t bits)
{
    SET_BITS(*ddr.byte,bits);
}

 BaseTypes::BitRegister_t* Ddr::getRegister(void)
 {
     return &ddr;
 }
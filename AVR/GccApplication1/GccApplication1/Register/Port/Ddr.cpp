
#include "Ddr.h"
 
 Ddr::Ddr()
 {
   
 }
 
 Ddr::Ddr(vuint8_t* ddrPtr)
 {
     this->setRegister(ddrPtr);
     this->setBits(0xFF);     
 }
 
 
 void Ddr::setDirection(Ddr::DdrPin_e pin,Ddr::DdrDirection_e dirStatus)
 {
     if(dirStatus == Ddr::DDR_INPUT) 
     {
        this->resetBit((BaseTypes::Bits_e)pin);
     }     
     else
     {
        this->setBit((BaseTypes::Bits_e)pin);             
     }     
 }
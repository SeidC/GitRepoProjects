
#include "Ddr.h"
 
 Ddr::Ddr(volatile uint8_t* ddrPtr)
 {
     setRegister(ddrPtr);
     
 }
 
 
 void Ddr::setDirection(BaseTypes::Bits_e bit, Ddr::Direction_e dirStatus)
 {
     if(dirStatus == INPUT) 
     {
        resetBit(bit);
     }     
     else
     {
        setBit(bit);
         
     }     
 }
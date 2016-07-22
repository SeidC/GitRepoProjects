
#include "Ddr.h"
 
 Ddr::Ddr(vuint8_t* ddrPtr)
 {
     setRegister(ddrPtr);
     setBits(0xFF);
     
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
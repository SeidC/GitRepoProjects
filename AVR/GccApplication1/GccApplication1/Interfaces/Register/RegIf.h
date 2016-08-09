/* 
* RegIf.h
*
* Created: 08.07.2016 21:44:29
* Author: AP02
*/


#ifndef __REGIF_H__
#define __REGIF_H__

#include "BaseTypes.h"


class RegIf : public BaseTypes
{
//parameter
private:
  

//functions
public:
    ~RegIf(){}
protected:
//Setter
	virtual void setRegister(volatile uint8_t *reg) {}               
	virtual void setBit(BaseTypes::Bits_e bit)      {} 
   virtual void setValue(uint8_t value)            {}              
	virtual void setBits(uint8_t bits)              {}               
	virtual void resetBit(BaseTypes::Bits_e bit)    {}               
   virtual void resetBits(uint8_t bits)            {}               
//Getter:    
   virtual uint8_t getBits(uint8_t bits)                           {return 0;}
   virtual BaseTypes::BitStatus_e getBit(uint8_t bit)              {return BaseTypes::BIT_LOW;}
   virtual BaseTypes::BitStatus_e getBit(BaseTypes::Bits_e bit)    {return BaseTypes::BIT_LOW;}
   virtual void getRegister( BaseTypes::Bit8Register_t* regPtr)    {}
   virtual uint16_t getValue(void)                                 {return 0;}
    
}; //RegIf

#endif //__REGIF_H__

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
    BitRegister_t register;

//functions
public:
    ~RegIf(){}
protected:
//Setter
	void setRegister(volatile uint8_t *reg)                 {register.byte = reg;}
	void setBit(BaseTypes::Bits_e bit)                      {SET_BIT(*register.byte,bit);}
	void setBits(uint8_t bits)                              {SET_BITS(*register.byte,bits);}
	void resetBit(BaseTypes::Bits_e bit)                    {RESET_BIT(*register.byte,bit);}
    void resetBits(uint8_t bits)                            {RESET_BITS(*register.byte,bits);}
//Getter:    
    uint8_t getBits(uint8_t bits);                          {return GET_BITS(*register.byte,bits);}
    BaseTypes::BitStatus_e getBit(BaseTypes::Bits_e bit);   {return (BaseTypes::BitStatus_e)GET_BIT(*register.byte,bit);}
    BaseTypes::BitRegister_t* getRegister(void);            {return &register;}
}; //RegIf

#endif //__REGIF_H__

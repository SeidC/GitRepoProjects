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
    BitRegister_t avrRegister;

//functions
public:
    ~RegIf(){}
protected:
//Setter
	void setRegister(volatile uint8_t *reg)                 {avrRegister.byte = reg;}
	void setBit(BaseTypes::Bits_e bit)                      {SET_BIT(*avrRegister.byte,bit);}
	void setBits(uint8_t bits)                              {SET_BITS(*avrRegister.byte,bits);}
	void resetBit(BaseTypes::Bits_e bit)                    {RESET_BIT(*avrRegister.byte,bit);}
    void resetBits(uint8_t bits)                            {RESET_BITS(*avrRegister.byte,bits);}
//Getter:    
    uint8_t getBits(uint8_t bits)                           {return GET_BITS(*avrRegister.byte,bits);}
    BaseTypes::BitStatus_e getBit(BaseTypes::Bits_e bit)    {return (BaseTypes::BitStatus_e)GET_BIT(*avrRegister.byte,bit);}
    BaseTypes::BitRegister_t* getRegister(void)             {return &avrRegister;}
}; //RegIf

#endif //__REGIF_H__

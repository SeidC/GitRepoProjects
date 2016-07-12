/*
 * RegIf8.h
 *
 * Created: 11.07.2016 22:17:38
 *  Author: AP
 */ 


#ifndef REGIF8_H_
#define REGIF8_H_
#include "RegIf.h"


class RegIf8 : public RegIf
{
    //parameter
    private:
    Bit8Register_t avrRegister;

    //functions
    public:
    ~RegIf8(){}
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
    void getRegister( BaseTypes::Bit8Register_t* regPtr)    {regPtr =  &avrRegister;}


};




#endif /* REGIF8_H_ */
/*
 * RegIfUart.h
 *
 * Created: 12.07.2016 23:10:31
 *  Author: AP
 */ 


#ifndef REGIFUBRR_H_
#define REGIFUBRR_H_
#include "RegIf.h"


class RegIfUbrr : public RegIf
{
    //parameter
    private:
    Bit8Register_t avrRegister;

    //functions
    public:
    ~RegIfUbrr(){}
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





#endif /* REGIFUART_H_ */
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
    void setRegister(vuint8_t *reg)                 {avrRegister.byte = reg;}
    void getRegister( BaseTypes::Bit8Register_t* regPtr)    {regPtr =  &avrRegister;}    
    void setBits(uint8_t bits)                              {SET_BITS(*avrRegister.byte,bits);}   
    void resetBits(uint8_t bits)                            {RESET_BITS(*avrRegister.byte,bits);}
    BaseTypes::BitStatus_e getBit(BaseTypes::Bits_e bit)    {return (BaseTypes::BitStatus_e)GET_BIT(*avrRegister.byte,bit);}
    BaseTypes::BitStatus_e getBit(uint8_t bit)              {return (BaseTypes::BitStatus_e)GET_BIT(*avrRegister.byte,bit);}
    protected:
    //Setter
    void setBit(BaseTypes::Bits_e bit)                      {SET_BIT(*avrRegister.byte,bit);}
    void setValue(uint8_t value)                            {*avrRegister.byte = value;}
    void resetBit(BaseTypes::Bits_e bit)                    {RESET_BIT(*avrRegister.byte,bit);}
    //Getter:
    uint8_t getBits(uint8_t bits)                           {return GET_BITS(*avrRegister.byte,bits);}
    uint16_t getValue(void)                                 {return (uint16_t)*avrRegister.byte;};

};




#endif /* REGIF8_H_ */
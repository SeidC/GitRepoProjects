/*
 * RegIf16.h
 *
 * Created: 11.07.2016 22:17:54
 *  Author: AP
 */ 


#ifndef REGIF16_H_
#define REGIF16_H_
#include "RegIf.h"


class RegIf16 : public RegIf
{
    //parameter
    private:
    Bit16Register_t avrRegister;

    //functions
    public:
    ~RegIf16(){}
     uint16_t getValue(void)                                {return *avrRegister.byte;}
     void setValue(uint16_t value)                          {*avrRegister.byte = value;}
     void setRegister(vuint16_t *reg)                       {avrRegister.byte = reg;}
     void getRegister(BaseTypes::Bit16Register_t* regPtr)   {regPtr =  &avrRegister;}
        
    //Setter
  
    void setBit(BaseTypes::Bits_e bit)                      {SET_BIT(*avrRegister.byte,bit);}
    void setBit(uint16_t bit)                               {SET_BIT(*avrRegister.byte,bit);}
    void setBits(uint8_t bits)                              {SET_BITS(*avrRegister.byte,bits);}
    void resetBit(BaseTypes::Bits_e bit)                    {RESET_BIT(*avrRegister.byte,bit);}
    void resetBit(uint16_t bit)                             {RESET_BIT(*avrRegister.byte,bit);}
    void resetBits(uint8_t bits)                            {RESET_BITS(*avrRegister.byte,bits);}
    //Getter:
    uint8_t getBits(uint8_t bits)                           {return GET_BITS(*avrRegister.byte,bits);}
    BaseTypes::BitStatus_e getBit(BaseTypes::Bits_e bit)    {return (BaseTypes::BitStatus_e)GET_BIT(*avrRegister.byte,bit);}
    BaseTypes::BitStatus_e getBit(uint8_t bit)              {return (BaseTypes::BitStatus_e)GET_BIT(*avrRegister.byte,bit);}

};



#endif /* REGIF16_H_ */
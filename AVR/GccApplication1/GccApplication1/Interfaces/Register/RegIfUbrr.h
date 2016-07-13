/*
 * RegIfUart.h
 *
 * Created: 12.07.2016 23:10:31
 *  Author: AP
 */ 


#ifndef REGIFUBRR_H_
#define REGIFUBRR_H_
#include "RegIf.h"

#define SET_UBRR_BIT(byte,reg,bit)                  \
        {                                           \
            if(byte == BaseTypes::HIGHER_BYTE)      \
                SET_BIT(*reg.UbrrH.byte,bit);       \
            else                                    \
                SET_BIT(*reg.UbrrL.byte,bit);       \    
        }                                           \
        
        
#define SET_UBRR_BITS(byte,reg,bits)                \
        {                                           \
            if(byte == BaseTypes::HIGHER_BYTE)      \
                SET_BITS(*reg.UbrrH.byte,bits);     \
            else                                    \
                SET_BITS(*reg.UbrrL.byte,bits);     \
        }                                           \
        
#define RESET_UBRR_BIT(byte,reg,bit)                \
        {                                           \
            if(byte == BaseTypes::HIGHER_BYTE)      \
                RESET_BIT(*reg.UbrrH.byte,bit);     \
            else                                    \
                RESET_BIT(*reg.UbrrL.byte,bit);     \
        }                                           \


#define RESET_UBRR_BITS(byte,reg,bits)                \
{                                           \
    if(byte == BaseTypes::HIGHER_BYTE)      \
    RESET_BITS(*reg.UbrrH.byte,bits);     \
    else                                    \
    RESET_BITS(*reg.UbrrL.byte,bits);     \
}                                           \


#define GET_UBRR_BIT(byte,reg,bit,retVal)                   \
        {                                                   \
            if(byte == BaseTypes::HIGHER_BYTE)              \
               retVal = GET_BIT(*reg.UbrrH.byte,bit);      \
            else                                            \
               retVal = GET_BIT(*reg.UbrrL.byte,bit);      \
        }                                                   \          
        
#define GET_UBRR_BITS(byte,reg,bits,retVal)                 \              
        {                                                   \
            if(byte == BaseTypes::HIGHER_BYTE)              \
            retVal =  GET_BITS(*reg.UbrrH.byte,bits);       \
            else                                            \
            retVal = GET_BITS(*reg.UbrrL.byte,bits);        \
        }                                                   \



class RegIfUbrr : public RegIf
{
    //types
    public:
       
    //parameter
    private:
    UbrrRegister_t avrRegister;

    //functions
    public:
    ~RegIfUbrr(){}
    protected:
    //Setter
    void setRegister(volatile uint8_t *reg1, volatile uint8_t* reg2)                 {avrRegister.UbrrH.byte = reg1; 
                                                                                      avrRegister.UbrrL.byte = reg2;}
                                                                                      
    void setBit(ByteType_e byte, BaseTypes::Bits_e bit)                              {SET_UBRR_BIT(byte,avrRegister,bit);}
    void setBits(ByteType_e byte, uint8_t bits)                                      {SET_UBRR_BITS(byte,avrRegister,bits);}
    void resetBit(ByteType_e byte, BaseTypes::Bits_e bit)                            {RESET_UBRR_BIT(byte,avrRegister,bit);}
    void resetBits(ByteType_e byte, uint8_t bits)                                    {RESET_UBRR_BITS(byte,avrRegister,bits);}
    //Getter:                                                                        
    uint8_t getBits(ByteType_e byte, uint8_t bits)                                   {uint8_t ret;
                                                                                      GET_UBRR_BITS(byte,avrRegister,bits,ret)
                                                                                      return ret;};
           
    BaseTypes::BitStatus_e getBit(ByteType_e byte, BaseTypes::Bits_e bit)            {uint8_t ret;
                                                                                      GET_UBRR_BIT(byte,avrRegister,bit,ret)
                                                                                      return (BaseTypes::BitStatus_e)ret;};
    void getRegister(ByteType_e byte, BaseTypes::Bit8Register_t* regPtr)             {byte == BaseTypes::HIGHER_BYTE ? regPtr = &avrRegister.UbrrH :
                                                                                                                       regPtr = &avrRegister.UbrrL;}


};





#endif /* REGIFUART_H_ */
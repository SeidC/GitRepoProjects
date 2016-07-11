/*
 * BaseTypes.h
 *
 * Created: 08.07.2016 20:47:45
 *  Author: AP02
 */ 


#ifndef BASETYPES_H_
#define BASETYPES_H_

#include <stdint.h>

#define SET_BIT(value,bit)                                          \
        (value |= (1 << bit))


#define SET_BITS(value,bits)                                        \
        (value |= bits)

#define RESET_BIT(value,bit)                                        \
        (value &= ~(1 << bit))
        
#define RESET_BITS(value,bits)                                      \
        (value &= ~(bits))
        
#define GET_BIT(value,bit)                                          \
        ((value & bit) >> bit)

#define GET_BITS(value,bits)                                        \
        (value & bits)



class BaseTypes 
{
    public:    
    struct Bits_s
    {
        uint8_t bit0             :1;
        uint8_t bit1             :1;
        uint8_t bit2             :1;
        uint8_t bit3             :1;
        uint8_t bit4             :1;
        uint8_t bit5             :1;
        uint8_t bit6             :1;
        uint8_t bit7             :1;    
    };
    
    enum Bits_e
    {
        BIT_0                   = 0,
        BIT_1                   = 1,
        BIT_2                   = 2,
        BIT_3                   = 3,
        BIT_4                   = 4,
        BIT_5                   = 5,
        BIT_6                   = 6,
        BIT_7                   = 7,        
    };
    
    enum BitStatus_e    
    {
        BIT_LOW                 = 0,
        BIT_HIGH                = 1,  
    };    
    union BitRegister_t
    {
        struct   Bits_s * bits;
        volatile uint8_t* byte;
    };
    
    typedef uint8_t boolean;
};



#endif /* BASETYPES_H_ */
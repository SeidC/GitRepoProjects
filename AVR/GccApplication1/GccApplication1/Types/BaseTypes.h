/*
 * BaseTypes.h
 *
 * Created: 08.07.2016 20:47:45
 *  Author: AP02
 */ 


#ifndef BASETYPES_H_
#define BASETYPES_H_

#include <stdint.h>
#include <avr/io.h>

typedef volatile uint8_t vuint8_t;


typedef struct
{
    vuint8_t* tcnt;
    vuint8_t* tccr;
    vuint8_t* ocr;
    vuint8_t* timsk;
    vuint8_t* tifr;
    vuint8_t* assr;
    
}Timer8Config_t;



typedef struct
{
    vuint8_t* port;
    vuint8_t* pin;
    vuint8_t* ddr;
    
}PortConfig_t;




#define SET_BIT(value,bit)                                          \
        (value |= (1 << bit))


#define SET_BITS(value,bits)                                        \
        (value |= bits)

#define RESET_BIT(value,bit)                                        \
        (value &= ~(1 << bit))
        
#define RESET_BITS(value,bits)                                      \
        (value &= ~(bits))
        
#define GET_BIT(value,bit)                                          \
        ((value & (bit+1)) >> bit )

#define GET_BITS(value,bits)                                        \
        (value & bits)



class BaseTypes 
{
    public:    
    struct Bits8_s
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
    
    
    struct Bits16_s
    {
        uint8_t bit0             :1;
        uint8_t bit1             :1;
        uint8_t bit2             :1;
        uint8_t bit3             :1;
        uint8_t bit4             :1;
        uint8_t bit5             :1;
        uint8_t bit6             :1;
        uint8_t bit7             :1;
        uint8_t bit8             :1;
        uint8_t bit9             :1;
        uint8_t bit10            :1;
        uint8_t bit11            :1;
        uint8_t bit12            :1;
        uint8_t bit13            :1;
        uint8_t bit14            :1;
        uint8_t bit15            :1;
    };
    
    enum Toggle_e
    {
        ENABLE,
        DISABLE    
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
    union Bit8Register_t
    {
        struct   Bits8_s* bits;
        volatile uint8_t* byte;
    };
    
    
     union Bit16Register_t
     {
         struct   Bits16_s* bits;
         volatile uint16_t* byte;
     };
     
     
    struct UbrrRegister_t
    {
        Bit8Register_t UbrrH;
        Bit8Register_t UbrrL;
    };
    
     enum ByteType_e
     {
         HIGHER_BYTE,
         LOWER_BYTE
     };
    typedef uint8_t boolean;
};



#endif /* BASETYPES_H_ */
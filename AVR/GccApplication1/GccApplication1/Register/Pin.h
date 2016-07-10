/* 
* Pin.h
*
* Created: 08.07.2016 20:59:25
* Author: AP02
*/


#ifndef __PIN_H__
#define __PIN_H__
#include "BaseTypes.h"
#include "RegIf.h"

class Pin : public BaseTypes , public RegIf
{
//variables
public:
    enum Pin_e
    {
        PIN_0           = 0x00,
        PIN_1           = 0x01,
        PIN_2           = 0x02,
        PIN_3           = 0x03,
        PIN_4           = 0x04,    
        PIN_5           = 0x05,
        PIN_6           = 0x06,
        PIN_7           = 0x07,
    };
    
protected:
private:
    BitRegister_t pin;

//functions
public:
	Pin();
	~Pin();
    BaseTypes::BitStatus_e getPin(Pin::Pin_e pin);
    
protected:
     void setRegister(volatile uint8_t *reg);
     void setBit(BaseTypes::Bits_e bit);
     void setBits(uint8_t bits);
     BaseTypes::BitRegister_t* getRegister(void);
private:
	Pin( const Pin &c );
	Pin& operator=( const Pin &c );

}; //Pin

#endif //__PIN_H__

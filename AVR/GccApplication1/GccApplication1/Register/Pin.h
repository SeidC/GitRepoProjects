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
protected:
private:
    BitRegister_t pin;

//functions
public:
	Pin();
	~Pin();
    void setRegister(volatile uint8_t *reg);
    void setBit(BaseTypes::Bits_e bit);
    void setBits(uint8_t bits);
    BaseTypes::BitRegister_t* getRegister(void);
   
protected:
private:
	Pin( const Pin &c );
	Pin& operator=( const Pin &c );

}; //Pin

#endif //__PIN_H__

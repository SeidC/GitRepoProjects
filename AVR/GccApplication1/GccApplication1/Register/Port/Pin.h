/* 
* Pin.h
*
* Created: 08.07.2016 20:59:25
* Author: AP02
*/


#ifndef __PIN_H__
#define __PIN_H__
#include "BaseTypes.h"
#include "RegIf8.h"


class Pin : public RegIf8
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

//functions
public:
	Pin(vuint8_t* pinPtr);
	~Pin();
    BaseTypes::BitStatus_e getPin(Pin::Pin_e pin);
    
private:
	//Pin( const Pin &c );
	Pin& operator=( const Pin &c );

}; //Pin

#endif //__PIN_H__

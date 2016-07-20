/* 
* Port.h
*
* Created: 08.07.2016 20:59:14
* Author: AP02
*/


#ifndef __PORT_H__
#define __PORT_H__
#include "RegIf8.h"

class Port : public RegIf8
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
    
    enum PinStatus_e
    {
        PIN_LOW,    
        PIN_HIGH,        
    };
    
    enum PullUpStatus_e
    {
        PULL_UP_DISABLE,
        PULL_UP_ENABLE    
    };
protected:

//functions
public:
	Port(volatile uint8_t* portPtr);
	~Port();
    void setPin(Pin_e pin,PinStatus_e status);
    void setPinsHigh(uint8_t pinMask);
    void setPinsLow(uint8_t pinMask);
    void setPullUp(Pin_e pin,PullUpStatus_e status);
    
private:
	Port( const Port &c );
	Port& operator=( const Port &c );

}; //Port

#endif //__PORT_H__

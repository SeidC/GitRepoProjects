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

    enum Port_e
    {
        PORT_0           = 0x00,
        PORT_1           = 0x01,
        PORT_2           = 0x02,
        PORT_3           = 0x03,
        PORT_4           = 0x04,
        PORT_5           = 0x05,
        PORT_6           = 0x06,
        PORT_7           = 0x07,
    };
    
    enum PortStatus_e
    {
        PORT_LOW,    
        PORT_HIGH,        
    };
    
    enum PullUpStatus_e
    {
        PULL_UP_DISABLE,
        PULL_UP_ENABLE    
    };
protected:

//functions
public:
	Port(vuint8_t* portPtr);
	~Port();
    void setPin(Port_e pin,PortStatus_e status);
    void setPinsHigh(uint8_t pinMask);
    void setPinsLow(uint8_t pinMask);
    void setPullUp(Pin_e pin,PullUpStatus_e status);
    
private:
	Port( const Port &c );
	Port& operator=( const Port &c );

}; //Port

#endif //__PORT_H__

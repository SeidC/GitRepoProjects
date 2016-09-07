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
    
protected:

//functions
public:
   Port();
	Port(vuint8_t* portPtr);
	~Port();
    void setPort(Port_e pin,PortStatus_e status);
    void setPortsHigh(uint8_t pinMask);
    void setPortsLow(uint8_t pinMask);
    PortStatus_e getPort(Port::Port_e port);
      
private:
	Port( const Port &c );
	Port& operator=( const Port &c );

}; //Port

#endif //__PORT_H__

/* 
* Io.h
*
* Created: 08.07.2016 20:04:40
* Author: AP02
*/


#ifndef __IO_H__
#define __IO_H__

#include <avr/io.h>
#include <stdint.h>
#include "AVRConfig.h"
#include "BaseTypes.h"
#include "Ddr.h"
#include "Port.h"
#include "Pin.h"


class Io : public BaseTypes
{
//types    
public: 

//variables
public:
protected:

private:
    Pin pin;
    Port port;
    Ddr ddr; 

//functions
public:
	Io(PortConfig_t* portConfig);
	~Io();
   void setDirection(Port::Port_e port, Ddr::Direction_e dirStatus);
   Pin::PinStatus_e getPin(Pin::Pin_e pin);
   void setPin(Pin_e pin,Pin_e status);
   void setPinsHigh(uint8_t pinMask);
   void setPinsLow(uint8_t pinMask);
   void setPullUp(Pin_e pin,PullUpStatus_e status);
protected:
private:
	Io( const Io &c );
	Io& operator=( const Io &c );

}; //Io

#endif //__IO_H__

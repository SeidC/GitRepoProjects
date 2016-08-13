/* 
* IoIf.h
*
* Created: 13.08.2016 12:22:46
* Author: AP02
*/


#ifndef __IOIF_H__
#define __IOIF_H__

#include "BaseTypes.h"


class IoIf : BaseTypes
{
//functions
public:
	virtual ~IoIf(){}
   virtual void setDirection(BaseTypes::Bits_e bit, Direction_e dirStatus) {};
   virtual BaseTypes::BitStatus_e getPin(Pin::Pin_e pin) {};
   virtual void setPin(Pin_e pin,PinStatus_e status) {};
   virtual void setPinsHigh(uint8_t pinMask) {};
   virtual void setPinsLow(uint8_t pinMask) {};
   virtual void setPullUp(Pin_e pin,PullUpStatus_e status) {};
	
   

}; //IoIf

#endif //__IOIF_H__

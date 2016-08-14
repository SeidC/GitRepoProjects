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
   enum IoDirection_e
   {
      IO_INPUT,
      IO_OUTPUT,   
   };
   
   enum IoPin_e
   {
      IO_PIN_0 = 0x00,
      IO_PIN_1 = 0x01,
      IO_PIN_2 = 0x02,
      IO_PIN_3 = 0x03,
      IO_PIN_4 = 0x04,
      IO_PIN_5 = 0x05,
      IO_PIN_6 = 0x06,
      IO_PIN_7 = 0x07,   
   };
   
   enum IoStatus_e
   {
      IO_LOW            = 0x00,
      IO_HIGH   
   };

  
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
   void setDirection(IoPin_e io, IoDirection_e ioStatus);
   IoDirection_e getDirection(IoPin_e io);
   IoStatus_e getIo(IoPin_e io);
   void setIo(IoPin_e,IoStatus_e ioStatus);
   void setPullUp(IoPin_e io,IoStatus_e ioPullup);
protected:
private:
	Io( const Io &c );
	Io& operator=( const Io &c );

}; //Io

#endif //__IO_H__

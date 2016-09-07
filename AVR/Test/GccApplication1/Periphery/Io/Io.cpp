/* 
* Io.cpp
*
* Created: 08.07.2016 20:04:40
* Author: AP02
*/


#include "Io.h"

// default constructor
Io::Io(PortConfig_t* portConfig)
{
   ddr.setRegister(portConfig->ddr);
   port.setRegister(portConfig->port);
   pin.setRegister(portConfig->pin);
} //Io

// default destructor
Io::~Io() 
{
    
} //~Io



void Io::setDirection(IoPin_e io, IoDirection_e ioStatus)
{
   ddr.setDirection((Ddr::DdrPin_e)io,(Ddr::DdrDirection_e)ioStatus);
}
 
Io::IoDirection_e Io::getDirection(Io::IoPin_e io)
{
   return (Io::IoDirection_e)ddr.getDirection((Ddr::DdrPin_e)io);
}
 
Io::IoStatus_e Io::getIo(Io::IoPin_e io)
{
   return (Io::IoStatus_e) pin.getPin((Pin::Pin_e) io); 
}
 
void Io::setIo(Io::IoPin_e io,Io::IoStatus_e ioStatus)
{
   port.setPort((Port::Port_e) io,(Port::PortStatus_e)ioStatus);
}
 
void Io::setPullUp(Io::IoPin_e io,Io::IoStatus_e ioPullup)
{
   if(ddr.getDirection((Ddr::DdrPin_e)io) == Ddr::DDR_INPUT)
   {
      port.setPort((Port::Port_e)io,(Port::PortStatus_e)ioPullup);  
   }
}
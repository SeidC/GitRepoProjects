/* 
* Io.cpp
*
* Created: 08.07.2016 20:04:40
* Author: AP02
*/


#include "Io.h"

// default constructor
Io::Io(PortConfig_t* portConfig) : Port(portConfig->port) , Ddr(portConfig->ddr), Pin(portConfig->pin)
{
    
} //Io

// default destructor
Io::~Io() 
{
    
} //~Io

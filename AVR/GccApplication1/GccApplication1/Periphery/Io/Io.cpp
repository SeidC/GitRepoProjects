/* 
* Io.cpp
*
* Created: 08.07.2016 20:04:40
* Author: AP02
*/


#include "Io.h"

// default constructor
Io::Io(volatile uint8_t* port)
        : Port(port), Ddr(port - 1 ), Pin(port - 2)
{
    
} //Io

// default destructor
Io::~Io() 
{
    
} //~Io

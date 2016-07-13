/* 
* Io.cpp
*
* Created: 08.07.2016 20:04:40
* Author: AP02
*/


#include "Io.h"

// default constructor
Io::Io(volatile uint8_t* port) : Port(port) , Ddr(port - DDR_ADR_CNT ), Pin(port - PIN_ADR_CNT)
{
    
} //Io

// default destructor
Io::~Io() 
{
    
} //~Io

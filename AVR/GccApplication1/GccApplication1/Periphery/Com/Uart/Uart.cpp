/* 
* Uart.cpp
*
* Created: 10.07.2016 14:16:32
* Author: AP02
*/


#include "Uart.h"

// default constructor
Uart::Uart(volatile uint8_t* udrPtr) : 
    Udr(udrPtr), Ucsra(udrPtr -1), Ucsrb(udrPtr-2) 
{
    
} //Uart

// default destructor
Uart::~Uart()
{
    
} //~Uart

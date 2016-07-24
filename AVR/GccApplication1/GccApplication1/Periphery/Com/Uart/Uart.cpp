/* 
* Uart.cpp
*
* Created: 10.07.2016 14:16:32
* Author: AP02
*/


#include "Uart.h"


// default constructor
Uart::Uart(UartConfig_t* uartConfig) : 
    Ubrr(uartConfig->ubrrh,uartConfig->ubrrl),
    Ucsra(uartConfig->ucsra),
    Ucsrb(uartConfig->ucsrb),
    Ucsrc(uartConfig->ucsrc),
    Udr(uartConfig->udr)     
{
    
} //Uart

// default destructor
Uart::~Uart()
{
    
} //~Uart

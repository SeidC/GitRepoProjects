/* 
* Uart.cpp
*
* Created: 10.07.2016 14:16:32
* Author: AP02
*/


#include "Uart.h"


// default constructor
Uart::Uart(UartConfig_t* uartConfig) : 
    Udr(uartConfig->udr), 
    Ucsra(uartConfig->ucsra), 
    Ucsrb(uartConfig->ucsrb),
    Ucsrc(uartConfig->ucsrc),
    Ubrr(uartConfig->ubrrh,uartConfig->ubrrl)
{
    
} //Uart

// default destructor
Uart::~Uart()
{
    
} //~Uart

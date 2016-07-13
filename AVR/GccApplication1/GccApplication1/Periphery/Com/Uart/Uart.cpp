/* 
* Uart.cpp
*
* Created: 10.07.2016 14:16:32
* Author: AP02
*/


#include "Uart.h"

// default constructor
Uart::Uart(volatile uint8_t* udrPtr) : 
    Udr(udrPtr), 
    Ucsra(udrPtr - UCSRA_ADR_CNT), 
    Ucsrb(udrPtr-UCSRB_ADR_CNT),
    Ucsrc(udrPtr - UDSRC_ADR_CNT),
    Ubrr(udrPtr - UBRRH_ADR_CNT,udrPtr - UBRRL_ADR_CNT)
{
    
} //Uart

// default destructor
Uart::~Uart()
{
    
} //~Uart

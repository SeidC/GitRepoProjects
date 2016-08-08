/*
 * AVRConfig.cpp
 *
 * Created: 23.07.2016 00:11:06
 *  Author: AP
 */ 

#include "AVRConfig.h"



Timer8Config_t timer0Cfg = 
{
     TIMER0_8BIT,
     &TCNT0,
     &TCCR0,
     &OCR0,
     NULL,
     NULL,
     NULL,
};
    
    
Timer8Config_t timer2Cfg =
{
    TIMER2_8_BIT_ASYNC,
    &TCNT2,
    &TCCR2,
    &OCR2,
    NULL,
    NULL,
    &ASSR,
};


PortConfig_t portACfg = 
{
   &PORTA,
   &PINA,
   &DDRA,
     
};

PortConfig_t portBCfg =
{
    &PORTB,
    &PINB, 
    &DDRB, 
    
};

PortConfig_t portCCfg =
{
    &PORTC,
    &PINC ,
    &DDRC ,
};

PortConfig_t portDCfg =
{
    &PORTD,
    &PIND ,
    &DDRD ,
    
};


UartConfig_t uartCfg =
{
    &UDR,
    &UCSRA,
    &UCSRB,
    &UCSRC,
    &UBRRL,
    &UBRRH,
};


void * operator new(size_t n)
{

}

void operator delete(void * p) // or delete(void *, std::size_t)
{

}
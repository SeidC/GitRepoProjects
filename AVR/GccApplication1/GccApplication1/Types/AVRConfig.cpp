/*
 * AVRConfig.cpp
 *
 * Created: 23.07.2016 00:11:06
 *  Author: AP
 */ 

#include "AVRConfig.h"



Timer8Config_t timer0Cfg = 
{
     &TCNT0,
     &TCCR0,
     &OCR0,
     NULL,
     NULL,
     NULL,
};
    
    
Timer8Config_t timer2Cfg =
{
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
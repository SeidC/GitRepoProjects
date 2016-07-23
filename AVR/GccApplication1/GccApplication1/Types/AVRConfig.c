/*
 * AVRConfig.cpp
 *
 * Created: 23.07.2016 00:11:06
 *  Author: AP
 */ 

#include "AVRConfig.h"



Timer8Config_t timer0Cfg = 
{
    .tcnt  = &TCNT0,
    .tccr  = &TCCR0,
    .ocr   = &OCR0,
    .tifr  = NULL,
    .assr  = NULL,
    .timsk = NULL,
};
    
    
Timer8Config_t timer2Cfg =
{
    .tcnt  = &TCNT2,
    .tccr  = &TCCR2,
    .ocr   = &OCR2,
    .tifr  = NULL,
    .timsk = NULL,
    .assr  = &ASSR,
};


PortConfig_t portACfg = 
{
    .port = &PORTA,
    .ddr  = &DDRA,
    .pin  = &PINA,  
};

PortConfig_t portBCfg =
{
    .port = &PORTB,
    .ddr  = &DDRB, 
    .pin  = &PINB, 
};

PortConfig_t portCCfg =
{
    .port = &PORTC,
    .ddr  = &DDRC ,
    .pin  = &PINC ,
};

PortConfig_t portDCfg =
{
    .port = &PORTD,
    .ddr  = &DDRD ,
    .pin  = &PIND ,
};


UartConfig_t uartCfg =
{
    .udr    = &UDR,
    .ucsra  = &UCSRA,
    .ucsrb  = &UCSRB,
    .ucsrc  = &UCSRC,
    .ubrrl  = &UBRRL,
    .ubrrh  = &UBRRH,
};
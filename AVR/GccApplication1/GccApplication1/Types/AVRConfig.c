/*
 * AVRConfig.cpp
 *
 * Created: 23.07.2016 00:11:06
 *  Author: AP
 */ 

#include "AVRConfig.h"



Timer8Config_t timer0 = 
    {
        .tcnt  = &TCNT0,
        .tccr  = &TCCR0,
        .ocr   = &OCR0,
        .tifr  = NULL,
        .assr  = NULL,
        .timsk = NULL,
    };
    
    
Timer8Config_t timer2 =
{
    .tcnt  = &TCNT2,
    .tccr  = &TCCR2,
    .ocr   = &OCR2,
    .tifr  = NULL,
    .timsk = NULL,
    .assr  = &ASSR,
};


PortConfig_t portA = 
{
    .port = &PORTA,
    .ddr  = &DDRA,
    .pin  = &PINA,  
};

PortConfig_t portB =
{
    .port = &PORTB,
    .ddr  = &DDRB, 
    .pin  = &PINB, 
};

PortConfig_t portC =
{
    .port = &PORTC,
    .ddr  = &DDRC ,
    .pin  = &PINC ,
};

PortConfig_t portD =
{
    .port = &PORTD,
    .ddr  = &DDRD ,
    .pin  = &PIND ,
};

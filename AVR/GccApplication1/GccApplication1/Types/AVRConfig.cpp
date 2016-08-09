/*
 * AVRConfig.cpp
 *
 * Created: 23.07.2016 00:11:06
 *  Author: AP
 */ 

#include "AVRConfig.h"



const Timer8Config_t timer0Cfg = 
{
     {
         TIMER0_8BIT,
         0xff, 
     },
     &TCNT0,
     &TCCR0,
     &OCR0,
     &TIMSK,
     &TIFR,
     NULL,
};
    
    
const Timer8Config_t timer2Cfg =
{
    {
      TIMER2_8_BIT_ASYNC,
      0xff,
    },    
    &TCNT2,
    &TCCR2,
    &OCR2,
    &TIMSK,
    &TIFR,
    &ASSR,
};

const Timer16Config_t timer1Cfg = 
{
   {
      TIMER1_16_BIT,
      0xffff,
   },
   &TCNT1,
   &TCCR1A,
   &TCCR1B,
   &OCR1A,
   &OCR1B,
   &ICR1,
   &TIMSK,
   &TIFR,
   NULL,
};


const PortConfig_t portACfg = 
{
   &PORTA,
   &PINA,
   &DDRA,
     
};

const PortConfig_t portBCfg =
{
    &PORTB,
    &PINB, 
    &DDRB, 
    
};

const PortConfig_t portCCfg =
{
    &PORTC,
    &PINC ,
    &DDRC ,
};

const PortConfig_t portDCfg =
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
   return NULL;
}

void operator delete(void * p) // or delete(void *, std::size_t)
{

}
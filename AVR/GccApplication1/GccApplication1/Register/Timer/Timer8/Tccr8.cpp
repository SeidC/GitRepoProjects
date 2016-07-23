/* 
* Tccr8.cpp
*
* Created: 17.07.2016 13:11:56
* Author: AP02
*/


#include "Tccr8.h"

// default constructor
Tccr8::Tccr8()
{
} //Tccr8

// default destructor
Tccr8::~Tccr8()
{
} //~Tccr8


 void Tccr8::setTimerMode(Tccr8::TimerMode_e tmode)
 {
    BaseTypes::Bits_e bits;
    
    if(tmode != TIMER_NORMAL)
    {
        bits = (BaseTypes::Bits_e)tmode;
        setBits(bits);
    }
    else
    {   
        bits = BaseTypes::BIT_3 | BaseTypes::BIT_6;
        resetBits(bits);
    }
    return;
 }
 
 
 void Tccr8::setOutputMode(Tccr8::OutputMode_e omode)
 {
     BaseTypes::Bits_e bits;
     if(omode == OC_PIN_DISCONNECTED)
     {
         bits = BaseTypes::BIT_4 | BaseTypes::BIT_5;
         resetBits(bits); 
     }
     else
     {
         bits = (BaseTypes::Bits_e)(omode << ((uint8_t) BaseTypes::BIT_4));
         setBits(bits);
     }
     return;
 }
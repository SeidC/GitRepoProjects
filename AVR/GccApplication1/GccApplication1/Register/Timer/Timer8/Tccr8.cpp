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
     switch(tmode)
     {
         case Tccr8::TIMER_NORMAL:
            resetBits(BaseTypes::BIT_3|BaseTypes::BIT_6);
         break;
         case Tccr8::PHASE_CORRECT_PWM:
            setBit(BaseTypes::BIT_6);
            resetBit(BaseTypes::BIT_3);
         break;
         case Tccr8::CLEAR_ON_COMPARE:
            resetBit(BaseTypes::BIT_6);
            setBit(BaseTypes::BIT_3);
         break;
         case Tccr8::FAST_PWM:
            setBits(BaseTypes::BIT_6|BaseTypes::BIT_3);
         break;
         default:
             resetBits(BaseTypes::BIT_6|BaseTypes::BIT_3);
         break;
     }
 }
 
 
 void Tccr8::setOutputMode(Tccr8::OutputMode_e omode)
 {
     
 }
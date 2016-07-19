/* 
* Tcrr8.cpp
*
* Created: 17.07.2016 13:11:56
* Author: AP02
*/


#include "Tcrr8.h"

// default constructor
Tcrr8::Tcrr8()
{
} //Tcrr8

// default destructor
Tcrr8::~Tcrr8()
{
} //~Tcrr8


 void Tcrr8::setMode(Tcrr8::Mode_e mode)
 {
     
     uint8_t bits;
     switch(mode)
     {
         case Tcrr8::TIMER_NORMAL:
            setBits(WGM00|WGM01);
         break;
         case Tcrr8::PHASE_CORRECT_PWM:
            setBit((BaseTypes::Bits_e)WGM00);
            resetBit((BaseTypes::Bits_e)WGM01);
         break;
         case Tcrr8::CLEAR_ON_COMPARE:
            resetBit((BaseTypes::Bits_e)WGM00);
            setBit((BaseTypes::Bits_e)WGM01);
         break;
         case Tcrr8::FAST_PWM:
            setBits(WGM00|WGM01);
         break;
         default:
             resetBits(WGM00|WGM01);
         break;
     }
 }
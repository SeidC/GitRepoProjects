/* 
* Tccr8.cpp
*
* Created: 17.07.2016 13:11:56
* Author: AP02
*/


#include "Tccr8.h"

// default constructor
Tccr8::Tccr8(TimerType_t timerType,vuint8_t* tccrPtr)
{
    setRegister(tccrPtr);
    setType(timerType);
} //Tccr8

// default destructor
Tccr8::~Tccr8()
{
} //~Tccr8


 void Tccr8::setTimerMode(Tccr8::TimerMode_e tmode)
 {
    uint8_t bits;
    
    if(tmode != TIMER_NORMAL)
    {
        bits = (BaseTypes::Bits_e)tmode;
        setBits(bits);
    }
    else
    {   
        bits = (uint8_t)(BaseTypes::BIT_3 | BaseTypes::BIT_6);
        resetBits((BaseTypes::Bits_e)bits);
    }
    return;
 }
 
 
 void Tccr8::setOutputMode(Tccr8::OutputMode_e omode)
 {
    uint8_t bits;
     if(omode == OC_PIN_DISCONNECTED)
     {
         bits = (uint8_t)(BaseTypes::BIT_4 | BaseTypes::BIT_5);
         resetBits(bits); 
     }
     else
     {
         bits = (BaseTypes::Bits_e)(omode << ((uint8_t) BaseTypes::BIT_4));
         setBits((BaseTypes::Bits_e)bits);
     }
     return;
 }
 
 
  void Tccr8::toggleTimer(Toggle_e status)
  {
      Prescaler_e prescaler;
      if(status == BaseTypes::ENABLE)
      {
            prescaler = getPreScaler();
            //setBits(prescaler);           
      }
      else
      {
         //prescaler = getBits();   
         setPreScaler(prescaler);
      }
      return;
  }
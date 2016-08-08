/* 
* Timer8.cpp
*
* Created: 17.07.2016 13:42:23
* Author: AP02
*/


#include "Timer8.h"

// default constructor
Timer8::Timer8(Timer8Config_t * timerCfg)
{
   
  
} //Timer8

// default destructor
Timer8::~Timer8()
{
} //~Timer8




void Timer8::setOutputCompare(uint8_t rawValue)
{
   ocr.setOutputCompare(rawValue);
}

uint16_t Timer8::getOutputCompare(void)
{
   return ocr.getOutputCompare();

}

Timer8::StdReturn_e Timer8::setTimerMode(Tccr8::TimerMode_e tmode)
{
    
}

void Timer8::setOutputMode(Tccr8::OutputMode_e omode)
{
   tccr.setOutputMode(omode);
}

void Timer8::setPreScaler(Tccr8::Prescaler_e prescaler)
{

}

void Timer8::toggleTimer(BaseTypes::Toggle_e status)
{
   tccr.toggleTimer(status);
}

uint16_t Timer8::getTime(void)
{
   return tcnt.getTime();
}
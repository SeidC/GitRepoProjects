/* 
* Timer16.cpp
*
* Created: 17.07.2016 13:43:07
* Author: AP02
*/


#include "Timer16.h"
Timer16::Timer16()
{
   
}

// default constructor
Timer16::Timer16(Timer16Config_t *config)
{
   setConfig(config);
    
} //Timer16

// default destructor
Timer16::~Timer16()
{
} //~Timer16


void Timer16::setConfig(Timer16Config_t *config)
{
   tcnt.setRegister(config->tcnt);
   tccr.setTccrRegister(Tccr16::TCCR_A,config->tccrA);
   tccr.setTccrRegister(Tccr16::TCCR_B,config->tccrB);
   ocrA.setRegister(config->ocrA);
   ocrB.setRegister(config->ocrB);
   icr.setRegister(config->icr);
   timsk.setRegister(config->timsk);
   tifr.setRegister(config->tifr);    
   setInfo(&config->info);
   return;
}

void Timer16::setOutputCompare(Ocr16::OutputCompareRegister_e ocr, uint8_t rawValue)
{
    if(ocr == Ocr16::OCR_A)
    {
       ocrA.setOutputCompare(rawValue);
    }
    else
    {
       ocrB.setOutputCompare(rawValue);
    }
}

uint16_t Timer16::getOutputCompare(Ocr16::OutputCompareRegister_e ocr)
{
   if(ocr == Ocr16::OCR_A)
   {
      return ocrA.getOutputCompare();
   }
   else if(ocr == Ocr16::OCR_B)
   {
      return ocrB.getOutputCompare();
   }
}

Timer16::StdReturn_e Timer16::setTimerMode(Tccr16::TimerMode_e tmode)
{
   return setTimerMode(tmode);
}
void Timer16::setOutputMode(Tccr16::OutputMode_e omode)
{
   tccr.setOutputMode(omode);
}

void Timer16::setPreScaler(Tccr16::Prescaler_e prescaler)
{
   tccr.setPreScaler(prescaler);
}

Tccr16::Prescaler_e Timer16::getPrescaler(void)
{
   return tccr.getPreScaler();
}

void Timer16::toggleTimer(BaseTypes::Toggle_e status)
{
   tccr.toggleTimer(status);
}

uint16_t Timer16::getTime(void)
{
   return tcnt.getTime();
}

bool Timer16::hasTimerOverflow(void)
{
   return (bool)tifr.hasOverflow(Tifr::TIMER_OVERFLOW_1);
}
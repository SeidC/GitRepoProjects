/* 
* Timer16.cpp
*
* Created: 17.07.2016 13:43:07
* Author: AP02
*/


#include "Timer16.h"

// default constructor
Timer16::Timer16()
{
    
} //Timer16

// default destructor
Timer16::~Timer16()
{
} //~Timer16

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
   else
   {
      return ocrB.getOutputCompare();
   }
}

void Timer16::setTimerMode(Tccr16::TimerMode_e tmode)
{

}
void Timer16::setOutputMode(Tccr16::OutputMode_e omode)
{

}

void Timer16::setPreScaler(Tccr16::Prescaler_e prescaler)
{

}

Tccr16::Prescaler_e Timer16::getPrescaler(void)
{

}

void Timer16::toggleTimer(Toggle_e status)
{

}

uint16_t Timer16::getTime(void)
{

}
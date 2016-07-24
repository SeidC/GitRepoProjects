/* 
* Timer8.cpp
*
* Created: 17.07.2016 13:42:23
* Author: AP02
*/


#include "Timer8.h"

// default constructor
Timer8::Timer8(Timer8Config_t * timerCfg) : Tcnt8(timerCfg->tcnt) , 
                                            Tccr8(timerCfg->type,timerCfg->tccr), 
                                            Ocr8(timerCfg->ocr)
{
  
} //Timer8

// default destructor
Timer8::~Timer8()
{
} //~Timer8

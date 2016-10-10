/* 
* Tifr.cpp
*
* Created: 17.07.2016 00:16:14
* Author: AP
*/


#include "Tifr.h"

// default constructor
Tifr::Tifr()
{
} //Tifr

// default destructor
Tifr::~Tifr()
{
} //~Tifr


 bool Tifr::hasOverflow(Tifr::Overflow_e timer)
 {
    bool ret = false;
    switch(timer)
    {
       case TIMER_OVERFLOW_0:
         ret = (bool)this->getBit(TOV0);  
       break;
       case TIMER_OVERFLOW_1:
          ret = (bool)this->getBit(TOV1);
       break;
       case TIMER_OVERFLOW_2:
          ret = (bool)this->getBit(TOV2);
       break;
       default:
       
       break;
    }
    
    return ret;
 }
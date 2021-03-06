/* 
* Tccr8.cpp
*
* Created: 17.07.2016 13:11:56
* Author: AP02
*/


#include "Tccr8.h"

Tccr8::Tccr8()
{
    
} //Tccr8


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


 Tccr8::StdReturn_e Tccr8::setTimerMode(Tccr8::TimerMode_e mode)
 {
    Tccr8::StdReturn_e ret = STD_NOK;
    
    switch(mode)
    {
       case Tccr8::NORMAL_TIMER_MODE:
         resetBit(WGM00);
         resetBit(WGM01);
         ret = STD_OK;
       break;
       case Tccr8::PHASE_CORRECT_PWM_MODE:
         setBit(WGM00);
         resetBit(WGM01);
         ret = STD_OK;
       break;
       case Tccr8::CLEAR_TIMER_ON_COMPARE_MODE:
         resetBit(WGM00);
         setBit(WGM01);
         ret = STD_OK;
       break;
       case Tccr8::FAST_PWM_MODE:
         setBit(WGM00);
         setBit(WGM01);
         ret = STD_OK;
       break;
       default:
       break;
    }
    return ret;
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
         bits = (uint8_t)(BaseTypes::BIT_4 | BaseTypes::BIT_5);
         resetBits(bits);
         
         bits = (BaseTypes::Bits_e)(omode << ((uint8_t) BaseTypes::BIT_4));
         setBits((BaseTypes::Bits_e)bits);
     }
     return;
 }
 
 
  void Tccr8::toggleTimer(Toggle_e status)
  {
      Prescaler_e prescaler;
      uint8_t bits = 0;  
    if(status == BaseTypes::ENABLE)
    {
        prescaler = getPreScaler();
        RESET_BITS(bits,BIT_0|BIT_1|BIT_2);
        switch(prescaler)
        {
            case TccrIf::NO_PRESCALER                       :
            SET_BIT(bits,BIT_0);
            break;
            case TccrIf::PRESCALER_8                        :
            SET_BIT(bits,BIT_1);
            break;
            case TccrIf::PRESCALER_32                       :
            
            break;
            case TccrIf::PRESCALER_64                       :
            SET_BITS(bits,BIT_0|BIT_1);
            break;
            case TccrIf::PRESCALER_128                      :
            
            break;
            case TccrIf::PRESCALER_256                      :
            SET_BITS(bits,BIT_2);
            break;
            case TccrIf::PRESCALER_1024                     :
            SET_BITS(bits,BIT_0|BIT_2);
            break;
            case TccrIf::EXTERNAL_TM01_SOURCE_FALLING_EDGE  :
            SET_BITS(bits,BIT_0|BIT_1);
            break;
            case TccrIf::EXTERNAL_TM01_SOURCE_RISING_EDGE   :
            SET_BITS(bits,BIT_0|BIT_1|BIT_2);
            break;
            default:
            SET_BIT(bits,BIT_0);
        }
        setBits(bits);    
    }
    else
    {
        SET_BITS(bits,BIT_0|BIT_1|BIT_2);
        resetBits(bits);
    }
      return;
  }
/* 
* TccrIf.h
*
* Created: 17.07.2016 13:18:46
* Author: AP02
*/


#ifndef __TCCRIF_H__
#define __TCCRIF_H__
#include "BaseTypes.h"

class TccrIf : public BaseTypes
{
//types
public:
   enum Prescaler_e
   {
        NO_PRESCALER                      ,
        PRESCALER_8                       ,
        PRESCALER_32                      ,
        PRESCALER_64                      ,
        PRESCALER_128                     ,
        PRESCALER_256                     ,
        PRESCALER_1024                    ,
        EXTERNAL_TM01_SOURCE_FALLING_EDGE ,   
        EXTERNAL_TM01_SOURCE_RISING_EDGE  ,
    };      
   
   enum TimerMode_e
   {
      NORMAL_TIMER_MODE                   = 0x00,
      CLEAR_TIMER_ON_COMPARE_MODE         = 0x01,
      PHASE_CORRECT_PWM_MODE              = 0x02,
      FAST_PWM_MODE                       = 0x03,
   };

   enum OutputMode_e
   {
      OC_PIN_DISCONNECTED             = 0x00,
      TOGGLE_OC_PIN_ON_COMPARE        = 0x01,
      CLEAR_OC_PIN_ON_COMPARE         = 0x02,
      SET_OC_PIN_ON_COMPARE           = 0x03,
   };
//parameter 
private:
    Prescaler_e psc;
    TimerType_t type;

protected:
    virtual void setType(TimerType_t t)               {type = t;}
    virtual TimerType_t getType(void)                 {return type;}    

//functions
public:
	virtual ~TccrIf(){}
	virtual void setPreScaler(Prescaler_e prescaler)  {psc = prescaler;}
   virtual Prescaler_e getPreScaler(void)            {return psc;};
   virtual void toggleTimer(Toggle_e stauts) {}; 
   virtual StdReturn_e setTimerMode(TimerMode_e tmode) {};
   virtual void outputMode(OutputMode_e omode) {};

}; //TccrIf

#endif //__TCCRIF_H__

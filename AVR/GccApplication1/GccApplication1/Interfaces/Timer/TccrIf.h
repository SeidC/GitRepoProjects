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
        NO_PRESCALER,
        PRESCALER_8,
        PRESCALER_64,
        PRESCALER_256,
        PRESCALER_1024,
        EXTERNAL_SOURCE_FALLING_EDGE, // Only for Timer 0/1
        EXTERNAL_SOURCE_RISING_EDGE,  // Only for Timer 0/1
        PRESCALER_32,                 // Only for Timer 2
   };      
   
   enum TimerMode_e{};
   enum OutputMode_e{};
//parameter 
private:
    Prescaler_e psclBckUp;
    
//functions
public:
	virtual ~TccrIf(){}
	virtual void setPreScaler(Prescaler_e prescaler)  {psclBckUp = prescaler;}
    virtual void toggleTimer(Toggle_e stauts) = 0; 
    virtual void setTimerMode(TimerMode_e tmode)  = 0;
    virtual void outputMode(OutputMode_e omode) = 0;

}; //TccrIf

#endif //__TCCRIF_H__

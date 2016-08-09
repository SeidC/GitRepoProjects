/* 
* Timer8.h
*
* Created: 17.07.2016 13:42:23
* Author: AP02
*/


#ifndef __TIMER8_H__
#define __TIMER8_H__
#include "TimerIf.h"
#include "Tcnt8.h"
#include "Tccr8.h"
#include "Ocr8.h"
#include "Timsk.h"
#include "Tifr.h"


class Timer8 : public TimerIf
{
//variables
public:
protected:
private:
   Tcnt8 tcnt;
   Tccr8 tccr;
   Ocr8  ocr;
   Timsk timsk;
   Tifr  tifr;
   
    

//functions
public:
	Timer8(Timer8Config_t * timerCfg);
	~Timer8();
    void setConfig(Timer8Config_t *config);
    void setOutputCompare(uint8_t value);
    uint16_t getOutputCompare(void);
    StdReturn_e setTimerMode(Tccr8::TimerMode_e tmode);
    void setOutputMode(Tccr8::OutputMode_e omode);
    void setPreScaler(Tccr8::Prescaler_e prescaler);
    Tccr8::Prescaler_e getPrescaler(void);
    void toggleTimer(BaseTypes::Toggle_e status);
    uint16_t getTime(void);


protected:
private:
	Timer8( const Timer8 &c );
	Timer8& operator=( const Timer8 &c );

}; //Timer8

#endif //__TIMER8_H__

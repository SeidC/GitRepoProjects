/* 
* Tccr8.h
*
* Created: 17.07.2016 13:11:56
* Author: AP02
*/


#ifndef __TCCR8_H__
#define __TCCR8_H__
#include "TccrIf.h"
#include "RegIf8.h"

class Tccr8 : public TccrIf, public RegIf8
{
//types
public:

//variables
public:
protected:
private:

//functions
public:
    Tccr8();
	Tccr8(TimerType_t timerType,vuint8_t* tccrPtr);
	~Tccr8();
   StdReturn_e setTimerMode(TimerMode_e tmode);
   void setOutputMode(OutputMode_e omode);
   void setPreScaler(Prescaler_e prescaler);
   void toggleTimer(Toggle_e status);
   
protected:
private:
	Tccr8( const Tccr8 &c );
	Tccr8& operator=( const Tccr8 &c );
 
 }; //Tccr8

#endif //__TCCR8_H__

/* 
* Timer8.h
*
* Created: 17.07.2016 13:42:23
* Author: AP02
*/


#ifndef __TIMER8_H__
#define __TIMER8_H__
#include "Tcnt8.h"
#include "Tccr8.h"
#include "Ocr8.h"


class Timer8 : public Tcnt8, public Tccr8, public Ocr8
{
//variables
public:
protected:
private:
    

//functions
public:
	Timer8(Timer8Config_t * timerCfg);
	~Timer8();
protected:
private:
	Timer8( const Timer8 &c );
	Timer8& operator=( const Timer8 &c );

}; //Timer8

#endif //__TIMER8_H__

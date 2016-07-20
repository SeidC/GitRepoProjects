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
    enum TimerMode_e
    {
        TIMER_NORMAL,
        PHASE_CORRECT_PWM,
        CLEAR_ON_COMPARE,
        FAST_PWM,        
    }; 
    
    enum OutputMode_e 
    {
        
    };  
//variables
public:
protected:
private:

//functions
public:
	Tccr8();
	~Tccr8();
protected:
private:
	Tccr8( const Tccr8 &c );
	Tccr8& operator=( const Tccr8 &c );
    void setTimerMode(TimerMode_e tmode);
    void setOutputMode(OutputMode_e omode);

}; //Tccr8

#endif //__TCCR8_H__

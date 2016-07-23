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
        TIMER_NORMAL                   = 0x00,
        CLEAR_ON_COMPARE               = 0x08,
        PHASE_CORRECT_PWM              = 0x40,
        FAST_PWM                       = 0x48,        
    }; 
    
    enum OutputMode_e 
    {
        OC_PIN_DISCONNECTED             = 0x00,
        TOGGLE_OC_PIN_ON_COMPARE        = 0x01,
        CLEAR_OC_PIN_ON_COMPARE         = 0x02,
        SET_OC_PIN_ON_COMPARE           = 0x03,
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

/* 
* Tcrr8.h
*
* Created: 17.07.2016 13:11:56
* Author: AP02
*/


#ifndef __TCRR8_H__
#define __TCRR8_H__
#include "TccrIf.h"
#include "RegIf8.h"

class Tcrr8 : public TccrIf, public RegIf8
{
//types
public:
    enum Mode_e
    {
        TIMER_NORMAL,
        PHASE_CORRECT_PWM,
        CLEAR_ON_COMPARE,
        FAST_PWM,        
    };   
//variables
public:
protected:
private:

//functions
public:
	Tcrr8();
	~Tcrr8();
protected:
private:
	Tcrr8( const Tcrr8 &c );
	Tcrr8& operator=( const Tcrr8 &c );
    void setMode(Mode_e mode);

}; //Tcrr8

#endif //__TCRR8_H__

/* 
* Tccr16.h
*
* Created: 17.07.2016 13:14:07
* Author: AP02
*/


#ifndef __TCCR16_H__
#define __TCCR16_H__
#include "TccrA.h"
#include "TccrB.h"
#include "TccrIf.h"


class Tccr16 : public TccrIf 
{

//types    
public:  
        enum Mode_e 
        {
            TIMER_NORMAL,
            PHASE_CORRECT_PWM_8BIT,
            PHASE_CORRECT_PWM_9BIT,
            PHASE_CORRECT_PWM_10BIT,
            CLEAR_ON_COMPARE_1,
            FAST_PWM_8BIT,
            FAST_PWM_9BIT,
            FAST_PWM_10BIT,
            PHASE_FREQUENC_CORRECT_PWM_1,
            PHASE_FREQUENC_CORRECT_PWM_2,
            PHASE_CORRECT_PWM_EX_1,
            PHASE_CORRECT_PWM_EX_2,
            CLEAR_ON_COMPARE_2,
            RESERVED,
            FAST_PWM_EX_1,
            FAST_PWM_EX_2 
        };        
//variables
public:
protected:
private:
    TccrA tccra;
    TccrB tccrb;

//functions
public:
	Tccr16();
	~Tccr16();
    void toggleTimer(Toggle_e stauts);
    void setMode(Mode_e mode);
protected:
private:
	Tccr16( const Tccr16 &c );
	Tccr16& operator=( const Tccr16 &c );

}; //Tccr16

#endif //__TCCR16_H__

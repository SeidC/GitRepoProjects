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


#define TIMER_OPTIONAL_MODE_MAIN_MASK                0xF0

#define TIMER_OPTIONAL_MODE_SUB_MASK                 0x0F


class Tccr16 : public TccrIf 
{

//types    
public:  
        enum TimerOptionalMode_e 
        {
            NO_SPECIAL_MODE                                  = 0x00,                                
            /*PWM - Special Modes*/
            PWM_8BIT_TOP_ICR1_UPDATE_TOP                     = 0x10,
            PWM_8BIT_TOP_OCR1A_UPDATE_TOP                    = 0x11,
            PWM_9BIT_TOP_0x01FF_UPDATE_TOP                   = 0x12,
            PWM_10BIT_TOP_0x03FF_UPDATE_TOP                  = 0x13,
            PWM_FREQUENCY_CORRECT_TOP_ICR1_UPDATE_BOTTOM     = 0x14,
            PWM_FREQUNCY_CORRECT_TOP_OCR1A_UPDATE_BOTTOM     = 0x15,
            /*CTC - Special Modes*/
            CLEAR_TIMER_ON_COMPARE_TOP_ICR1_UPDATE_IMMEDIATE = 0x20,
            /*Fast PWM - Special Modes*/
            FAST_PWM_9BIT_TOP_0x01FF_UPDATE_BOTTOM           = 0x30,
            FAST_PWM_10BIT_TOP_0x03FF_UPDATE_BOTTOM          = 0x31,
            FAST_PWM_TOP_ICR1_UPDATE_BOTTOM                  = 0x32,
            FAST_PWM_TOP_OCR1A_UPDATE_BUTTON                 = 0x33,           
        };   
        
        enum TccrType_e
        {
            TCCR_A,
            TCCR_B,   
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
    StdReturn_e setTimerMode(TimerMode_e mode, TimerOptionalMode_e spMode = NO_SPECIAL_MODE);
    void setTccrRegister(TccrType_e registerType, vuint8_t* reg);
protected:
private:
	Tccr16( const Tccr16 &c );
	Tccr16& operator=( const Tccr16 &c );

}; //Tccr16

#endif //__TCCR16_H__

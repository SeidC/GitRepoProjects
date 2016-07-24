/* 
* Tccr16.cpp
*
* Created: 17.07.2016 13:14:07
* Author: AP02
*/


#include "Tccr16.h"

// default constructor
Tccr16::Tccr16()
{
} //Tccr16

// default destructor
Tccr16::~Tccr16()
{
} //~Tccr16


void Tccr16::toggleTimer(Toggle_e status)
{
    if(status == BaseTypes::ENABLE)
    {
        
    }
    else
    {
                
    }
}


void Tccr16::setMode(Tccr16::Mode_e mode)
{
    switch(mode)
    {
        case Tccr16::TIMER_NORMAL:
            tccra.resetBits(WGM11|WGM10);
            tccrb.resetBits(WGM12|WGM13);
        break;
        case Tccr16::PHASE_CORRECT_PWM_8BIT:
            tccra.setBit((BaseTypes::Bits_e)   WGM10);
            tccra.resetBit((BaseTypes::Bits_e) WGM11);
            tccrb.resetBit((BaseTypes::Bits_e) WGM12);
            tccrb.resetBit((BaseTypes::Bits_e) WGM13);
        break;
        case Tccr16::PHASE_CORRECT_PWM_9BIT:
        
        break;
        case Tccr16::PHASE_CORRECT_PWM_10BIT:
        
        break;
        case Tccr16::CLEAR_ON_COMPARE_1:
            tccra.resetBit((BaseTypes::Bits_e) WGM10);
            tccra.resetBit((BaseTypes::Bits_e) WGM11);
            tccrb.setBit((BaseTypes::Bits_e)   WGM12);
            tccrb.resetBit((BaseTypes::Bits_e) WGM13);
        break;
        case Tccr16::FAST_PWM_8BIT:
        
        break;
        case Tccr16::FAST_PWM_9BIT:
        
        break;
        case Tccr16::FAST_PWM_10BIT:
        
        break;
        case Tccr16::PHASE_FREQUENC_CORRECT_PWM_1:
        
        break;
        case Tccr16::PHASE_FREQUENC_CORRECT_PWM_2:
        
        break;
        case Tccr16::PHASE_CORRECT_PWM_EX_1:
        
        break;
        case Tccr16::PHASE_CORRECT_PWM_EX_2:
        
        break;
        case Tccr16::CLEAR_ON_COMPARE_2:
        
        break;
        case Tccr16::RESERVED:
        
        break;
        case Tccr16::FAST_PWM_EX_1:
        
        break;
        case Tccr16::FAST_PWM_EX_2:
        
        break;
        default:
            tccra.resetBits(WGM11|WGM10);
            tccrb.resetBits(WGM12|WGM13);
        break;
    }
    
}
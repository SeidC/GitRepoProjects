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
    Prescaler_e prescaler;
    uint8_t bits;
    if(status == BaseTypes::ENABLE)
    {
        prescaler = getPreScaler();
        RESET_BITS(bits,BIT_0|BIT_1|BIT_2);
        switch(prescaler)
        {
            case TccrIf::NO_PRESCALER                       :
            SET_BIT(bits,BIT_0);
            break;
            case TccrIf::PRESCALER_8                        :
            SET_BIT(bits,BIT_1);
            break;
            case TccrIf::PRESCALER_32                       :
            
            break;
            case TccrIf::PRESCALER_64                       :
            SET_BITS(bits,BIT_0|BIT_1);
            break;
            case TccrIf::PRESCALER_128                      :
            
            break;
            case TccrIf::PRESCALER_256                      :
            SET_BITS(bits,BIT_2);
            break;
            case TccrIf::PRESCALER_1024                     :
            SET_BITS(bits,BIT_0|BIT_2);
            break;
            case TccrIf::EXTERNAL_TM01_SOURCE_FALLING_EDGE  :
            SET_BITS(bits,BIT_0|BIT_1);
            break;
            case TccrIf::EXTERNAL_TM01_SOURCE_RISING_EDGE   :
            SET_BITS(bits,BIT_0|BIT_1|BIT_2);
            break;
            default:
            SET_BIT(bits,BIT_0);
        }
        tccrb.setBits(bits);
    }
    else
    {
        SET_BITS(bits,BIT_0|BIT_1|BIT_2);
        tccrb.resetBits(bits);
    }
    return;
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
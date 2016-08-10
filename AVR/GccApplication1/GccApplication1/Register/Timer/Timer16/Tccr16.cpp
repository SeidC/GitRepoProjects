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


void Tccr16::toggleTimer(Tccr16::Toggle_e status)
{
    Prescaler_e prescaler;
    uint8_t bits;
    if(status == BaseTypes::ENABLE)
    {
        prescaler = getPreScaler();
        RESET_BITS(bits,BIT_0|BIT_1|BIT_2);
        switch(prescaler)
        {
            case Tccr16::NO_PRESCALER                       :
            SET_BIT(bits,BIT_0);
            break;
            case Tccr16::PRESCALER_8                        :
            SET_BIT(bits,BIT_1);
            break;
            case Tccr16::PRESCALER_32                       :
            
            break;
            case Tccr16::PRESCALER_64                       :
            SET_BITS(bits,BIT_0|BIT_1);
            break;
            case Tccr16::PRESCALER_128                      :
            
            break;
            case Tccr16::PRESCALER_256                      :
            SET_BITS(bits,BIT_2);
            break;
            case Tccr16::PRESCALER_1024                     :
            SET_BITS(bits,BIT_0|BIT_2);
            break;
            case Tccr16::EXTERNAL_TM01_SOURCE_FALLING_EDGE  :
            SET_BITS(bits,BIT_0|BIT_1);
            break;
            case Tccr16::EXTERNAL_TM01_SOURCE_RISING_EDGE   :
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


Tccr16::StdReturn_e setTimerMode(Tccr16::TimerMode_e mode, Tccr16::TimerOptionalMode_e spMode)
{
   Tccr16::StdReturn_e ret = Tccr16::STD_NOT_SUPPORTED;
   uint8_t regA = 0 ,regB = 0;

   switch(mode)
   {
      case Tccr16::NORMAL_TIMER_MODE:
      {
         if(spMode == Tccr16::NO_SPECIAL_MODE)
         {
             RESET_BIT(regA,WGM10);
             RESET_BIT(regA,WGM11);
             RESET_BIT(regB,WGM12);
             RESET_BIT(regB,WGM13);
             ret = Tccr16::STD_OK;
         }
         break;
      }
      case Tccr16::CLEAR_TIMER_ON_COMPARE_MODE:
      {
         if(spMode == Tccr16::NO_SPECIAL_MODE)
         {
            RESET_BIT(regA,WGM10);
            RESET_BIT(regA,WGM11);
            SET_BIT(regB,WGM12);
            RESET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }
         else if(spMode == Tccr16::CLEAR_TIMER_ON_COMPARE_TOP_ICR1_UPDATE_IMMEDIATE)
         {
            RESET_BIT(regA,WGM10);
            RESET_BIT(regA,WGM11);
            SET_BIT(regB,WGM12);
            SET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }
         else
         {
            /*--- Do Nothing ---*/
         }
         break;
      }
      case Tccr16::PHASE_CORRECT_PWM_MODE:
      {
         if(spMode == Tccr16::NO_SPECIAL_MODE)
         {
            SET_BIT(regA,WGM10);
            RESET_BIT(regA,WGM11);
            RESET_BIT(regB,WGM12);
            RESET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }  
         else if (spMode == Tccr16::PWM_8BIT_TOP_ICR1_UPDATE_TOP)
         {
            RESET_BIT(regA,WGM10);
            SET_BIT(regA,WGM11);
            RESET_BIT(regB,WGM12);
            SET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }
         else if (spMode == Tccr16::PWM_8BIT_TOP_OCR1A_UPDATE_TOP)
         {
            SET_BIT(regA,WGM10);
            SET_BIT(regA,WGM11);
            RESET_BIT(regB,WGM12);
            SET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }
         else if (spMode == Tccr16::PWM_9BIT_TOP_0x01FF_UPDATE_TOP)
         {
            RESET_BIT(regA,WGM10);
            SET_BIT(regA,WGM11);
            RESET_BIT(regB,WGM12);
            RESET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }
         else if (spMode == Tccr16::PWM_10BIT_TOP_0x03FF_UPDATE_TOP)
         {
            SET_BIT(regA,WGM10);
            SET_BIT(regA,WGM11);
            RESET_BIT(regB,WGM12);
            RESET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }
         else if (spMode == Tccr16::PWM_FREQUENCY_CORRECT_TOP_ICR1_UPDATE_BOTTOM)
         {
            RESET_BIT(regA,WGM10);
            RESET_BIT(regA,WGM11);
            RESET_BIT(regB,WGM12);
            SET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;
         }
         else if (spMode == Tccr16::PWM_FREQUNCY_CORRECT_TOP_OCR1A_UPDATE_BOTTOM)
         {
            SET_BIT(regA,WGM10);
            RESET_BIT(regA,WGM11);
            RESET_BIT(regB,WGM12);
            SET_BIT(regB,WGM13);
            ret = Tccr16::STD_OK;  
         }
         else
         {
            /*--- Do Nothing ---*/
         }            
         break;
      }        
      case Tccr16::FAST_PWM_MODE:
      {
      
         break;   
      }
      default:
      {
       
         break;  
      }            
   }
   return ret;      
}   
    
void Tccr16::setTccrRegister(Tccr16::TccrType_e registerType, vuint8_t* reg)
{
   if(registerType == Tccr16::TCCR_A)
   {
      tccra.setRegister(reg);
   }
   else if (registerType == Tccr16::TCCR_B)
   {
      tccrb.setRegister(reg);
   }
   else
   {
      
   }
   return; 
}   


void Tccr16::setOutputMode(Tccr16::OutputMode_e omode)
{
   
}
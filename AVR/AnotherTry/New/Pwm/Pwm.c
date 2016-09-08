   /*
   * Pwm.c
   *
   * Created: 08.09.2016 19:52:41
   *  Author: AP
   */ 
   #include "Pwm.h"

#define PWM_FAST_PWM_SCALER          256u

#define PWM_PHASE_CORRECT_SCALER    510u

#define PWM_NUMBER_OF_PRESCALER        5u


static const uint16_t Pwm_PrescalerFactorTable[PWM_NUMBER_OF_PRESCALER] = 
                       [1,8,64,256,1024];

static Pwm_Prescaler_t Pwm_prescaler;


void Pwm_SetPwmMode(Pwm_Mode_t mode)
{
   if(mode == PWM_FAST_PWM)
   {
      TCCR0 |= (1 << WGM00);
      TCCR0 |= (1 << WGM01);
   }
   else if (mode == PWM_PHASE_CORRECT)
   {
      TCCR0 |= (1 << WGM00);
      TCCR0 &= ~(1 << WGM01)
   }
   else
   {
         
   }
   return
}


void Pwm_ConfigureOutputPin(Pwm_OutputPin_t pinCfg)
{
   if (pinCfg == PWM_PIN_NOT_USED  )
   {
      TCCR0 &= ~(1 << COM00);
      TCCR0 &= ~(1 << COM01);
   }
   else if (pinCfg == PWM_NON_INVERTED)
   {
      TCCR0 &= ~(1 << COM00);
      TCCR0 |=  (1 << COM01);
   }
   else if (pinCfg == PWM_INVERTED)
   { 
      TCCR0 |=  (1 << COM00);
      TCCR0 |=  (1 << COM01); 
   }
   else
   {
       
   } 
   return;
}

void Pwm_SetPwmFrequenze(Pwm_Prescaler_t prescaler)
{
   Pwm_prescaler = prescaler;
   return;
}

void Pwm_Start(void)
{
   if(Pwm_prescaler == PWM_PRESCALER_0   )
   {
      TCCR0 |=  (1 << CS00);
      TCCR0 &= ~(1 << CS01);
      TCCR0 &= ~(1 << CS02);
   }
   else if(Pwm_prescaler == PWM_PRESCALER_8   )
   {
      TCCR0 &= ~(1 << CS00);
      TCCR0 |=  (1 << CS01);
      TCCR0 &= ~(1 << CS02);
   }
   else if(Pwm_prescaler == PWM_PRESCALER_64  )
   {
      TCCR0 |=  (1 << CS00);
      TCCR0 |=  (1 << CS01);
      TCCR0 &= ~(1 << CS02);
   }
   else if(Pwm_prescaler == PWM_PRESCALER_256 )
   {
      TCCR0 &= ~(1 << CS00);
      TCCR0 &= ~(1 << CS01);
      TCCR0 |=  (1 << CS02);
   }
   else if(Pwm_prescaler == PWM_PRESCALER_1024)
   {
      TCCR0 |=  (1 << CS00);
      TCCR0 &= ~(1 << CS01);
      TCCR0 |=  (1 << CS02);
   }
   else
   {
      
   }
   return
}

void Pwm_Stop(void)
{
   uint8_t pwmValue;
   pwmValue |= ((TCCR0 & CS00) | (TCCR0 & CS01) |(TCCR0 & CS02)) - 1;
   Pwm_prescaler = (Pwm_Prescaler_t)pwmValue;
   TCCR0 &= ~(1 << CS00);
   TCCR0 &= ~(1 << CS01);
   TCCR0 &= ~(1 << CS02);
   return;   
}


void Pwm_TogglePwm(Pwm_Status_t status)
{
    if(status == PWM_START)
    {
       Pwm_Start();
    }
    else
    {
       Pwm_Stop();
    }
   
}
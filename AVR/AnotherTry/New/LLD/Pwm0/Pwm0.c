   /*
   * Pwm0.c
   *
   * Created: 08.09.2016 19:52:41
   *  Author: AP
   */ 
   #include "Pwm0.h"


#define PWM0_DUTY_CYCLE_100						255u


static Pwm0_Prescaler_t Pwm0_prescaler;


void Pwm0_SetPwmMode(Pwm0_Mode_t mode)
{
   if(mode == PWM0_FAST_PWM0)
   {
      TCCR0 |= (1 << WGM00);
      TCCR0 |= (1 << WGM01);
   }
   else if (mode == PWM0_PHASE_CORRECT)
   {
      TCCR0 |= (1 << WGM00);
      TCCR0 &= ~(1 << WGM01);
   }
   else
   {
         
   }
   return;
}


void Pwm0_ConfigureOutputPin(Pwm0_OutputPin_t pinCfg)
{
   if (pinCfg == PWM0_PIN_NOT_USED  )
   {
      TCCR0 &= ~(1 << COM00);
      TCCR0 &= ~(1 << COM01);
   }
   else if (pinCfg == PWM0_NON_INVERTED)
   {
      TCCR0 &= ~(1 << COM00);
      TCCR0 |=  (1 << COM01);
   }
   else if (pinCfg == PWM0_INVERTED)
   { 
      TCCR0 |=  (1 << COM00);
      TCCR0 |=  (1 << COM01); 
   }
   else
   {
       
   } 
   return;
}

void Pwm0_SetPwmFrequenze(Pwm0_Prescaler_t prescaler)
{
   Pwm0_prescaler = prescaler;
   return;
}

void Pwm0_Start(void)
{
   DDRB |= (1 << PB3);
   if(Pwm0_prescaler == PWM0_PRESCALER_0   )
   {
      TCCR0 |=  (1 << CS00);
      TCCR0 &= ~(1 << CS01);
      TCCR0 &= ~(1 << CS02);
   }
   else if(Pwm0_prescaler == PWM0_PRESCALER_8   )
   {
      TCCR0 &= ~(1 << CS00);
      TCCR0 |=  (1 << CS01);
      TCCR0 &= ~(1 << CS02);
   }
   else if(Pwm0_prescaler == PWM0_PRESCALER_64  )
   {
      TCCR0 |=  (1 << CS00);
      TCCR0 |=  (1 << CS01);
      TCCR0 &= ~(1 << CS02);
   }
   else if(Pwm0_prescaler == PWM0_PRESCALER_256 )
   {
      TCCR0 &= ~(1 << CS00);
      TCCR0 &= ~(1 << CS01);
      TCCR0 |=  (1 << CS02);
   }
   else if(Pwm0_prescaler == PWM0_PRESCALER_1024)
   {
      TCCR0 |=  (1 << CS00);
      TCCR0 &= ~(1 << CS01);
      TCCR0 |=  (1 << CS02);
   }
   else
   {
      
   }
   return;
}

void Pwm0_Stop(void)
{
   uint8_t pwmValue = 0;
   pwmValue |= ((TCCR0 & CS00) | (TCCR0 & CS01) |(TCCR0 & CS02)) - 1;
   Pwm0_prescaler = (Pwm0_Prescaler_t)pwmValue;
   TCCR0 &= ~(1 << CS00);
   TCCR0 &= ~(1 << CS01);
   TCCR0 &= ~(1 << CS02);
   return;   
}


void Pwm0_TogglePwm(Pwm0_Status_t status)
{
   if(status == PWM0_START)
   {
      Pwm0_Start();
   }
   else
   {
      Pwm0_Stop();
   }
   return;
}

void Pwm0_SetDutyCycle(uint8_t dutyCycle)
{
	uint8_t newDutyCycle;
   if (dutyCycle >= 0 && dutyCycle <= 100)
   {	
	   newDutyCycle = PWM0_DUTY_CYCLE_100 * dutyCycle / 100;
	   OCR0 = newDutyCycle;
   }
   return;
}
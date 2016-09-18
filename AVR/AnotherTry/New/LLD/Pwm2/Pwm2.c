   /*
   * Pwm2.c
   *
   * Created: 08.09.2016 19:52:41
   *  Author: AP
   */ 
   #include "Pwm2.h"


#define PWM2_DUTY_CYCLE_100						255u


static Pwm2_Prescaler_t Pwm2_prescaler;


void Pwm2_SetPwmMode(Pwm2_Mode_t mode)
{
   if(mode == PWM2_FAST_PWM2)
   {
      TCCR2 |= (1 << WGM20);
      TCCR2 |= (1 << WGM21);
   }
   else if (mode == PWM2_PHASE_CORRECT)
   {
      TCCR2 |=  (1 << WGM20);
      TCCR2 &= ~(1 << WGM21);
   }
   else
   {
         
   }
   return;
}


void Pwm2_ConfigureOutputPin(Pwm2_OutputPin_t pinCfg)
{
   if (pinCfg == PWM2_PIN_NOT_USED  )
   {
      TCCR2 &= ~(1 << COM20);
      TCCR2 &= ~(1 << COM21);
   }
   else if (pinCfg == PWM2_NON_INVERTED)
   {
      TCCR2 &= ~(1 << COM20);
      TCCR2 |=  (1 << COM21);
   }
   else if (pinCfg == PWM2_INVERTED)
   { 
      TCCR2 |=  (1 << COM20);
      TCCR2 |=  (1 << COM21); 
   }
   else
   {
       
   } 
   return;
}

void Pwm2_SetPwmFrequenze(Pwm2_Prescaler_t prescaler)
{
   Pwm2_prescaler = prescaler;
   return;
}

void Pwm2_Start(void)
{
   DDRD |= (1 << PD7);
   if(Pwm2_prescaler == PWM2_PRESCALER_0   )
   {
      TCCR2 |=  (1 << CS20);
      TCCR2 &= ~(1 << CS21);
      TCCR2 &= ~(1 << CS22);
   }
   else if(Pwm2_prescaler == PWM2_PRESCALER_8   )
   {
      TCCR2 &= ~(1 << CS20);
      TCCR2 |=  (1 << CS21);
      TCCR2 &= ~(1 << CS22);
   }
   else if(Pwm2_prescaler == PWM2_PRESCALER_64  )
   {
      TCCR2 |=  (1 << CS00);
      TCCR2 |=  (1 << CS01);
      TCCR2 &= ~(1 << CS02);
   }
   else if(Pwm2_prescaler == PWM2_PRESCALER_256 )
   {
      TCCR2 &= ~(1 << CS20);
      TCCR2 &= ~(1 << CS21);
      TCCR2 |=  (1 << CS22);
   }
   else if(Pwm2_prescaler == PWM2_PRESCALER_1024)
   {
      TCCR2 |=  (1 << CS20);
      TCCR2 &= ~(1 << CS21);
      TCCR2 |=  (1 << CS22);
   }
   else
   {
      
   }
   return;
}

void Pwm2_Stop(void)
{
   uint8_t pwmValue = 0;
   pwmValue |= ((TCCR2 & CS20) | (TCCR2 & CS21) |(TCCR2 & CS22)) - 1;
   Pwm2_prescaler = (Pwm2_Prescaler_t)pwmValue;
   TCCR2 &= ~(1 << CS20);
   TCCR2 &= ~(1 << CS21);
   TCCR2 &= ~(1 << CS22);
   return;   
}


void Pwm2_TogglePwm(Pwm2_Status_t status)
{
   if(status == PWM2_START)
   {
      Pwm2_Start();
   }
   else
   {
      Pwm2_Stop();
   }
   return;
}

void Pwm2_SetDutyCycle(uint8_t dutyCycle)
{
	uint8_t newDutyCycle;
   if (dutyCycle >= 0 && dutyCycle <= 100)
   {	
	   newDutyCycle = PWM2_DUTY_CYCLE_100 * dutyCycle / 100;
	   OCR2 = newDutyCycle;
   }
   return;
}


void Pwm2_Init(Pwm2_Config_t* config)
{
	Pwm2_SetPwmMode(config->mode);
	Pwm2_SetPwmFrequenze(config->prescaler);
	Pwm2_ConfigureOutputPin(config->outputPin);
	return;
}
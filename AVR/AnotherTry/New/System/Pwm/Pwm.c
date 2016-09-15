   /*
   * Pwm.c
   *
   * Created: 08.09.2016 19:52:41
   *  Author: AP
   */ 
   #include "Pwm.h"
   #include "Pwm0.h"
   #include "Pwm2.h"


void Pwm_SetPwmMode(Pwm_Channel_t channel, Pwm_Mode_t mode)
{
   switch (channel)
   {
      case PWM_CHANNEL_0:
         Pwm0_SetPwmMode((Pwm0_Mode_t)mode);
      break;
      case PWM_CHANNEL_2:
         Pwm2_SetPwmMode((Pwm2_Mode_t)mode);
      break;
      default:
      break;
   }     
   return;
}


void Pwm_ConfigureOutputPin(Pwm_Channel_t channel, Pwm_OutputPin_t pinCfg)
{
   switch (channel)
   {
      case PWM_CHANNEL_0:
         Pwm0_ConfigureOutputPin((Pwm0_OutputPin_t) pinCfg);
      break;
      case PWM_CHANNEL_2:
         Pwm2_ConfigureOutputPin((Pwm2_OutputPin_t) pinCfg);
      break;
      default:
      break;
   }
   return;
}

void Pwm_SetPwmFrequenze(Pwm_Channel_t channel, Pwm_Prescaler_t prescaler)
{
   switch (channel)
   {
      case PWM_CHANNEL_0:
         Pwm0_SetPwmFrequenze((Pwm0_Prescaler_t)prescaler);
      break;
      case PWM_CHANNEL_2:
         Pwm2_SetPwmFrequenze((Pwm2_Prescaler_t)prescaler);
      break;
      default:
      break;
   }
   return;
}

void Pwm_Start(Pwm_Channel_t channel)
{
   switch (channel)
   {
      case PWM_CHANNEL_0:
         Pwm0_Start();
      break;
      case PWM_CHANNEL_2:
         Pwm2_Start();
      break;
      default:
      break;
   }
   return;
}

void Pwm_Stop(Pwm_Channel_t channel)
{
   switch (channel)
   {
      case PWM_CHANNEL_0:
         Pwm0_Stop();
      break;
      case PWM_CHANNEL_2:
         Pwm2_Stop();
      break;
      default:
      break;
   }
   return;   
}


void Pwm_TogglePwm(Pwm_Channel_t channel, Pwm_Status_t status)
{
   switch (channel)
   {
      case PWM_CHANNEL_0:
         Pwm0_TogglePwm((Pwm0_Status_t) status);  
      break;
      case PWM_CHANNEL_2:
         Pwm2_TogglePwm((Pwm2_Status_t) status);
      break;
      default:
      break;
   }
   return;
}

void Pwm_SetDutyCycle(Pwm_Channel_t channel, uint8_t dutyCycle)
{
	switch (channel)
	{
   	case PWM_CHANNEL_0:
         Pwm0_SetDutyCycle(uint8_t dutyCycle);
   	break;
   	case PWM_CHANNEL_2:
   	   Pwm2_SetDutyCycle(uint8_t dutyCycle);
   	break;
   	default:
   	break;
	}
   return;
}
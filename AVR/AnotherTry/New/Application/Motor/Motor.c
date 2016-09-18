/*
 * Motor.c
 *
 * Created: 18.09.2016 15:35:33
 *  Author: AP02
 */ 
#include "Motor.h"


Motor_Config_t Motor_config[MOTOR_NUMBER_OF_MOTOR] =
      {
         {
            .motorAdcChannel = ADC_CHANNEL_0,
            .motorBridge     = TLE5206_BRIDGE_00,
            
         },
         {
            .motorAdcChannel = ADC_CHANNEL_1,
            .motorBridge     = TLE5206_BRIDGE_01,
         },
      };
      
      
void Motor_Enable(Motor_Names_t motor)
{
    
}


void Motor_Disable(Motor_Names_t motor)
{
   
}
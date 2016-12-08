/*
 * Easy_Cfg.c
 *
 * Created: 03.11.2016 23:53:46
 *  Author: AP
 */ 
#include "Easy_Cfg.h"


Easy_Config_t Easy_config =
{
   .indicationTime      =  300,
   .lowBit              =  200,
   .highBit             =  400,
   .jitter              =   25,
   .bitPause            =   50,
};



EASY_INLINE void Easy_Cfg_SwitchCapturedEdge(void)
{
   if(Timer1_GetCapturedEdge() == TIMER1_CAPTURE_RISING_EDGE)
   {
      Timer1_CaptureEdge(TIMER1_CAPTURE_FALLING_EDGE);
   }
   else 
   {
      Timer1_CaptureEdge(TIMER1_CAPTURE_RISING_EDGE);
   }
   return;
}

EASY_INLINE uint8_t Easy_Cfg_GetCapturedEdge(void)
{
   return (uint8_t) Timer1_GetCapturedEdge();
}


void Easy_Cfg_CaptureEdge(uint8_t edge)
{
   Timer1_CaptureEdge((Timer1_InputCaptureEdge_t)edge);
   return; 
}
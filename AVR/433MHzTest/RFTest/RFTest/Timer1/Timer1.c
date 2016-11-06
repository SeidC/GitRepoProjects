/*
 * Timer1.c
 *
 * Created: 12.10.2016 23:12:19
 *  Author: AP02
 */ 

#include "Timer1.h"
#include "avr/io.h"

#include "PR_DEF.h"

void Timer1_Init(void)
{
	TCCR1A = TIMER1_CONTROL_A_REGISTER;
	TCCR1B = TIMER1_CONTROL_B_REGISTER;
}


uint16_t Timer1_GetCounterValueUs(void)
{
	return ((TCNT1 * 1000000 * TIMER1_PRESCALER_CALC_VALUE)/F_CPU);
}


uint16_t Timer1_CalculateTimeDiff(uint16_t diffTime)
{
   uint16_t ret = 0;
   if(!TIMER1_HAS_TIMER_OVERFLOW())
   {
      ret = TIMER1_GET_ACTUAL_COUNTER_VALUE() - diffTime;   
   }
   else
   {
      ret =    (TIMER1_COUNTER_MAX - diffTime) + TIMER1_GET_ACTUAL_COUNTER_VALUE();
      TIMER1_RESET_OVERFLOW_FLAG();
   }
   return ret;
}
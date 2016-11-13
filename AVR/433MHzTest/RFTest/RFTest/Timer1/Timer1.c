/*
 * Timer1.c
 *
 * Created: 12.10.2016 23:12:19
 *  Author: AP02
 */ 

#include "Timer1.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "PR_DEF.h"


static uint32_t  Timer1_overFlowCount;


void Timer1_Init(void)
{
	TCCR1A = TIMER1_CONTROL_A_REGISTER;
	TCCR1B = TIMER1_CONTROL_B_REGISTER;
   TIMSK  |= TIMER1_INTERRUPT_MASK_CFG;
   Timer1_overFlowCount = 0;
   sei();
}


uint16_t Timer1_GetCounterValueUs(void)
{
	return ((TCNT1 * 1000000 * TIMER1_PRESCALER_CALC_VALUE)/F_CPU);
}


uint16_t Timer1_CalculateActualTimeDiff(Timer1_Time_t* diffTime)
{
   uint16_t ret;
   uint32_t cVal, diff;
   
   diff = (uint32_t)diffTime->overflow * (uint32_t)TIMER1_COUNTER_MAX +
          (uint32_t)diffTime->count;
   
   cVal = (uint32_t)Timer1_overFlowCount * (uint32_t)TIMER1_COUNTER_MAX +
   TIMER1_GET_ACTUAL_COUNTER_VALUE();
   
   ret = cVal - diff;   
   return ret;
}


TIMER1_INLINE void Timer1_GetCount(Timer1_Time_t *ptr)
{
   if(ptr != NULL)
   {
      ptr->count = (uint16_t)TCNT1;
      ptr->overflow = Timer1_overFlowCount;
   }
   return;
}



InterruptRoutine(TIMER1_OVF_vect)
{
   Timer1_overFlowCount++;
}

uint16_t Timer1_CalculateTimeDiffBetweenTimes(Timer1_Time_t *oTime,Timer1_Time_t *nTime)
{
      uint16_t ret;
      uint32_t nDiff, oDiff;
      
      oDiff = (uint32_t)oTime->overflow * (uint32_t)TIMER1_COUNTER_MAX +
      (uint32_t)oTime->count;
      
      nDiff = (uint32_t)nTime->overflow* (uint32_t)TIMER1_COUNTER_MAX +
               nTime->count;
      
      ret = (uint16_t)(nDiff - oDiff);
      return ret;
}
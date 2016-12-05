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

TIMER1_INLINE uint16_t Timer1_GetOverflowGap(Timer1_Time_t *oTimer,Timer1_Time_t *nTimer);

volatile static uint32_t  Timer1_overFlowCount;

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
   uint16_t ret,gap;
   uint32_t cVal, diff;
   
   Timer1_Time_t currentTime = 
         {
            .count = TIMER1_GET_ACTUAL_COUNTER_VALUE(),
            .overflow = Timer1_overFlowCount,
         };
         
   gap =  Timer1_GetOverflowGap(diffTime,&currentTime);
   
   cVal = (uint32_t)(gap) * (uint32_t)TIMER1_COUNTER_MAX + currentTime.count;
   
   ret = cVal - diffTime->count;
   return ret;
}


TIMER1_INLINE void Timer1_GetCount(Timer1_Time_t *ptr)
{
   if(ptr != NULL)
   {
      ptr->count = TIMER1_GET_ACTUAL_COUNTER_VALUE();
      ptr->overflow = Timer1_overFlowCount;
   }
   return;
}

TIMER1_INLINE void Timer1_GetInputCaptureCount(Timer1_Time_t *ptr)
{
   if(ptr != NULL)
   {
      ptr->count = TIMER1_GET_INPUT_CAPTURE_TIME();
      ptr->overflow = Timer1_overFlowCount;
   }
   return;
}


TIMER1_INLINE uint16_t Timer1_GetOverflowGap(Timer1_Time_t *oTimer,Timer1_Time_t *nTimer)
{
   uint16_t ret = 0;
   if(nTimer->overflow >= oTimer->overflow)
   {
      ret = nTimer->overflow - oTimer->overflow;
   }
   else
   {
      ret = INT16_MAX - oTimer->overflow + nTimer->overflow;
   }
   return ret;
}

InterruptRoutine(TIMER_1_OVERFLOW_INTERRUPT)
{
   Timer1_overFlowCount++;
}

uint16_t Timer1_CalculateTimeDiffBetweenTimes(Timer1_Time_t *oTime,Timer1_Time_t *nTime)
{
      uint16_t ret,gap;
      uint32_t cVal, diff;
      
      gap =  Timer1_GetOverflowGap(oTime,nTime);
      
      cVal = (uint32_t)(gap) * (uint32_t)TIMER1_COUNTER_MAX + nTime->count;
      
      ret = cVal - oTime->count;
      return ret;
}


void Timer1_WaitUsHard(uint16_t usTime)
{
   Timer1_Time_t tTime;
   Timer1_GetCount(&tTime);
   usTime = TIMER1_CALCULATE_US_TIME_TO_TICKS(usTime - TIMER1_WAIT_US_HARD_OFFSET);
   do{
         /*--- Do Nothing ---*/
   }while(Timer1_CalculateActualTimeDiff(&tTime) < usTime);
   return;
}


TIMER1_INLINE volatile uint32_t Timer1_GetOverflowCount(void)
{
   return Timer1_overFlowCount;
}

TIMER1_INLINE void Timer1_CaptureEdge(Timer1_InputCaptureEdge_t edge)
{
   edge == TIMER1_CAPTURE_FALLING_EDGE       ? 
               (TCCR1B &= ~(1 << ICES1))     :
               (TCCR1B |=  (1 << ICES1));
   return;
}

TIMER1_INLINE Timer1_InputCaptureEdge_t Timer1_GetCapturedEdge(void)
{
   return  (Timer1_InputCaptureEdge_t)((TCCR1B & (1 << ICES1)) >> ICES1);
}


/*
 * Timer1.h
 *
 * Created: 12.10.2016 23:12:38
 *  Author: AP02
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "PR_DEF.h"
#include "Timer1_Cfg.h"
#include "avr/io.h"


#define TIMER1_HAS_TIMER_OVERFLOW()				            \
		  ((TIFR & (1 << TOV1)) >> TOV1)

#define TIMER1_RESET_OVERFLOW_FLAG()                     \
        (TIFR &= ~(1 << TOV1))

#define TIMER1_COUNTER_MAX							            \
		  (UINT16_MAX)

#define TIMER1_GET_ACTUAL_COUNTER_VALUE()			         \
		  ((uint16_t)TCNT1)

#define TIMER1_GET_INPUT_CAPTURE_TIME()                  \
        ((uint16_t)ICR1)

#define TIMER1_CHECK_TIMER_OVERFLOW(valueToCheck)	      \
		  ((TCNT1 + (uint32_t)valueToCheck) > TIMER1_COUNTER_MAX)
		
#define TIMER1_RESET_OVERFLOW()						         \
        ((TIFR &= ~(1 << TOV1)))


#define TIMER1_FREQUENCY_FACTOR                          \
		   ((F_CPU) /((uint32_t)MEGA * (uint32_t)TIMER1_PRESCALER_CFG))
         
   
#define TIMER1_CALCULATE_US_TIME_TO_TICKS(usTime)        \
	     ((uint16_t)((usTime) * TIMER1_FREQUENCY_FACTOR))



typedef enum 
{
   TIMER1_CAPTURE_FALLING_EDGE           = 0u,
   TIMER1_CAPTURE_RISING_EDGE            = 1u 
}Timer1_InputCaptureEdge_t;

typedef struct  
{
   uint16_t count;
   uint32_t overflow;
   
}Timer1_Time_t;


void Timer1_Init(void);

void Timer1_WaitUsHard(uint16_t usTime);

uint16_t Timer1_GetCounterValueUs(void);

uint16_t Timer1_CalculateActualTimeDiff(Timer1_Time_t* diffTime);

TIMER1_INLINE void Timer1_GetCount(Timer1_Time_t *ptr);

uint16_t Timer1_CalculateTimeDiffBetweenTimes(Timer1_Time_t *oTime,Timer1_Time_t *nTime);

TIMER1_INLINE volatile uint32_t Timer1_GetOverflowCount(void);

TIMER1_INLINE void Timer1_GetInputCaptureCount(Timer1_Time_t *ptr);

TIMER1_INLINE void Timer1_CaptureEdge(Timer1_InputCaptureEdge_t edge);

TIMER1_INLINE Timer1_InputCaptureEdge_t Timer1_GetCapturedEdge(void);




#if TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_1
   #define TIMER1_PRESCALER_CALC_VALUE					   ((uint16_t)1u)
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_8
   #define TIMER1_PRESCALER_CALC_VALUE					   ((uint16_t)8u)
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_64  
   #define TIMER1_PRESCALER_CALC_VALUE					  ((uint16_t)64u)
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_256 
   #define TIMER1_PRESCALER_CALC_VALUE					 ((uint16_t)256u)
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_1024
   #define TIMER1_PRESCALER_CALC_VALUE					((uint16_t)1024u)
#else
   #error "!!!Prescaler not defined!!!"
#endif



#endif /* TIMER1_H_ */
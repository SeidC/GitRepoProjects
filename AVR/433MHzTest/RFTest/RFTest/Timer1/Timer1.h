/*
 * Timer1.h
 *
 * Created: 12.10.2016 23:12:38
 *  Author: AP02
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "Timer1_Cfg.h"
#include "avr/io.h"


#define  TIMER1_HAS_TIMER_OVERFLOW()				\
		 ((TIFR & (1 << TOV1)) >> TOV1)

#define TIMER1_COUNTER_MAX							\
		(INT16_MAX)

#define TIMER1_GET_ACTUAL_COUNTER_VALUE()			\
		((uint16_t)TCNT1)
		
#define TIMER1_CHECK_TIMER_OVERFLOW(valueToCheck)	\
		((TCNT1 + (uint32_t)valueToCheck) > TIMER1_COUNTER_MAX)
		
#define TIMER1_RESET_OVERFLOW()						\
		((TIFR &= ~(1 << TOV1)))
		
		
void Timer1_Init(void);
uint16_t Timer1_CalculateUsTimeValue(uint16_t usTime);


#endif /* TIMER1_H_ */
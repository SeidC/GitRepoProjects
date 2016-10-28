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

uint16_t Timer1_GetCounterValueUs(void);



#if TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_1
#define TIMER1_PRESCALER_CALC_VALUE					1
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_8
#define TIMER1_PRESCALER_CALC_VALUE					8
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_64  
#define TIMER1_PRESCALER_CALC_VALUE					64
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_256 
#define TIMER1_PRESCALER_CALC_VALUE					256
#elif TIMER1_PRESCALER_CFG == TIMER1_PRESCALER_1024
#define TIMER1_PRESCALER_CALC_VALUE					1024
#else
#error "!!!Prescaler not defined!!!"
#endif



#endif /* TIMER1_H_ */
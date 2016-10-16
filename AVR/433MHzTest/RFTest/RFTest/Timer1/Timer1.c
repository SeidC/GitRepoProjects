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

uint16_t Timer1_CalculateUsTimeValue(uint16_t usTime) 
{
	return (usTime * 100.000)/F_CPU;
}

void Timer1_WaitUs(uint16_t usTime)
{
	uint16_t duration; boolean exit = FALSE;
	boolean overflow;
	
	usTime = Timer1_CalculateUsTimeValue(usTime);
	
	if (TIMER1_CHECK_TIMER_OVERFLOW(usTime) == TRUE)
	{
		duration = usTime - TIMER1_COUNTER_MAX + TIMER1_GET_ACTUAL_COUNTER_VALUE();
		overflow = TRUE;
	}
	else
	{
		duration  = TIMER1_GET_ACTUAL_COUNTER_VALUE() + usTime;
		overflow = FALSE;
	}
	
	while (exit == FALSE)
	{
		if(overflow == FALSE)
		{
			if(TIMER1_GET_ACTUAL_COUNTER_VALUE() > duration)
			{
				exit = TRUE;
			}
		}
		else
		{
			if(TIMER1_HAS_TIMER_OVERFLOW() == TRUE)
			{
				if(TIMER1_GET_ACTUAL_COUNTER_VALUE() > duration)
				{
					exit = TRUE;
					TIMER1_RESET_OVERFLOW();					
				}	
			}
		}
	}
}
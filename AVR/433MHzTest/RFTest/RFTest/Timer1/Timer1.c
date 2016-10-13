/*
 * Timer1.c
 *
 * Created: 12.10.2016 23:12:19
 *  Author: AP02
 */ 

#include "Timer1.h"
#include "avr/io.h"

void Timer1_Init(void)
{
	TCCR1A = TIMER1_CONTROL_A_REGISTER;
	TCCR1B = TIMER1_CONTROL_B_REGISTER;
}


void Timer1_WaitUs(uint16_t us)
{
	uint16_t start; 
	
	start = TCNT1;
	while 
}
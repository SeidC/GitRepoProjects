/*
 * RFTest.c
 *
 * Created: 07.10.2016 23:48:52
 * Author : AP
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "USART.h"
#include "Timer1.h"
#include "Easy.h"


uint16_t buff[11] = {};


int main(void)
{
	uint8_t transmit = 0;
	PIND = 0x00;
	PORTD = 0x00;
	DDRD = 0x00;
	Easy_Init();
	Timer1_Init();
	sei();
    /* Replace with your application code */
	//Easy_TransmitSyncField();
	
	
	while (1) 
    {
		if(transmit == 1)
		{
			Easy_TransmitChar("A");
			transmit = 0;	
		}
		Easy_RxMainfunction();	
    }
}


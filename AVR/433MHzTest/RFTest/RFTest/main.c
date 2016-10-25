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


uint16_t buff[11] = {};


int main(void)
{
	Easy_Init();
	Timer1_Init();
	char x = 0xAA;
    /* Replace with your application code */
    while (1) 
    {
		Easy_TransmitSyncField();
		Easy_TransmitString("Hello World",11,buff);
		_delay_ms(500);
    }
}


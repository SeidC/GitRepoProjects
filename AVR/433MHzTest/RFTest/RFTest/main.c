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


int main(void){
 
   DDRB = 0xff;
   PORTB = 0x00;
   
	Easy_Init(&Easy_config);
   TCCR1B |= (1 << ICES1);
	Timer1_Init();
	sei();
    /* Replace with your application code */
	//Easy_TransmitSyncField();
	
	
	while (1) 
    {
      Easy_TransmissionStart();         
       
    }
}


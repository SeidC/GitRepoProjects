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


int main(void){
	
	uint16_t index = TIMER1_CALCULATE_US_TIME_TO_TICKS(100);
	uint8_t transmit = 0;
   
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
  
		//if(transmit == 1)
		{
         //Easy_TransmissionStart();
			//Easy_TransmitChar(0x85);
			//transmit = 0;	
         PORTD |= (1 << PIND1);
         Timer1_WaitUsHard(50);
         PORTD &= ~(1 << PIND1);
         Timer1_WaitUsHard(50);
         
		}
		//Easy_RxMainfunction();	
      
     
    }
}


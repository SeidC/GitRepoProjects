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
 
   Timer1_Init();
	Easy_Init(&Easy_config);
	TCCR1B |= (1 << ICES1);
   	
	
	while (1) 
   {
      Easy_TransmissionStart();      
      Easy_TransmitChar("A");      
   }
}


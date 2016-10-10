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


USART_Config_t config =
{
	.rxEnableConfig		= USART_ENABLE,
	.txEnableConfig		= USART_ENABLE,
	.parityConfig		= USART_EVEN_PARITY,
	.stopBitConfig		= USART_USE_2_STOP_BIT,
	.dataSizeConfig		= USART_8_BIT_DATA_SIZE,
	.transmitionConfig  = USART_USE_ASYNCHRONOUS_MODE,
	.ubrrValueConfig	= USART_BAUDRATE,
};





int main(void)
{
	Easy_Init();
	
    /* Replace with your application code */
    while (1) 
    {
		Easy_TransmitChar("a");
		
    }
}


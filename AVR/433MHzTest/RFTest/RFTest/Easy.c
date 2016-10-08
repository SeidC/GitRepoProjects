/*
 * Easy.c
 *
 * Created: 08.10.2016 00:58:41
 *  Author: AP
 */ 
#include "Easy.h"
#include "avr/io.h"
#include "avr/delay.h"

#define DDR_ADDRESS_OFFSET				-1


#define EASY_GET_DDR_REGISTER(port)				\
		((volatile uint8_t*)(port + DDR_ADDRESS_OFFSET))
		
#define EASY_SET_BIT(reg,bit)					\
		(reg |= (1<<bit))
		
#define EASY_RESET_BIT(reg,bit)					\
		(reg &= ~(1 << bit))


#define EASY_TRANSMIT_TIME_US					\
		(EASY_BYTE_TRANSMIT_TIME_MS  * 1000)
		
		
#define EASY_BIT_TRANSMIT_TIME_US				\
		(EASY_TRANSMIT_TIME_US / 8)	
		
#define EASY_GET_TRASMIT_PORT()					\
		((volatile uint8_t*) (EASY_TX_PORT))

#define EASY_GET_TRANSMIT_PIN()					\
		(EASY_TX_PIN)
		
void Easy_Init(void)
{
	volatile uint8_t *ddrPortRx, *ddrPortTx;
	
	ddrPortRx = EASY_GET_DDR_REGISTER(EASY_RX_PORT);
	ddrPortTx =  EASY_GET_DDR_REGISTER(EASY_TX_PORT);
	
	EASY_SET_BIT(*ddrPortTx,EASY_TX_PIN);
	EASY_RESET_BIT(*ddrPortRx,EASY_RX_PIN);
	
	return;
}


void Easy_TransmitChar(char p)
{
	volatile uint8_t *port;
	uint8_t i = 0, pin = 0;
	
	port = EASY_GET_TRASMIT_PORT();
	pin  = EASY_GET_TRANSMIT_PIN();
	for (i = 0; i < 8; i++)
	{
		(p & (1 << i) < 0) ? EASY_SET_BIT(*port,pin) : EASY_RESET_BIT(*port,pin);
		_delay_us(EASY_BIT_TRANSMIT_TIME_US);
	}
}
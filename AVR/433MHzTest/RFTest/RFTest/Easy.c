/*
 * Easy.c
 *
 * Created: 08.10.2016 00:58:41
 *  Author: AP
 */ 
#include "Easy.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "Manchester.h"

#define DDR_ADDRESS_OFFSET				-1


#define EASY_GET_DDR_REGISTER(port)				\
		((volatile uint8_t*)(port + DDR_ADDRESS_OFFSET))
		
#define EASY_SET_BIT(reg,bit)					\
		(reg |= (1<<bit))
		
#define EASY_RESET_BIT(reg,bit)					\
		(reg &= ~(1 << bit))


#define EASY_GET_US_DELAY()						\
		(1000 / EASY_TRANSMIT_TICKS_PER_MS )

		
void Easy_Init(void)
{
	EASY_SET_BIT(EASY_TX_DDR,EASY_TX_PIN);
	EASY_RESET_BIT(EASY_RX_DDR,EASY_RX_PIN);
	EASY_SET_BIT(EASY_TX_PORT,EASY_TX_PIN);
	
	return;
}




void Easy_TransmitChar(char p)
{
	uint8_t i = 0, tick;
	uint8_t buffer[MANCHESTER_CALCULATE_DATA_SIZE(1)];
	
	Manchester_t tData = {
		buffer,
		0,
	};
	
	Manchester_EncodeChar(p,&tData);
	
	for (i = 0; i < tData.sizeOfTicks; i++)
	{
		tick = Manchester_GetTick(&tData);
		if (tick == 1)
			EASY_TX_PORT |= (1 << EASY_TX_PIN);
		else
			EASY_TX_PORT &= ~(1 << EASY_TX_PIN);
			
		_delay_us(EASY_GET_US_DELAY());
	}
	EASY_SET_BIT(EASY_TX_PORT,EASY_TX_PIN);
	return;
}
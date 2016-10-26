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
#include "avr/interrupt.h"


#define EASY_GET_DDR_REGISTER(port)				\
		((volatile uint8_t*)(port -1))

#define EASY_GET_PIN_REGISTER(port)				\
	   ((volatile uint8_t*)(port -2))

#define EASY_SET_BIT(reg,bit)					\
		(reg |= (1<<bit))
		
#define EASY_RESET_BIT(reg,bit)					\
		(reg &= ~(1 << bit))

#define EASY_GET_BIT(reg,bit)					\
		((reg & (1 << bit)) >> bit)

#define EASY_GET_US_DELAY()						\
		(250)

#define EASY_SYNC_SIGN							((char)0x55u)

volatile uint8_t Easy_oldEdge;
volatile uint8_t Easy_currentEdge;
volatile uint8_t av[30];
volatile uint8_t index = 0;
void Easy_Init(void)
{
	EASY_SET_BIT(EASY_TX_DDR,EASY_TX_PIN);
	EASY_SET_BIT(EASY_TX_PORT,EASY_TX_PIN);
	
	EASY_RESET_BIT(EASY_RX_DDR,EASY_RX_PIN);
	EASY_SET_BIT(EASY_RX_PORT,EASY_RX_PIN);
	
	EASY_RX_INTERRUPT_REG_A |= EASY_RX_INTERRUPT_EDGE_CONFIG;		
	EASY_RX_INTERRUPT_REG_B |= EASY_RX_INTERRUPT_ENABLE;
	if(EASY_RX_INTERRUPT_ENABLE)
	{
		sei();
	}	
	return;
}

void Easy_TransmitChar(char p)
{
	uint8_t i = 0, tick;
	uint16_t buffer = 0;
	Manchester_t tData = {&buffer,0,0};
	
	Manchester_EncodeChar(p,&tData);
	
	MANCHESTER_SET_TICK_POS_TO_START(&tData);
	
	for (i = 0; i < tData.sizeOfTicks; i++)
	{
		tick = Manchester_GetTick(&tData);
		if (tick == 1)
			EASY_SET_TX();
		else
			EASY_CLEAR_TX();
		//tick == 1 ? EASY_SET_TX() : EASY_CLEAR_TX();
		_delay_us(EASY_GET_US_DELAY());
	}
	EASY_SET_BIT(EASY_TX_PORT,EASY_TX_PIN);
	return;
}


void Easy_TransmitString(char* string, uint8_t stringLength, uint16_t* buffer)
{
	uint16_t i;
	uint8_t tick;
	Manchester_t data = {buffer,0,0};
		
	Manchester_EncodeString(string,stringLength,&data);
	for (i = 0; i < data.sizeOfTicks; i++)
	{
		tick = Manchester_GetTick(&data);
		tick == 1 ? EASY_SET_TX() : EASY_CLEAR_TX();
		_delay_us(EASY_GET_US_DELAY());
	}
	EASY_SET_BIT(EASY_TX_PORT,EASY_TX_PIN);
	return;
}

void Easy_TransmitSyncField(void)
{
	Easy_TransmitChar(EASY_SYNC_SIGN);
	return;
}

ISR(EASY_RX_INTERRUPT)
{
	volatile uint8_t* pinReg = EASY_GET_PIN_REGISTER(&EASY_RX_PORT);
	
	av[index] = EASY_GET_BIT(*pinReg,EASY_RX_PIN);
	index++;
}
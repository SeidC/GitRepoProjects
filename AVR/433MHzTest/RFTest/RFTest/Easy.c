/*
 * Easy.c
 *
 * Created: 08.10.2016 00:58:41
 *  Author: AP
 */ 
#include "Easy.h"
#include "Manchester.h"
#include "FiFo8.h"
#include "FiFo16.h"


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
		(EASY_TX_EDGE_US_DELAY)
		
#define EASY_SET_RX_EXTERN_INDICATION()			\		
		(Easy_rxIndication = EASY_EXTERN_RX)
		
#define EASY_SET_RX_INTERN_INDICATION()			\
		(Easy_rxIndication = EASY_INTERN_RX)
		
#define EASY_IS_RX_EXTERN_INDICATION()			\
		(Easy_rxIndication == EASY_EXTERN_RX)

#define EASY_IS_RX_INTERN_INDICATION()			\
		(Easy_rxIndication == EASY_INTERN_RX)

#define EASY_RX_MIN_EDGE_TIME					\		
		(EASY_RX_EDGE_US_TIME - EASY_RX_NEG_US_TIME_OFFSET)
		
#define EASY_RX_MAX_EDGE_TIME					\		
		(EASY_RX_EDGE_US_TIME + EASY_RX_POS_US_TIME_OFFSET)		

static uint8_t Easy_edgeBuffer[EASY_RX_BUFFER_SIZE] = {};
static uint16_t Easy_timeBuffer[EASY_RX_BUFFER_SIZE] = {};
static const volatile FIFO8_Buffer_t Easy_RxEdgeBuffer = {};
static const volatile FIFO16_Buffer_t Easy_RxTimeBuffer = {};
volatile static Easy_RxIndication_t Easy_rxIndication;

void Easy_Init(void)
{
	EASY_SET_BIT(EASY_TX_DDR,EASY_TX_PIN);
	EASY_SET_BIT(EASY_TX_PORT,EASY_TX_PIN);
	
	EASY_RESET_BIT(EASY_RX_DDR,EASY_RX_PIN);
	EASY_SET_BIT(EASY_RX_PORT,EASY_RX_PIN);
	
	EASY_RX_INTERRUPT_REG_A |= EASY_RX_INTERRUPT_EDGE_CONFIG;		
	EASY_RX_INTERRUPT_REG_B |= EASY_RX_INTERRUPT_ENABLE_CONFIG;
	if(EASY_RX_INTERRUPT_ENABLE)
	{
		sei();
	}
	FIFO8_InitBuffer(&Easy_RxEdgeBuffer,Easy_edgeBuffer,EASY_RX_BUFFER_SIZE);
	FIFO16_InitBuffer(&Easy_RxTimeBuffer,Easy_timeBuffer,EASY_RX_BUFFER_SIZE);
	Easy_rxIndication = EASY_NO_INDICATION;
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
		{
			EASY_SET_TX();
		}
		else
		{
			EASY_CLEAR_TX();
		}
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
	EASY_SET_RX_INTERN_INDICATION();
	Easy_TransmitChar(EASY_SYNC_SIGN);
	return;
}

void Easy_RxMainfunction(void)
{
	
}

ISR(EASY_RX_INTERRUPT_VECTOR_CONFIG)
{
	volatile uint8_t* pinReg = EASY_GET_PIN_REGISTER(&EASY_RX_PORT);
	FIFO16_Write(&Easy_RxTimeBuffer,EASY_GET_TIME());

	FIFO8_Write(&Easy_RxEdgeBuffer,EASY_GET_BIT(*pinReg,EASY_RX_PIN));

}
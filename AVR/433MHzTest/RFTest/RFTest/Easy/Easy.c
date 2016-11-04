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

/*--- Local Defines -----------------------------------------------------------*/
#define EASY_SET_BIT(reg,bit)					\
		(reg |= (1<<bit))
		
#define EASY_RESET_BIT(reg,bit)					\
		(reg &= ~(1 << bit))

#define EASY_GET_BIT(reg,bit)					\
		((reg & (1 << bit)) >> bit)

#define EASY_GET_US_DELAY()						\
		(internalCfg->txBaudrate)
		
#define EASY_RX_MIN_EDGE_TIME					\
      (internalCfg->rxEdgeTime - internalCfg->rxNegOffset)
		
#define EASY_RX_MAX_EDGE_TIME					\
      (internalCfg->rxEdgeTime + internalCfg->rxPosOffset)		

#define EASY_SET_TX_TO_DEFAULT()          \
        (EASY_CLEAR_TX())

/*--- Local Parameter ---------------------------------------------------------*/

/**
 *                                                                      
 */
static uint16_t Easy_edgeBuffer[EASY_RX_BUFFER_SIZE] = {};

/**
 *                                                                      
 */
static uint16_t Easy_timeBuffer[EASY_RX_BUFFER_SIZE] = {};

/**
 *                                                                      
 */
EASY_VOL_STAT FIFO16_Buffer_t Easy_RxEdgeBuffer = {};

/**
 *                                                                      
 */
EASY_VOL_STAT FIFO16_Buffer_t Easy_RxTimeBuffer = {};

/**
 *                                                                      
 */
EASY_VOL_STAT Easy_RxStatus_t Easy_rxStatus;

/**
 *
 */
EASY_VOL_STAT Easy_Config_t* internalCfg = NULL;




void Easy_Init(Easy_Config_t *cftPtr)
{
   internalCfg = cftPtr;
	EASY_SET_BIT(EASY_TX_DDR,EASY_TX_PIN);
   EASY_RESET_BIT(EASY_RX_DDR,EASY_RX_PIN);
   EASY_SET_TX_TO_DEFAULT();
	
	EASY_RX_INTERRUPT_REG_A |= EASY_RX_INTERRUPT_EDGE_CONFIG;		
	EASY_RX_INTERRUPT_REG_B |= EASY_RX_INTERRUPT_ENABLE_CONFIG;
	if(EASY_RX_INTERRUPT_ENABLE)
	{
		sei();
	}
	FIFO16_InitBuffer(&Easy_RxEdgeBuffer,Easy_edgeBuffer,EASY_RX_BUFFER_SIZE);
	FIFO16_InitBuffer(&Easy_RxTimeBuffer,Easy_timeBuffer,EASY_RX_BUFFER_SIZE);
	
	Easy_rxStatus.indication = EASY_NO_INDICATION;

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
	return;
}

void Easy_TransmitSyncField(void)
{
	Easy_TransmitChar(EASY_SYNC_SIGN);
	return;
}

void Easy_RxMainfunction(void)
{
  }


bool_t Easy_GetReceivedData(uint8_t *buffer)
{

}


InterruptRoutine(EASY_RX_INTERRUPT_VECTOR_CONFIG)
{
    Easy_RxInterruptRoutine();
}


void Easy_TransmissionStart(void)
{
   volatile uint8_t *pin = GET_PIN_REG_PTR_BY_PORT(EASY_RX_PORT);
   if(Easy_rxStatus.indication == EASY_NO_INDICATION)
   {
      Easy_rxStatus.lastBit = 0;
      EASY_SET_TX();
      _delay_us(200);
   }
   return;
}

EASY_INLINE void Easy_RxInterruptRoutine(void)
{
   uint8_t* pin = GET_PIN_REG_PTR_BY_PORT(EASY_RX_PORT);
   uint8_t cBit = EASY_GET_BIT(*pin,EASY_RX_PIN);

   
   if(Easy_rxStatus.indication == EASY_NO_INDICATION)
   {
      Easy_rxStatus.startTime = EASY_GET_TIME();
      Easy_rxStatus.indication = EASY_RX_PRE_START;
   }
   
   if (Easy_rxStatus.bitCount < MANCHESTER_GET_MSG_BIT_SIZE())
   {
      if((Easy_rxStatus.lastBit == 0) && (cBit == 1))
      {
         Easy_rxStatus.bitBuffer |= (MANCHESTER_RISING_EDGE << Easy_rxStatus.bitCount);
      }
      else if((Easy_rxStatus.lastBit == 1) && (cBit == 0))
      {
         Easy_rxStatus.bitBuffer |= (MANCHESTER_FALLING_EDGE << Easy_rxStatus.bitCount);         
      }
      else
      {
         __asm("NOP");
      }
      Easy_rxStatus.bitCount += MANCHESTER_BITS_PER_EDGE;
   }
   
   if (Easy_rxStatus.bitCount >= MANCHESTER_GET_MSG_BIT_SIZE())
   {
      FIFO16_Write(&Easy_RxEdgeBuffer,Easy_rxStatus.bitBuffer);
      Easy_rxStatus.bitBuffer = 0;
      Easy_rxStatus.bitCount = 0;
   }      
   Easy_rxStatus.lastBit = cBit;     
}
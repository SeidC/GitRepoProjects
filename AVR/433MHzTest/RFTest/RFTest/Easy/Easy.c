/*
 * Easy.c
 *
 * Created: 08.10.2016 00:58:41
 *  Author: AP
 */ 
#include "Easy.h"
#include "Easy_RxFsm.h"
#include "Manchester.h"
#include "FiFo8.h"
#include "FiFo16.h"

/*--- Local Defines -----------------------------------------------------------*/
#define EASY_SET_BIT(reg,bit)					\
		  (reg |= (1<<bit))
		
#define EASY_RESET_BIT(reg,bit)					\
		  (reg &= ~(1 << bit))

#define EASY_GET_BIT(reg,bit)					            \
		  ((reg & (1 << bit)) >> bit)

#define EASY_GET_US_DELAY()						         \
		  (internalCfg->txBaudrate)

#define EASY_SET_TX_TO_DEFAULT()                      \
        (EASY_CLEAR_TX())

/*--- Defines for Received Edges ---------------------------------------------------*/		

#define EASY_RX_MIN_EDGE_TIME					            \
        (internalCfg->rxEdgeTime - internalCfg->rxNegOffset)
		
#define EASY_RX_MAX_EDGE_TIME					            \
        (internalCfg->rxEdgeTime + internalCfg->rxPosOffset)		

#define EASY_IS_RX_EDGE_IN_TIME(t)                    \
        ((t >= EASY_RX_MIN_EDGE_TIME) && (t <= EASY_RX_MAX_EDGE_TIME))

/*--- Defines for StartUp ----------------------------------------------------------*/
#define EASY_START_UP_MIN_TIME                        \
        (internalCfg->startTime - internalCfg->startMinTimeOffset)

#define EASY_START_UP_MAX_TIME                        \
        (internalCfg->startTime + internalCfg->startMaxTimeOfset)

#define EASY_IS_START_UP_IN_TIME(t)                   \
        ((t >= EASY_START_UP_MIN_TIME) && (t <= EASY_START_UP_MAX_TIME))
/*--- Defines for StartUp with First Received Edge----------------------------------*/
#define EASY_START_UP_RX_EDGE_MIN_TIME                \
        (internalCfg->startTime + EASY_RX_MIN_EDGE_TIME)

#define EASY_START_UP_RX_EDGE_MAX_TIME                \
        (internalCfg->startTime + EASY_RX_MAX_EDGE_TIME)

#define EASY_IS_START_UP_W_RX_EDGE_IN_TIME(t)         \
         ((t >= EASY_START_UP_RX_EDGE_MIN_TIME) && (t <= EASY_START_UP_RX_EDGE_MAX_TIME))
/*--- Local Parameter ---------------------------------------------------------*/

/**
 *                                                                      
 */
static uint16_t Easy_edgeBuffer[EASY_RX_BUFFER_SIZE] = {};

/**
 *                                                                      
 */
EASY_VOL_STAT FIFO16_Buffer_t Easy_RxEdgeBuffer = {};

/**
 *                                                                      
 */
EASY_VOL_STAT Easy_RxStatus_t Easy_rxStatus;

/**
 *
 */
EASY_VOL_STAT Easy_Config_t* Easy_internalCfg = NULL;


EASY_VOL EASY_RXFSM_EVENT_T msg;

EASY_VOL EASY_RXFSM_INSTANCEDATA_T Easy_rxFsm;
 
void Easy_Init(Easy_Config_t *cftPtr)
{
   Easy_internalCfg = cftPtr;
	EASY_SET_BIT(EASY_TX_DDR,EASY_TX_PIN);
   EASY_RESET_BIT(EASY_RX_DDR,EASY_RX_PIN);
   EASY_SET_TX_TO_DEFAULT();
   
	Easy_RxFsmResetMachine(&Easy_rxFsm);   
   FIFO16_InitBuffer(&Easy_RxEdgeBuffer,Easy_edgeBuffer,EASY_RX_BUFFER_SIZE);
   
	EASY_RX_INTERRUPT_REG_A |= EASY_RX_INTERRUPT_EDGE_CONFIG;		
	EASY_RX_INTERRUPT_REG_B |= EASY_RX_INTERRUPT_ENABLE_CONFIG;
	if(EASY_RX_INTERRUPT_ENABLE)
	{
		sei();
	}
		
	//Easy_rxStatus.indication = EASY_NO_INDICATION;

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
    uint8_t* pin = GET_PIN_REG_PTR_BY_PORT(EASY_RX_PORT);
    Easy_rxStatus.nBit = EASY_GET_BIT(*pin,EASY_RX_PIN);    
    
    Easy_RxFsm(&Easy_rxFsm);
    
    Easy_rxStatus.oBit = Easy_rxStatus.nBit;
}


void Easy_TransmissionStart(void)
{
   volatile uint8_t *pin = GET_PIN_REG_PTR_BY_PORT(EASY_RX_PORT);
   if(Easy_RxFsmIsInEasy_RxNoIndicationState(&Easy_rxFsm))
   {
      EASY_SET_TX();
      _delay_us(200);
   }
   return;
}

EASY_INLINE void Easy_RxInterruptRoutine(void)
{
   /*
   uint8_t* pin = GET_PIN_REG_PTR_BY_PORT(EASY_RX_PORT);
   uint8_t cBit = EASY_GET_BIT(*pin,EASY_RX_PIN);
   uint8_t oBit = Easy_rxStatus.lastBit;
   
   if(Easy_rxStatus.indication == EASY_NO_INDICATION)
   {
      if(MANCHESTER_IS_RISNG_EDGE(oBit,cBit) == TRUE)
      {
         Easy_rxStatus.startTime = EASY_GET_TIME();
         Easy_rxStatus.indication = EASY_RX_PRE_START;
      }
      else
      {
         
      }      
   }
   else if(Easy_rxStatus.indication == EASY_RX_PRE_START)
   {
      if(MANCHESTER_IS_FALLING_EDGE(oBit,cBit) == TRUE)
      {
         
      }
      else
      {
         
      }
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
   Easy_rxStatus.oBit = nBit;   
   */      
}


EASY_INLINE void Easy_SetFsmSignal(EASY_RXFSM_EVENT_T signal)
{
   msg = signal;
   return;
}


EASY_INLINE void Easy_RxNoIndication(void)
{
    if(MANCHESTER_IS_RISNG_EDGE(Easy_rxStatus.oBit,Easy_rxStatus.nBit) == TRUE)
    {
       Easy_rxStatus.startTime = EASY_GET_TIME();
       Easy_SetFsmSignal(EASY_RX_PRE_START);
    }
    else
    {
       /*--- Do Nothing ---*/
    }
    return;  
}

EASY_INLINE void Easy_RxFinished(void)
{
 
}   

EASY_INLINE void Easy_RxPreStart(void)
{
   uint16_t timeDiff = 0;
   if(MANCHESTER_IS_FALLING_EDGE(Easy_rxStatus.oBit,Easy_rxStatus.nBit) == TRUE)
   {
      timeDiff = EASY_CALCULATE_TIME_DIFF(Easy_rxStatus.startTime);
      if(EASY_IS_START_UP_IN_TIME(timeDiff))
      {
         Easy_SetFsmSignal(EASY_RX_RECEIVE);
      }
      else if(EASY_IS_START_UP_W_RX_EDGE_IN_TIME(timeDiff))
      {
         if(Easy_rxStatus.bitCount == 0)
         {
            Easy_rxStatus.bitBuffer |= (MANCHESTER_FALLING_EDGE << Easy_rxStatus.bitCount);
            Easy_rxStatus.bitCount += MANCHESTER_BITS_PER_EDGE;
            Easy_SetFsmSignal(EASY_RX_RECEIVE);
         }
         else
         {
            /*--- Error ---*/
            //Easy_SetFsmSignal(EASY_RX_ERROR);
         }
         
      }
      else
      {
         /*--- Error ---*/  
         //Easy_SetFsmSignal(EASY_RX_ERROR);
      }
   }
   else
   {
      /*--- Error ---*/
      //Easy_SetFsmSignal(EASY_RX_ERROR);
   }
   return;
}

EASY_INLINE void Easy_RxReceiveError(void)
{
   
}

EASY_INLINE void Easy_RxReceive(void)
{
   
}
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
		  (Easy_internalCfg->txBaudrate)

#define EASY_SET_TX_TO_DEFAULT()                      \
        (EASY_CLEAR_TX())

/*--- Defines for Received Edges ---------------------------------------------------*/		

#define EASY_RX_MIN_EDGE_TIME					            \
        (Easy_internalCfg->rxEdgeTime - Easy_internalCfg->rxNegOffset)
		
#define EASY_RX_MAX_EDGE_TIME					            \
        (Easy_internalCfg->rxEdgeTime + Easy_internalCfg->rxPosOffset)		

#define EASY_IS_RX_EDGE_IN_TIME(t)                    \
        ((t >= EASY_RX_MIN_EDGE_TIME) && (t <= EASY_RX_MAX_EDGE_TIME))

/*--- Defines for Received Edges ---------------------------------------------------*/	

#define EASY_RX_MIN_EDGES_TIME					            \
        ((Easy_internalCfg->rxEdgeTime * 2) - Easy_internalCfg->rxNegOffset)

#define EASY_RX_MAX_EDGES__TIME					            \
        ((Easy_internalCfg->rxEdgeTime * 2) + Easy_internalCfg->rxPosOffset)

#define EASY_ARE_RX_EDGES_IN_TIME(t)                    \
((t >= EASY_RX_MIN_EDGES_TIME) && (t <= EASY_RX_MAX_EDGES__TIME))

/*--- Defines for StartUp ----------------------------------------------------------*/
#define EASY_START_UP_MIN_TIME                        \
        (Easy_internalCfg->startTime - Easy_internalCfg->startMinTimeOffset)

#define EASY_START_UP_MAX_TIME                        \
        (Easy_internalCfg->startTime + Easy_internalCfg->startMaxTimeOfset)

#define EASY_IS_START_UP_IN_TIME(t)                   \
        ((t >= EASY_START_UP_MIN_TIME) && (t <= EASY_START_UP_MAX_TIME))
/*--- Defines for StartUp with First Received Edge----------------------------------*/
#define EASY_START_UP_RX_EDGE_MIN_TIME                \
        (Easy_internalCfg->startTime + EASY_RX_MIN_EDGE_TIME)

#define EASY_START_UP_RX_EDGE_MAX_TIME                \
        (Easy_internalCfg->startTime + EASY_RX_MAX_EDGE_TIME)

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




static void Easy_ReportError(EASY_RXFSM_STATES_T state, uint8_t instanceId);
EASY_INLINE void Easy_BackUpTime(Timer1_Time_t* oTime,Timer1_Time_t* nTime);

EASY_INLINE EASY_RXFSM_STATES_T Easy_GetFsmState(void);

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
    
   EASY_GET_TIME(&Easy_rxStatus.nTime);  
   if (Easy_GetFsmState() != Easy_RxNoIndicationState)
   {
      Easy_rxStatus.timeDiff = EASY_CALCULATE_TIME_DIFF(&Easy_rxStatus.oTime,&Easy_rxStatus.nTime);   
   }
    
    
   Easy_RxFsm(&Easy_rxFsm);
    
   Easy_rxStatus.oBit = Easy_rxStatus.nBit;
   Easy_BackUpTime(&Easy_rxStatus.oTime,&Easy_rxStatus.nTime);
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


EASY_INLINE void Easy_SetFsmSignal(EASY_RXFSM_EVENT_T signal)
{
   msg = signal;
   return;
}


EASY_INLINE void Easy_RxNoIndication(void)
{
    if(MANCHESTER_IS_RISNG_EDGE(Easy_rxStatus.oBit,Easy_rxStatus.nBit) == TRUE)
    {
      Easy_SetFsmSignal(EASY_RX_PRE_START);
    }
    else
    {
       Easy_ReportError(Easy_rxFsm.stateVar,0);
    }
    return;  
}

EASY_INLINE void Easy_RxFinished(void)
{
 
}   

EASY_INLINE void Easy_RxPreStart(void)
{
   if(MANCHESTER_IS_FALLING_EDGE(Easy_rxStatus.oBit,Easy_rxStatus.nBit) == TRUE)
   {
      if(EASY_IS_START_UP_W_RX_EDGE_IN_TIME(Easy_rxStatus.timeDiff))
      {
         if(Easy_rxStatus.bitCount == 0)
         {
            Easy_rxStatus.bitBuffer |= (MANCHESTER_FALLING_EDGE << Easy_rxStatus.bitCount);
            Easy_rxStatus.bitCount += MANCHESTER_BITS_PER_EDGE;
            Easy_SetFsmSignal(EASY_RX_RECEIVE);
         }
         else
         {
            Easy_ReportError(Easy_rxFsm.stateVar,0);
         }         
      }
      else if (EASY_IS_START_UP_W_RX_EDGE_IN_TIME(Easy_rxStatus.timeDiff) == TRUE)
      {
         /*--- DO NOTHING ---*/
      }
      else
      {
         Easy_ReportError(Easy_rxFsm.stateVar,1);
      }
   }
   else
   {
      if(EASY_IS_RX_EDGE_IN_TIME(Easy_rxStatus.timeDiff) == TRUE)
      {
          Easy_rxStatus.bitBuffer |= (MANCHESTER_RISING_EDGE << Easy_rxStatus.bitCount);
          Easy_rxStatus.bitCount += MANCHESTER_BITS_PER_EDGE;
          Easy_SetFsmSignal(EASY_RX_RECEIVE);
      }
      else
      {
         Easy_ReportError(Easy_rxFsm.stateVar,2);
      }
   }
   return;
}

EASY_INLINE void Easy_RxReceiveError(void)
{
   
}

EASY_INLINE void Easy_RxReceive(void)
{
   if (Easy_rxStatus.bitCount < MANCHESTER_GET_MSG_BIT_SIZE())
   {
      if(MANCHESTER_IS_RISNG_EDGE(Easy_rxStatus.oBit,Easy_rxStatus.nBit) == TRUE)
      {
         Easy_rxStatus.bitBuffer |= (MANCHESTER_RISING_EDGE << Easy_rxStatus.bitCount);
      }
      else if(MANCHESTER_IS_FALLING_EDGE(Easy_rxStatus.oBit,Easy_rxStatus.nBit) == TRUE)
      {
         Easy_rxStatus.bitBuffer |= (MANCHESTER_FALLING_EDGE << Easy_rxStatus.bitCount);
      }
      else
      {
         Easy_ReportError(Easy_rxFsm.stateVar,0);
      }
      Easy_rxStatus.bitCount += MANCHESTER_BITS_PER_EDGE;
   }
   
   if (Easy_rxStatus.bitCount >= MANCHESTER_GET_MSG_BIT_SIZE())
   {
      FIFO16_Write(&Easy_RxEdgeBuffer,Easy_rxStatus.bitBuffer);
      Easy_rxStatus.bitBuffer = 0;
      Easy_rxStatus.bitCount = 0;
   }
   return;
}

static void Easy_ReportError(EASY_RXFSM_STATES_T state, uint8_t instanceId)
{
   
   __asm("nop");
}


EASY_INLINE EASY_RXFSM_STATES_T Easy_GetFsmState(void)
{
   return Easy_rxFsm.stateVar;
}


EASY_INLINE void Easy_BackUpTime(Timer1_Time_t* oTime,Timer1_Time_t* nTime)
{
   oTime->count     = nTime->count;
   oTime->overflow  = nTime->overflow;
   return;
}
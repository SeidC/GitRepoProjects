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
		  (Easy_internalTxCfg.baudrate)

#define EASY_SET_TX_TO_DEFAULT()                      \
        (EASY_CLEAR_TX())
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
EASY_VOL_STAT Easy_Config_t Easy_internalTxCfg;

EASY_VOL_STAT Easy_Config_t Easy_internalRxCfg;

/**
 *
 */
EASY_VOL EASY_RXFSM_EVENT_T msg;

EASY_VOL EASY_RXFSM_INSTANCEDATA_T Easy_rxFsm = EASY_RXFSM_INSTANCEDATA_INIT;




static void Easy_ReportError(EASY_RXFSM_STATES_T state, uint8_t instanceId);
EASY_INLINE void Easy_BackUpTime(Timer1_Time_t* oTime,Timer1_Time_t* nTime);

void Easy_SetupConfiguration(Easy_Config_t *cftPtr);

EASY_INLINE EASY_RXFSM_STATES_T Easy_GetFsmState(void);

void Easy_Init(Easy_Config_t *cfgPtr)
{
   Easy_SetupConfiguration(cfgPtr);
   
	EASY_SET_BIT(EASY_TX_DDR,EASY_TX_PIN);
   EASY_RESET_BIT(EASY_RX_DDR,EASY_RX_PIN);
   EASY_SET_TX_TO_DEFAULT();
     
   FIFO16_InitBuffer(&Easy_RxEdgeBuffer,Easy_edgeBuffer,EASY_RX_BUFFER_SIZE);
    
   
	if(ARE_GLOBAL_INTERRUPTS_ENABLED() == 0)
	{
		sei();
	}
		
	return;
}


void Easy_SetupConfiguration(Easy_Config_t *cftPtr)
{
    Easy_internalRxCfg.baudMax =
               EASY_CONVERT_TIME(cftPtr->baudMax + EASY_RX_INTERRUPT_TIME_OFFSET);
    
    Easy_internalRxCfg.baudMin =
               EASY_CONVERT_TIME(cftPtr->baudMin + EASY_RX_INTERRUPT_TIME_OFFSET);
    
    Easy_internalRxCfg.baudrate =
               EASY_CONVERT_TIME(cftPtr->baudrate + EASY_RX_INTERRUPT_TIME_OFFSET);
    
    
    Easy_internalRxCfg.txIndicationMinTime =
               EASY_CONVERT_TIME(cftPtr->txIndicationMinTime + EASY_RX_INTERRUPT_TIME_OFFSET);
    
    Easy_internalRxCfg.txIndicationTime =
               EASY_CONVERT_TIME(cftPtr->txIndicationTime + EASY_RX_INTERRUPT_TIME_OFFSET);
    
    Easy_internalRxCfg.txIndicationMaxTime =
               EASY_CONVERT_TIME(cftPtr->txIndicationMaxTime + EASY_RX_INTERRUPT_TIME_OFFSET);
    
    
    Easy_internalTxCfg.baudMax =
               EASY_CONVERT_TIME(cftPtr->baudMax);
    
    Easy_internalTxCfg.baudMin =
               EASY_CONVERT_TIME(cftPtr->baudMin);
    
    Easy_internalTxCfg.baudrate =
               EASY_CONVERT_TIME(cftPtr->baudrate);
    
    Easy_internalTxCfg.txIndicationTime =
               EASY_CONVERT_TIME(cftPtr->txIndicationTime);
    
    Easy_internalTxCfg.txIndicationMinTime =
               EASY_CONVERT_TIME(cftPtr->txIndicationMinTime);
      
    Easy_internalTxCfg.txIndicationTime =
               EASY_CONVERT_TIME(cftPtr->txIndicationTime);
      
    Easy_internalTxCfg.txIndicationMaxTime =
               EASY_CONVERT_TIME(cftPtr->txIndicationMaxTime);
    
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
		EASY_WAIT_US(EASY_GET_US_DELAY());
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
		EASY_WAIT_US(EASY_GET_US_DELAY());
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

volatile uint8_t cnt;
volatile uint16_t diffTimes[30];
Timer1_Time_t times[30]; 


InterruptRoutine(EASY_RX_INTERRUPT_VECTOR_CONFIG)
{
    EASY_GET_TIME(&Easy_rxStatus.currentTime);    
    
    if(Easy_GetCapturedEdge() == EASY_LOW)
    {
      diffTimes[0] = EASY_CALCULATE_TIME_DIFF(&Easy_rxStatus.lastTime,&Easy_rxStatus.currentTime);
    }     
    
    
    Easy_Cfg_SwitchCapturedEdge();   
    Easy_BackUpTime(&Easy_rxStatus.lastTime,&Easy_rxStatus.currentTime);
}


void Easy_TransmissionStart(void)
{
   if(Easy_RxFsmIsInEasy_RxNoIndicationState(&Easy_rxFsm))
   {
      EASY_SET_TX();
      EASY_WAIT_US(300);
      EASY_CLEAR_TX();
   }
   return;
}


EASY_INLINE void Easy_SetFsmSignal(EASY_RXFSM_EVENT_T signal)
{
   msg = signal;
   return;
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
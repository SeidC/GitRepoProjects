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
EASY_VOL_STAT Easy_InternalConfig_t Easy_rxConfig;

EASY_VOL_STAT Easy_Config_t* Easy_txConfig = NULL;

/**
 *
 */
EASY_VOL EASY_RXFSM_EVENT_T msg = EASY_RXFSM_NO_MSG;

/**
 *
 */
EASY_VOL EASY_RXFSM_INSTANCEDATA_T Easy_rxFsm = EASY_RXFSM_INSTANCEDATA_INIT;



EASY_INLINE void Easy_InitRxFsm(void);
//EASY_INLINE void Easy_ReportError(EASY_RXFSM_STATES_T state, uint8_t instanceId);
EASY_INLINE void Easy_BackUpTime(Timer1_Time_t* oTime,Timer1_Time_t* nTime);  
EASY_INLINE void Easy_SetupConfiguration(Easy_Config_t *cfgPtr);              
EASY_INLINE EASY_RXFSM_STATES_T Easy_GetFsmState(void);
EASY_INLINE void Easy_RxInterrupt(void);



void Easy_Init(Easy_Config_t *cfgPtr)
{
   Easy_SetupConfiguration(cfgPtr);
   Easy_InitRxFsm();
   
   Easy_rxStatus.firstRxInterrupt = TRUE;
   Easy_rxStatus.currentTime.count = 0;
   Easy_rxStatus.currentTime.overflow = 0;
   Easy_rxStatus.lastTime.count = 0;
	Easy_rxStatus.lastTime.overflow = 0;
   
   EASY_SET_BIT(EASY_TX_DDR,EASY_TX_PIN);
   EASY_RESET_BIT(EASY_RX_DDR,EASY_RX_PIN);
   EASY_SET_TX_TO_DEFAULT();
     
   FIFO16_InitBuffer(&Easy_RxEdgeBuffer,Easy_edgeBuffer,EASY_RX_BUFFER_SIZE);
    
   
	if(ARE_GLOBAL_INTERRUPTS_ENABLED() == FALSE)
	{
		sei();
	}
		
	return;
}


EASY_INLINE void Easy_SetupConfiguration(Easy_Config_t *cfgPtr)
{
   if (cfgPtr != NULL)
   {
      Easy_txConfig = cfgPtr;
      Easy_rxConfig.rxMax = EASY_CONVERT_TIME(cfgPtr->baudrate + cfgPtr->jitter + EASY_RX_INTERRUPT_TIME_OFFSET);
      Easy_rxConfig.rxMin = EASY_CONVERT_TIME(cfgPtr->baudrate - cfgPtr->jitter + EASY_RX_INTERRUPT_TIME_OFFSET);
      
      Easy_rxConfig.rxMaxDouble = 2 * EASY_CONVERT_TIME(cfgPtr->baudrate + cfgPtr->jitter + EASY_RX_INTERRUPT_TIME_OFFSET);
      Easy_rxConfig.rxMinDouble = 2 * EASY_CONVERT_TIME(cfgPtr->baudrate - cfgPtr->jitter + EASY_RX_INTERRUPT_TIME_OFFSET);
      
      
      Easy_rxConfig.startMax = EASY_CONVERT_TIME(cfgPtr->indicationTime + cfgPtr->jitter + EASY_RX_INTERRUPT_TIME_OFFSET);
      Easy_rxConfig.startMin = EASY_CONVERT_TIME(cfgPtr->indicationTime - cfgPtr->jitter + EASY_RX_INTERRUPT_TIME_OFFSET);
   }
   else
   {
      Easy_txConfig = NULL;
      Easy_rxConfig.rxMax = 0;
      Easy_rxConfig.rxMin = 0;
      Easy_rxConfig.startMax = 0;
      Easy_rxConfig.startMin = 0;   
   }    
   
   return;
}

EASY_INLINE void Easy_InitRxFsm(void)
{
   Easy_RxFsmResetMachine(&Easy_rxFsm);
   msg = EASY_RXFSM_NO_MSG;
   return;
}

uint16_t buffer = 0;
Manchester_t tData = {&buffer,0,0};
void Easy_TransmitChar(char p)
{
	uint8_t i = 0, tick;	
	
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
		EASY_WAIT_US(Easy_txConfig->baudrate);
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
		EASY_WAIT_US(Easy_txConfig->baudrate);
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
    if(Easy_rxStatus.firstRxInterrupt == FALSE)
    {
      Easy_RxInterrupt();  
    }
    else
    {
       Easy_rxStatus.firstRxInterrupt = FALSE;
    }
    return;
}

volatile uint32_t diffTime = 0;
volatile EASY_RXFSM_STATES_T fsmState;
volatile uint8_t edge;
EASY_INLINE void Easy_RxInterrupt(void)
{
   EASY_GET_TIME(&Easy_rxStatus.currentTime);    
   diffTime = EASY_CALCULATE_TIME_DIFF(&Easy_rxStatus.lastTime,
                                       &Easy_rxStatus.currentTime);
   
   Easy_RxFsm(&Easy_rxFsm);
   fsmState = Easy_GetFsmState();
   edge = Easy_Cfg_GetCapturedEdge();
   switch(fsmState)
   {
      case Easy_RxReceiveState:
           if(diffTime >= Easy_rxConfig.rxMin && diffTime <= Easy_rxConfig.rxMax)
           {
              Easy_rxStatus.tickCount++;
           }
           else if(diffTime >= Easy_rxConfig.rxMinDouble && diffTime <= Easy_rxConfig.rxMaxDouble)
           {
              Easy_rxStatus.tickCount += 2;
           }
           else
           {
               asm("nop");
           }
            
            if(IS_ODD(Easy_rxStatus.tickCount))
            {
               Easy_rxStatus.bitBuffer |= (edge << Easy_rxStatus.tickCount);
            }
         
      break;
      case Easy_RxPreStartState:
           if(edge == EASY_FALLING_EDGE)
           {
              if(diffTime >= Easy_rxConfig.startMin && diffTime <= Easy_rxConfig.startMax)
              {
                  Easy_rxStatus.tickCount = 0;
                  Easy_rxStatus.bitBuffer = 0;
                  Easy_NextState(EASY_RX_RECEIVE);
              }              
           }
      break;
      case Easy_RxNoIndicationState:
         if(edge == EASY_RISING_EDGE)
         {
            Easy_NextState(EASY_RX_PRE_START);
         }
      break;
      case Easy_RxFinishedState:
      
      break;
      default:
      
      break;
   }       
   
   Easy_Cfg_SwitchCapturedEdge();   
   Easy_BackUpTime(&Easy_rxStatus.lastTime,&Easy_rxStatus.currentTime);
   return;
}

void Easy_TransmissionStart(void)
{
   if(Easy_RxFsmIsInEasy_RxNoIndicationState(&Easy_rxFsm))
   {
      EASY_SET_TX();
      EASY_WAIT_US(Easy_txConfig->indicationTime);
      EASY_CLEAR_TX();
      //EASY_WAIT_US(Easy_txConfig->baudrate);
   }
   return;
}


EASY_INLINE void Easy_NextState(EASY_RXFSM_EVENT_T state)
{
   msg = state;
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
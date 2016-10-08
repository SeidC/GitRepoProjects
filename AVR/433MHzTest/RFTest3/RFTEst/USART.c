/*
 * USART.c
 *
 * Created: 22.02.2016 18:42:36
 *  Author: AP
 */ 

#include "USART.h"
#include "FIFO.h"

#if (USART_USE_INTERRUPT == TRUE)
   #include <avr/interrupt.h>
#endif

/*=== Local Defines =============================================================================*/

/**
 * @brief Transmit Data Byte
 * 
 *  Macro which use the configured TX-Buffer Macro to transmit a given data byte
 */ 
#define USART_TRANSMIT_DATA_BYTE(tByte)             \
        (USART_HW_TX_BUFFER = tByte)
    
/**
 * @brief Receive Data Byte
 *
 * Macro which use the configured RX-Buffer to receive a data byte
 */ 
#define USART_RECEIVE_DATA_BYTE()                   \
        (USART_HW_RX_BUFFER)
/*=== Local Function Prototypes =================================================================*/

/**
 *  @brief Transmit Callback
 *  @param NONE
 *  @return NONE
 * 
 * Callback which can be used to implement USART user code. This 
 * function will be called in case of Interrupt are enabled and activated.
 * This callback should be implement code to transmit USART data
 */
void USART_TxCallback(void);

/**
 *  @brief Receive Callback
 *  @param NONE
 *  @return NONE
 * 
 * Callback which can be used to implement USART user code. This 
 * function will be called in case of Interrupt are enabled and activated.
 * This callback should be implement code to receive USART data
 */
void USART_RxCallback(void);

/**
 *  @brief Set Interrupts
 *  @param NONE
 *  @return NONE
 *  
 * This functions enables/disables the USART Interrupt depended on the user 
 * configuration defines 
 *   ---------------------------------------------Enable --|--Disable -------------
 *   - USART_ENABLE_RX_INTERRUPT                   TRUE    |   FALSE
 *   - USART_ENABLE_TX_INTERRUPT                   TRUE    |   FALSE
 *   - USART_ENABLE_TX_DATA_EMPTY_INTERRUPT        TRUE    |   FALSE
 */
USART_INLINE void USART_SetInterrupt(void);

/**
 *  @brief Set Global Interrupt Flag
 *  @param NONE
 *  @return NONE
 *  
 * To enable the interrupt globally, the global interrupt flag has to be set.
 * This will be done with this function. 
 * If all interrupts are disabled. This function will return with no effect.
 */
USART_INLINE void USART_SetGlobalInterruptFlag(void);

/*=== Local Parameter =================================================================*/
/**
 * @brief RX-Buffer Array
 */
uint8_t USART_rxBufferAv[USART_RX_BUFFER_SIZE];
/**
 * @brief TX-Buffer Array
 */
uint8_t USART_txBufferAv[USART_TX_BUFFER_SIZE];
/**
 * @brief RX-Fifo
 */
FIFO_Buffer_t USART_rxBuffer = 
        { 
            .bufferPtr  = USART_rxBufferAv,
            .bufferSize = USART_RX_BUFFER_SIZE,
            .status     = FIFO_BUFFER_EMPTY,
            .counter    = { 
                            .read  = 0,
                            .write = 0,
                            .overflow = FALSE,                
                          }
        };

/**
 * @brief Tx-Fifo
 */
FIFO_Buffer_t USART_txBuffer = 
          {
              .bufferPtr  = USART_txBufferAv,
              .bufferSize = USART_TX_BUFFER_SIZE,
              .status     = FIFO_BUFFER_EMPTY,
              .counter    = {
                                .read  = 0,
                                .write = 0,
                                .overflow = FALSE,
                            }
          };


/*=== Function ========================================================================*/
/************************************************************************/
/* USART_TxCallback                                                     */
/************************************************************************/
void USART_TxCallback(void)
{
   char p;
   if(FIFO_IS_BUFFER_EMPTY((&USART_txBuffer)) == FALSE)
   {
        p = FIFO_Read(&USART_txBuffer);
        USART_TRANSMIT_DATA_BYTE(p);
   }   
   return;
}

/************************************************************************/
/* USART_RxCallback                                                     */
/************************************************************************/
void USART_RxCallback(void)
{
    char p;
    
    if(FIFO_IS_BUFFER_FULL((&USART_rxBuffer)) == FALSE)
    {
        p = USART_RECEIVE_DATA_BYTE();    
        FIFO_Write(&USART_rxBuffer,p);
    }    
    return;
}

/************************************************************************/
/* void USART_Init(...)													*/
/************************************************************************/
USART_INLINE void USART_Init(const USART_Config_t* config)
{
    if(config != NULL)
    {
	   
	   USART_SetBaudrate(config->ubrrValueConfig); 
       USART_SetEnableStatus(config->rxEnableConfig,config->txEnableConfig);
       USART_SetParityMode(config->parityConfig);
       USART_SetStopBit(config->stopBitConfig);
       USART_SetDatasize(config->dataSizeConfig);
       USART_SetInterrupt();      
       USART_SetGlobalInterruptFlag();   
    }    
    return;
}

/************************************************************************/
/* void USART_SetBaudrate(...)											*/
/************************************************************************/
USART_INLINE void USART_SetBaudrate(uint16_t baud)
{
	uint8_t low, high;
	
	if(baud <= 0xFF)
	{
		USART_BAUDRATE_LOW_REG = (uint8_t)baud;
	}
	else
	{
		low = baud & 0x00FF;
		high = ((baud & 0xFF00) >> 8);
		USART_BAUDRATE_LOW_REG = low;
		USART_BAUDRATE_HIGH_REG = high;
	}
	return;		
}

/************************************************************************/
/* void USART_SetEnableStatus(...)										*/
/************************************************************************/
USART_INLINE void USART_SetEnableStatus(USART_Enable_t rx, USART_Enable_t tx )
{
     if( rx == USART_ENABLE) 
     {
         SET_REGISTER_BIT(USART_STATUS_B_REG,RXEN);
     }
     else
     {
         RESET_REGISTER_BIT(USART_STATUS_B_REG,RXEN);
     }     
     
     
     if(tx == USART_ENABLE)
     {
        SET_REGISTER_BIT(USART_STATUS_B_REG,TXEN);
     }
     else
     {
        RESET_REGISTER_BIT(USART_STATUS_B_REG,TXEN); 
     }     
    return;
}

/************************************************************************/
/* void USART_SetInterrupt(...)											*/
/************************************************************************/
USART_INLINE void USART_SetInterrupt(void)
{
    /*
     * Validate global interrupt enable flag and set 
     * the correspondent flag --> RXICE = BIT_7
     */
    if(USART_USE_INTERRUPT == TRUE)
    {
        SET_REGISTER_BIT(USART_STATUS_B_REG,RXCIE);
        SET_REGISTER_BIT(USART_STATUS_B_REG,TXCIE);
    }
    else
    {
        RESET_REGISTER_BIT(USART_STATUS_B_REG,RXCIE);
        RESET_REGISTER_BIT(USART_STATUS_B_REG,TXCIE);
    }
    return;
}

/************************************************************************/
/* void USART_SetGlobalInterruptFlag(...)								*/
/************************************************************************/
USART_INLINE void USART_SetGlobalInterruptFlag(void)
{
    /*
     * Enable global Interrupt flag. This will be done by calling 
     * function sei(). 
     * Avoid else branch with disabling of the interrupts flag to avoid 
     * global disabling. Especially in case of other module use Interrupt. 
     * this could cause problems.
     */
    if(USART_USE_INTERRUPT == TRUE)
    {
        sei();
    }
    return;   
}

/************************************************************************
 * void USART_SetParityMode
 ************************************************************************/
USART_INLINE void USART_SetParityMode(USART_ParityMode_t parity)
{
    switch (parity)
    {
        case USART_PARITY_DISABLED:
            USART_RESET_STATUS_C_REGISTER(UPM0);
            USART_RESET_STATUS_C_REGISTER(UPM1);
        break;
        case USART_EVEN_PARITY:
            USART_RESET_STATUS_C_REGISTER(UPM0);
            USART_SET_STATUS_C_REGISTER(UPM1);
        break;
        case USART_ODD_PARITY:
            USART_SET_STATUS_C_REGISTER(UPM0);
            USART_SET_STATUS_C_REGISTER(UPM1);
        break;
        default:
            RESET_REGISTER_BIT(USART_STATUS_C_REG,UPM0);
            RESET_REGISTER_BIT(USART_STATUS_C_REG,UPM1);
        break;
    }
    return;
}

/************************************************************************/
/* void USART_SetStopBit                                                */
/************************************************************************/
USART_INLINE void USART_SetStopBit(USART_StopBit_t stopBit)
{
    if (stopBit == USART_USE_2_STOP_BIT)
    {
        USART_RESET_STATUS_C_REGISTER(USBS);
    }
    else
    {
       USART_SET_STATUS_C_REGISTER(USBS);
    }    
    return;
}


/************************************************************************/
/* void USART_SetDatasize                                               */
/************************************************************************/
USART_INLINE void USART_SetDatasize(USART_DataSize_t size)
{   
    switch (size)
    {
        case  USART_5_BIT_DATA_SIZE:
                /*-- Do Nothing, leave it a t zero*/
        break;
        case  USART_6_BIT_DATA_SIZE:
              USART_SET_STATUS_C_REGISTER(UCSZ0);
        break;
        case  USART_7_BIT_DATA_SIZE:
              USART_SET_STATUS_C_REGISTER(UCSZ1);
        break;
        case  USART_8_BIT_DATA_SIZE:
              USART_SET_TWO_STATUS_C_REGISTER(UCSZ1,UCSZ0);
        break;
        case  USART_9_BIT_DATA_SIZE:
             USART_SET_TWO_STATUS_C_REGISTER(UCSZ1,UCSZ0);
             SET_REGISTER_BIT(USART_STATUS_B_REG,UCSZ2);
        break;
        default:
            USART_SET_TWO_STATUS_C_REGISTER(UCSZ1,UCSZ0);
        break;
    }     
 return;   
} 


/************************************************************************/
/* void USART_TransmitChar                                              */
/************************************************************************/
void USART_TransmitChar(char c)
{
   char p;
   FIFO_Write(&USART_txBuffer,c);
   p = FIFO_Read(&USART_txBuffer);
   USART_TRANSMIT_DATA_BYTE(p);
   return;
}

/************************************************************************/
/* void USART_TransmitString                                            */
/************************************************************************/
void USART_TransmitString(char *str)
{
    char c;
    FIFO_WriteString(&USART_txBuffer,str);
    c = FIFO_Read(&USART_txBuffer);
    USART_TRANSMIT_DATA_BYTE(c);
    return;
}

/************************************************************************/
/* void USART_ReceiveChar                                               */
/************************************************************************/
char USART_ReceiveChar(void)
{
    return FIFO_Read(&USART_rxBuffer);
}

/************************************************************************/
/* void USARt_ReceiveString                                             */
/************************************************************************/
void USARt_ReceiveString(char *str, int size)
{
    FIFO_ReadString(&USART_rxBuffer,str,size);
    return;   
}



#if (USART_USE_INTERRUPT == TRUE)

 /**
  * @brief USART Rx Interrupt
  * 
  * Interrupt service routine to receive data from USART. This 
  * interrupt will be called in case of data data receives over USART and 
  * it is available in the Rx Hardware Buffer
  * This routine calls the Rx Callback only. In this callback the 
  * other interrupt code can be added.
  *
  */
 ISR(USART_RXC_vect)
 {
     USART_RxCallback();
 }
 
 /**
  * @brief USART Tx Interrupt
  * 
  * Interrupt service routine to transmit data from USART. This 
  * interrupt will be called in case of data is ready to be transmitted.
  * If data will be written into the Tx Hardware Buffer, this callback will be 
  * called
  * This routine calls the Tx Callback only. In this callback the
  * other interrupt code can be added
  */
 ISR(USART_TXC_vect)
 {
     USART_TxCallback();
 }
 
 
 
 #endif
 
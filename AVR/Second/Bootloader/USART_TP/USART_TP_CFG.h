/*
 * USART_TP_Cfg.h
 *
 * Created: 09.05.2016 22:20:46
 *  Author: AP
 */ 


#ifndef USART_TP_CFG_H_
#define USART_TP_CFG_H_

#include "TP.h"

/*--- Configuration Defines ---------------------------------------------------------------------*/


/**
 * @brief Start up Sign 
 * 
 * Sign to indicate the start of a TP Message
 */     
#define USART_TP_START_SIGN                                         0xAA55u

/**
 * @brief Delimiter
 *
 * Indicator of the end of a TP Message
 */
#define USART_TP_DELIMITER                                          "\r\n"



/*--- Not Changeable Defines --------------------------------------------------------------------*/
/**
 * @brief Size of Tx Handles
 *
 * Size of all available Tx Handles. This will be determined automatically by the 
 * Tx Handles definition
 */
#define USART_TP_TX_HANDLE_SIZE()              \
        (USART_TP_TX_NUMBER_OF_HANDLS)

/**
 * @brief Size of Rx Handles
 *
 * Size of all available Rx Handles. This will be determined automatically by the
 * Tx Handles definition
 */
#define USART_TP_RX_HANDLE_SIZE()              \
        (USART_TP_RX_NUMBER_OF_HANDLS)

/** 
 * @brief New Message Definition
 */
#define USART_TP_NEW_MESSAGE(uMsgName,uMsgId,uMsgLen)                                           \
        TP_NEW_MESSAGE(uMsgName,uMsgId,uMsgLen,USART_TP_START_SIGN,USART_TP_DELIMITER)

/**
 * @brief Get Message Reference
 *
 */
#define USART_TP_GET_MESSAGE_REFERENCE(uMsgName)                                                \
        TP_GET_MESSAGE_REFERENCE(msgName)
        
           
/*--- Type Definitions --------------------------------------------------------------------------*/
/**
 * @brief Tx Handles Definition
 */
typedef enum
{
    USART_TP_TX_ID_0x0100              = 0x00,
    USART_TP_TX_ID_0x0250                    ,
    
    USART_TP_TX_NUMBER_OF_HANDLS
}USART_TP_TxIdHandle_t;

/**
 * @brief Rx Handles Definition
 */
typedef enum 
{
    USART_TP_RX_ID_0x0200              = 0x00,
    USART_TP_RX_ID_0x0350                    ,
    
    
    USART_TP_RX_NUMBER_OF_HANDLS
}USART_TP_RxIdHandle_t;

/**
 * @brief USART Tp Config
 */
extern TP_Config_t USART_TP_config;


#endif /* USART_TP_CFG_H_ */
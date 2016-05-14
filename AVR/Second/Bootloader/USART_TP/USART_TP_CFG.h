/*
 * USART_TP_CFG.h
 *
 * Created: 09.05.2016 22:20:46
 *  Author: AP
 */ 


#ifndef USART_TP_CFG_H_
#define USART_TP_CFG_H_

#include "USART_TP_Types.h"
#include "TP.h"

/*--- Defines -----------------------------------------------------------------------------------*/

/**
 * @brief Size of Tx Handles
 */
#define USART_TP_TX_HANDLE_SIZE()              \
        (USART_TP_TX_NUMBER_OF_HANDLS)

/**
 * @brief Size of Rx Handles
 */
#define USART_TP_RX_HANDLE_SIZE()              \
        (USART_TP_RX_NUMBER_OF_HANDLS)


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




#endif /* USART_TP_CFG_H_ */
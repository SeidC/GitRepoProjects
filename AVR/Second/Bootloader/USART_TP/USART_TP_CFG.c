/*
 * USART_TP_CFG.c
 *
 * Created: 09.05.2016 22:21:14
 *  Author: AP
 */ 


#include "USART_TP_Cfg.h"


/*--- Definition of Tx - TP Messages ------------------------------------------------------------*/

USART_TP_NEW_MESSAGE(msg_ID100,0x250,20);

USART_TP_NEW_MESSAGE(msg_ID250,0x250,20);



/*--- Definition of Rx - TP Messages ------------------------------------------------------------*/

USART_TP_NEW_MESSAGE(msg_ID200,0x250,20);

USART_TP_NEW_MESSAGE(msg_ID350,0x250,20);

/*--- Tx and Rx Message List --------------------------------------------------------------------*/
static TP_Message_t* USART_TP_Tx_MessageList[USART_TP_TX_HANDLE_SIZE()] =
{
   USART_TP_GET_MESSAGE_REFERENCE(msg_ID100),
   USART_TP_GET_MESSAGE_REFERENCE(msg_ID250),
    
};


static TP_Message_t* USART_TP_Rx_MessageList[USART_TP_RX_HANDLE_SIZE()] = 
{
    USART_TP_GET_MESSAGE_REFERENCE(msg_ID200),
    USART_TP_GET_MESSAGE_REFERENCE(msg_ID350),
}



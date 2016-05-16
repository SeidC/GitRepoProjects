/*
 * USART_TP_CFG.c
 *
 * Created: 09.05.2016 22:21:14
 *  Author: AP
 */ 


#include "USART_TP_Cfg.h"
#include "USART.h"


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
};


static TP_MessageConfig_t USART_TP_txConfig = 
{
    .list = USART_TP_Tx_MessageList,
    .size = USART_TP_TX_HANDLE_SIZE(),
    
};

static TP_MessageConfig_t USART_TP_rxConfig =
{
    .list = USART_TP_Rx_MessageList,
    .size = USART_TP_RX_HANDLE_SIZE(),
};


static TP_Settings_t USART_TP_settings = 
{
    .startSign = USART_TP_START_SIGN,
    .delimiter = USART_TP_DELIMITER, 
    
};


static TP_TimerConfig_t USART_TP_timerConfig = 
{
    .size = USART_TP_TX_HANDLE_SIZE(),
    .list = {
                TP_INIT_TIMER(500,TP_TIMER_RUN),
                TP_INIT_TIMER(750,TP_TIMER_RUN),
            },            
};


TP_Config_t USART_TP_config =   
{
    .rxConfig   = &USART_TP_rxConfig,
    .txConfig   = &USART_TP_txConfig,
    .settings   = &USART_TP_settings,
    .txClbk     = USART_TransmitString,
    .rxClbk     = USART_ReceiveString,
    .txTmConfig = &USART_TP_timerConfig,
};
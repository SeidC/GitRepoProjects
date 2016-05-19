/*
 * USART_TP_CFG.c
 *
 * Created: 09.05.2016 22:21:14
 *  Author: AP
 */ 


#include "USART_TP_Cfg.h"
#include "USART.h"


/*--- Definition of Tx - TP Messages ------------------------------------------------------------*/

USART_TP_NEW_MESSAGE(msg_ID100,0x100,10);

USART_TP_NEW_MESSAGE(msg_ID250,0x250,5);



/*--- Definition of Rx - TP Messages ------------------------------------------------------------*/

USART_TP_NEW_MESSAGE(msg_ID200,0x200,10);

USART_TP_NEW_MESSAGE(msg_ID350,0x350,5);

/*--- Tx and Rx Message List --------------------------------------------------------------------*/

TP_MessageList_t msgList = 
    {
        
        .txMsgLst = 
        {
           USART_TP_GET_MESSAGE_REFERENCE(msg_ID100),
           USART_TP_GET_MESSAGE_REFERENCE(msg_ID250),
        },
        .rxMsgLst = 
        {
           USART_TP_GET_MESSAGE_REFERENCE(msg_ID200),
           USART_TP_GET_MESSAGE_REFERENCE(msg_ID350),
        },
        .txLstSize = USART_TP_TX_HANDLE_SIZE(),
    };  .rxLstSize = USART_TP_RX_HANDLE_SIZE(),


static TP_Settings_t USART_TP_settings = 
{
    .startSign = USART_TP_START_SIGN,
    .stopSign = USART_TP_STOP_SIGN, 
    
};


static TP_TimerConfig_t USART_TP_timerConfig = 
{
    .size = USART_TP_TX_HANDLE_SIZE(),
    .list = {
                TP_INIT_TIMER(10,TP_TIMER_RUN),
                TP_INIT_TIMER(10,TP_TIMER_RUN),
            },            
};


TP_Config_t USART_TP_config =   
{
     .msgList   =
    .settings   = &USART_TP_settings,
    .txTmConfig = &USART_TP_timerConfig,
    .txClbk     = USART_TransmitString,
    .rxClbk     = USART_ReceiveString,
};
/*
 * USART_TP.c
 *
 * Created: 07.05.2016 15:40:52
 *  Author: AP02
 */ 
#include "USART_TP.h"


TP_Config_t *USART_TP_Confg = NULL;


void USART_TP_Init(TP_Config_t *config)
{
    if (config != NULL)
    {
        USART_TP_Confg = config;
    }    
    return;
}



void USART_TP_MainFunction(void)
{
    TP_Task(USART_TP_Confg);
}


void USART_TP_TimerTask(void)
{
    TP_TimerTask(USART_TP_Confg);
}

void USART_TP_SetData(USART_TP_TxIdHandle_t hndl, uint8_t *data)
{
    TP_Message_t *msg;
    msg = &USART_TP_config.txConfig->list[hndl];
    TP_SetMessageData(msg,data);
    return;
}
/*
 * USART_TP.c
 *
 * Created: 07.05.2016 15:40:52
 *  Author: AP02
 */ 

#include "TP.h"
#include "USART.h"

TP_Config_t *USART_TP_Confg = NULL;


void USART_TP_Init(TP_Config_t *config)
{
    if (config != NULL)
    {
        USART_TP_Confg = config;
    }    
    return;
}



void USART_TP_Transmit(void)
{
    USART_Ta
}


void USART_TP_Receive(void)
{
    
}


void USART_TP_MainFunction(void)
{
    
}
/*
 * USART_TP_CFG.c
 *
 * Created: 09.05.2016 22:21:14
 *  Author: AP
 */ 


#include "USART_TP_CFG.h"


static const TP_Message_t msg_ID_0x100 = 
            {
                .header.header_str = {
                    .id = 0x100, 
                }
            }

static const TP_Message_t msg_ID_0x250 =
{
    .header.header_str = {
        .id = 0x250,
    }
}


static const TP_Message_t USART_TP_MessageList[USART_TP_HANDLE_SIZE()] =
{
    &msg_ID_0x100,
    &msg_ID_0x0250,
}
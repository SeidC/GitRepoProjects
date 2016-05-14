/*
 * USART_TP_CFG.c
 *
 * Created: 09.05.2016 22:21:14
 *  Author: AP
 */ 


#include "USART_TP_CFG.h"


 TP_Message_t msg_ID_0x100 = 
            {
//                 .header.header_str = {
//                     .id = 0x100, 
//                 }
            };

 TP_Message_t msg_ID_0x250 =
{
//     .header.header_str = {
//         .id = 0x250,
//     }
};


static TP_Message_t USART_TP_Tx_MessageList[2] =
{
    {
        .header.header_str = {.id = 0x250},
        
    },
    
};


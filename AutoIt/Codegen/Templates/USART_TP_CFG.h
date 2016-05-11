/*
 * USART_TP_CFG.h
 *
 * Created: 09.05.2016 22:20:46
 *  Author: AP
 */ 


#ifndef USART_TP_CFG_H_
#define USART_TP_CFG_H_

#include "TP.h"

#define USART_TP_HANDLE_SIZE()              \
        (USART_TP_NUMBER_OF_HANDLS)


typedef enum
{
    USART_TP_ID_0x0100              = 0x00,
    USART_TP_ID_0x0250                    ,
    
    USART_TP_NUMBER_OF_HANDLS
}USART_TP_IdHandle_t;






#endif /* USART_TP_CFG_H_ */
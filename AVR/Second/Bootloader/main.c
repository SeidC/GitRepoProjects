/*
 * Bootloader.cpp
 *
 * Created: 02.05.2016 23:07:22
 * Author : AP
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include "USART.h"
#include "USART_TP.h"

USART_Config_t usartConfig = 
    {
        .dataSizeConfig     = USART_8_BIT_DATA_SIZE,
        .parityConfig       = USART_PARITY_DISABLED,
        .rxEnableConfig     = USART_ENABLE,
        .txEnableConfig     = USART_ENABLE,
        .stopBitConfig      = USART_USE_1_STOP_BIT,
        .transmitionConfig  = USART_USE_ASYNCHRONOUS_MODE,
        .ubrrValueConfig    = USART_BAUDRATE,
    };
    


uint8_t av[20];

TP_Message_t msg = 
    {
        .header.header_str =
        {
             .startSign = USART_TP_START_SIGN,
             .id        = 0x100,
             .dataLen   = 0,
        },
        
        .body = 
        {
            .dataAv = av,
            .size = 20,
        },
        
        .footer.footer_str = 
        {
            .crc = 5,
            .sqc = 10,
            .delim = USART_TP_DELIMITER,
        },        
 };

int main(void)
{
    /* Replace with your application code */
    USART_Init(&usartConfig);
    USART_TP_Init(&USART_TP_config);
    
    USART_TP_SetData(USART_TP_TX_ID_0x0100,"Hallo Welt");
    USART_TP_SetData(USART_TP_TX_ID_0x0250,"Blubb");
    
    msg.body.size = 15;
    
    while (1) 
    {
        USART_TP_TimerTask();
        USART_TP_MainFunction();
        _delay_ms(100);
        
    }
}


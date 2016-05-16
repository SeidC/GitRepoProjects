/*
 * Bootloader.cpp
 *
 * Created: 02.05.2016 23:07:22
 * Author : AP
 */ 

#include <avr/io.h>
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
    
    

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}


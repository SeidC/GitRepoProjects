/*
 * TP.c
 *
 * Created: 06.05.2016 22:16:43
 *  Author: AP02
 */ 
#include "TP.h"


void TP_Transmit(TP_Config_t *config, uint8_t index);


void TP_Receive(TP_Config_t *config, uint8_t *data, uint8_t size);



/**************************************************************************************************
 * FUNCTION: void TP_SetTpData(...)
 *************************************************************************************************/
void TP_SetTpData(TP_Message_t *msg, uint8_t *data, uint8_t size))
{
    uint8_t i;
    
    if (size < msg->body.size)
    {    
        for(i = 0; i < size; i++)
        {
            msg->body.dataAv[i] == data[i];        
        }
    }    
    return;
}

/**************************************************************************************************
 * FUNCTION: uint8_t TP_GetMessageSize(...)
 *************************************************************************************************/
uint8_t TP_GetMessageSize(TP_Message_t *msg, TP_SizeValue_t sizeType)
{
    uint8_t header,body,footer,ret;

    switch(sizeType)
    {
     case TP_MESSAGE_DATA_LENGTH     :
         ret = TP_GET_MESSAGE_LENGTH(msg);
         break; 
     case TP_MESSAGE_TP_LENGTH :
         header  = TP_HEADER_SIZE();
         body    = TP_GET_BODY_LENGTH(msg);
         footer  = TP_FOOTER_SIZE();
         ret = (header + body + footer);
         break;
     case TP_FOOTER_LENGTH       :
        ret = TP_FOOTER_SIZE();
        break;
     case TP_HEADER_LENGTH       :
        ret = TP_HEADER_SIZE();
        break;
     case TP_BODY_LENGTH         :
        ret = TP_GET_BODY_LENGTH(msg);
        break;
     default:
        ret = 0;
        break;
    }    
    
    return ret;
}


/**************************************************************************************************
 * FUNCTION: void TP_TimerReload(...)
 *************************************************************************************************/
void TP_TimerReload(TP_Timer_t *timer)
{
    if (timer->timerStatus != TP_TIMER_OFF)
    {
        timer->msCurrTime = timer->msThreshold;
        timer->timerStatus = TP_TIMER_RUN;
    }    
    return;
}

void TP_Task(TP_Config_t *config)
{
    TP_TimerTask(config);
    TP_Transmit(config);
    TP_Receive(config);
}

void TP_TimerTask(TP_Config_t *config)
{
    uint8_t i;
    TP_Timer_t *timer;
    for(i = 0; i < config->txTimerCfg->size; i++)
    {
        timer = &(config->txTimerCfg->list[i]);
        if (timer->timerStatus != TP_TIMER_OFF)
        {
            if (timer->msCurrTime > 0x00)
            {
                timer->msCurrTime --;
            }            
        }
        else
        {
            timer->timerStatus = TP_TIMER_EXPIRED;
        }
    }
    return;
}


void TP_Transmit(TP_Config_t *config, uint8_t index)
{
    uint8_t i;
    TP_Timer_t *timer;
    
    for(i = 0; i < config->txTimerCfg->size; i++)
    {
        timer = &(config->txTimerCfg->list[i]);
        if(config->txTimerCfg->list[i].timerStatus == TP_TIMER_EXPIRED)
        {
            
            
            
            TP_TimerReload(timer);
        }
    }
    return;
}


void TP_Receive(TP_Config_t *config, uint8_t *data, uint8_t size);
{
    
    
}
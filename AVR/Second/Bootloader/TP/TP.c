/*
 * TP.c
 *
 * Created: 06.05.2016 22:16:43
 *  Author: AP02
 */ 
#include "TP.h"

/**
 *  @brief Brief
 *  
 *  @param [in] msg Parameter_Description
 *  @param [in] av Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
uint8_t TP_GetHeader(TP_Message_t *msg, uint8_t* av);
/**
 *  @brief Brief
 *  
 *  @param [in] msg Parameter_Description
 *  @param [in] av Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
uint8_t TP_GetFooter(TP_Message_t *msg, uint8_t* av);
/**
 *  @brief Brief
 *  
 *  @param [in] msg Parameter_Description
 *  @param [in] av Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
uint8_t TP_GetBody(TP_Message_t *msg, uint8_t* av);
/**
 *  @brief Brief
 *  
 *  @param [in] msg Parameter_Description
 *  @param [in] len Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void TP_SetMessagLength(TP_Message_t *msg, uint8_t len);

/**************************************************************************************************
 * FUNCTION: uint8_t TP_GetHeader(...)
 *************************************************************************************************/
uint8_t TP_GetHeader(TP_Message_t *msg, uint8_t* av)
{
    av = msg->header.header_b;
    return TP_HEADER_SIZE();
}
/**************************************************************************************************
 * FUNCTION: uint8_t TP_GetFooter(...)
 *************************************************************************************************/
uint8_t TP_GetFooter(TP_Message_t *msg, uint8_t* av)
{
    av = msg->footer.footer_b;
    return TP_FOOTER_SIZE();
}
/**************************************************************************************************
 * FUNCTION: uint8_t TP_GetBody(...)
 *************************************************************************************************/
uint8_t TP_GetBody(TP_Message_t *msg, uint8_t* av)
{
    av = msg->body.dataAv;
    return TP_BODY_SIZE(msg);
}
/**************************************************************************************************
 * FUNCTION: void TP_SetId(...)
 *************************************************************************************************/
void TP_SetId(TP_Message_t *msg, uint8_t id)
{
    msg->header.header_str.id = id;
    
    return;
}
/**************************************************************************************************
 * FUNCTION: void TP_SetMessagLenth(...)
 *************************************************************************************************/
void TP_SetMessagLength(TP_Message_t *msg, uint8_t len)
{
    msg->header.header_str.dataLen = len;
    return;
}
/**************************************************************************************************
 * FUNCTION: uint8_t TP_SetMessage(...)
 *************************************************************************************************/
uint8_t TP_SetMessage(TP_Message_t *msg, uint8_t *data)
{
    uint8_t count = 0;
    while(*data)
    {
        if (count < TP_MAX_MESSAGE_SIZE)
        {
            msg->body.dataAv[count] = *data;
        }
        else
        {
            break;
        }
        data++;
        count++;
    }
    return count;
}

/**************************************************************************************************
 * FUNCTION: uint8_t TP_SetMessage(...)
 *************************************************************************************************/
void TP_SetMessageData(TP_Message_t *msg, uint8_t *data)
{
    uint8_t length,id;
    id = TP_GET_MESSAGE_ID(msg);
    TP_SetId(msg,id);
    length = TP_SetMessage(msg,data);
    TP_SetMessagLength(msg,length);
    return;
}
/**************************************************************************************************
 * FUNCTION: uint8_t TP_GetMessageSize(...)
 *************************************************************************************************/
uint8_t TP_GetMessageSize(TP_Message_t *msg, TP_SizeValue_t sizeType)
{
    uint8_t header,body,maxBody,footer,ret;

    switch(sizeType)
    {
     case TP_MAX_BODY_LENGTH     :
         ret = TP_GET_MAX_BODY_LENGTH(msg);
         break;         
     case TP_MAX_MESSAGE_LENGTH  :
         header  = TP_HEADER_SIZE();
         footer  = TP_FOOTER_SIZE();
         maxBody = TP_GET_MAX_BODY_LENGTH(msg);
         ret = (header + maxBody + footer);
         break; 
     case TP_CURR_MESSAGE_LENGTH :
         header  = TP_HEADER_SIZE();
         body    = TP_GET_CURRENT_BODY_LENGTH(msg);
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
        ret = TP_GET_CURRENT_BODY_LENGTH(msg);
        break;
     default:
        ret = 0;
        break;
    }    
    
    return ret;
}

/**************************************************************************************************
 * FUNCTION: void TP_Timer(...)
 *************************************************************************************************/
void TP_Timer(TP_Timer_t *timer)
{
    if (timer->timerStatus != TP_TIMER_OFF)
    {        
        if (timer->msCurrTime > 0x00)
        {
            timer->msCurrTime --;
        }
        else
        {
            timer->timerStatus = TP_TIMER_EXPIRED;
        }
    }   
    return;    
}

/**************************************************************************************************
 * FUNCTION: void TP_TImerReload(...)
 *************************************************************************************************/
void TP_TImerReload(TP_Timer_t *timer)
{
    if (timer->timerStatus != TP_TIMER_OFF)
    {
        timer->msCurrTime = timer->msThreshold;
        timer->timerStatus = TP_TIMER_RUN;
    }    
    return;
}
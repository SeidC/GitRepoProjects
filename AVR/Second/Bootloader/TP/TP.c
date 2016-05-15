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


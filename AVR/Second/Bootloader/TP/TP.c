/*
 * TP.c
 *
 * Created: 06.05.2016 22:16:43
 *  Author: AP02
 */ 


#include "TP.h"






uint8_t TP_GetHeader(TP_Message_t *msg, uint8_t* av);

uint8_t TP_GetFooter(TP_Message_t *msg, uint8_t* av);

uint8_t TP_GetBody(TP_Message_t *msg, uint8_t* av);

void TP_SetMessagLength(TP_Message_t *msg, uint8_t len);

void TP_SetDelimiter(TP_Message_t *msg);

void TP_SetMessageIndicator(TP_Message_t *msg);

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
   // av = msg->body;
    return TP_BODY_SIZE();
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
            //msg->body[count] = *data;
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
void TP_SetMessageData(TP_Message_t *msg, uint8_t id, uint8_t *data)
{
    uint8_t length;
    TP_SetMessageIndicator(msg);
    TP_SetId(msg,id);
    length = TP_SetMessage(msg,data);
    TP_SetMessagLength(msg,length);
    TP_SetDelimiter(msg);
    return;
}

/**************************************************************************************************
 * FUNCTION: void TP_SetDelimiter(...)
 *************************************************************************************************/
void TP_SetDelimiter(TP_Message_t *msg)
{
    uint8_t i;
    uint8_t delim[TP_DELIMITER_CFG_SIZE()] = TP_DELIMITER_CFG; 
    
    for (i = 0; i < TP_DELIMITER_CFG_SIZE(); i++)
    {
        msg->footer.footer_str.delim[i] = delim[i];
    }
    return;
}

/**************************************************************************************************
 * FUNCTION: void TP_SetMessageIndicator(...)
 *************************************************************************************************/
void TP_SetMessageIndicator(TP_Message_t *msg)
{
    uint8_t i;
    //uint8_t indi = TP_MESSAGE_INDICATOR;
    
    for(i = 0; i < TP_MESSAGE_INDICATOR_SIZE(); i++)
    {
        //msg->header.header_str.msgSign[i] = indi[i];
    }
    return;

}

/*
 * TP.c
 *
 * Created: 06.05.2016 22:16:43
 *  Author: AP02
 */ 


#include "TP.h"



uint8_t TP_GetHeader(TP_Message_t *msg, uint8_t* av)
{
    av = msg->header.header_b;
    return TP_HEADER_SIZE();
}

uint8_t TP_GetFooter(TP_Message_t *msg, uint8_t* av)
{
    av = msg->footer.footer_b;
    return TP_FOOTER_SIZE();
}

uint8_t TP_GetBody(TP_Message_t *msg, uint8_t* av)
{
    av = msg->body;
    return TP_BODY_SIZE();
}


void TP_SetId(TP_Message_t *msg, uint8_t id)
{
    msg->header.header_str.id = id;
    return;
}

void TP_SetMessagLenth(TP_Message_t *msg, uint8_t len)
{
    msg->header.header_str.dataLen = len;
    return;
}

uint8_t TP_SetMessage(TP_Message_t *msg, uint8_t *data)
{
    uint8_t count = 0;
    while(*data)
    {
        if (count < TP_MAX_MESSAGE_SIZE)
        {
            msg->body[count] = *data;
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


void TP_CreateMessage(TP_Message_t *msg, uint8_t id, uint8_t *data)
{
    uint8_t length;
    TP_SetId(msg,id);
    length = TP_SetMessage(msg,data);
    TP_SetMessagLenth(msg,length);
    return;
}
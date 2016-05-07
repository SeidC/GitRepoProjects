/*
 * TP.c
 *
 * Created: 06.05.2016 22:16:43
 *  Author: AP02
 */ 


#include "TP.h"



static TP_Service_t TP_CreateService(TP_ServiceType_t serv, TP_SubserviceType_t subServ);

/**
 * @brief Positive Response Definition
 */
static const TP_MessageBody_t TP_PositveResponse = 
{
    .sizeOfData = 1,
    .data = {TP_ACK_CFG},   
};

/**
 * @brief Negative Response Definition
 */
static const TP_MessageBody_t TP_NegativeResponse =
{
    .sizeOfData = 1,
    .data = {TP_NACK_CFG},    
};


/*************************************************************************************************
 * TP_Service_t TP_CreateService(...)                                                                     
 *************************************************************************************************/
static TP_Service_t TP_CreateService(TP_ServiceType_t serv, TP_SubserviceType_t subServ)
{
    TP_Service_t ret;
    
    ret |= (serv & 0xF0) | (subServ & 0x0F); 
    return ret;
}

/*************************************************************************************************
 * void TP_GenerateResponse(...)                                                                     
 *************************************************************************************************/
void TP_GenerateResponse(TP_Response_t response, TP_SubserviceType_t service, TP_Message_t *msg)
{
    msg->header.service = TP_CreateService(TP_RESPONSE,service);  
    if(response == TP_NEGATIVE_RESPONSE)
    {
        msg->body = &TP_NegativeResponse;
    }   
    else if(response == TP_POSITIVE_RESPONSE) 
    {
        msg->body = &TP_PositveResponse;
    } 
    else
    {
        
    }
    return;
}
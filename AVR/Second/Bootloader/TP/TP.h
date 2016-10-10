/*
 * TP.h
 *
 * Created: 06.05.2016 22:16:53
 *  Author: AP02
 */ 


#ifndef TP_H_
#define TP_H_

#include "TP_Cfg.h"

typedef uint8_t TP_Service_t;

/**
 * @brief Header of the TP
 */
typedef struct  
{
     uint16_t startToken;
     TP_Service_t service;
}TP_MessageHeader_t;

/**
 * @brief Body of the TP
 */
typedef struct
{
    uint16_t sizeOfData;
    uint8_t data[TP_MAX_MESSAGE_LENGHT_CFG];
}TP_MessageBody_t;

/**
 * @brief Footer of the TP
 */
typedef struct 
{
    
}TP_MessageFooter_t;

/**
 * @brief TP Message
 */
typedef struct
{
    TP_MessageHeader_t header;
    TP_MessageBody_t    *body;     
    TP_MessageFooter_t footer;       
}TP_Message_t;


typedef enum
{
    TP_NEGATIVE_RESPONSE        = 0x00,
    TP_POSITIVE_RESPONSE        = 0x01,
}TP_Response_t;


#endif /* TP_H_ */
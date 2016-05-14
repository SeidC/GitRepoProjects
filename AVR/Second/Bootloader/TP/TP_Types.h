/*
 * TP_Types.h
 *
 * Created: 12.05.2016 17:04:22
 *  Author: AP02
 */ 


#ifndef TP_TYPES_H_
#define TP_TYPES_H_

#include "PR_DEF.h"

/*--- Size Configuration Defines ----------------------------------------------------------------*/

/**
 * @brief Header Size
 */
#define TP_HEADER_SIZE()                    \
            (sizeof(TP_Header_str))
 
/**
 * @brief Footer Size
 */          
#define TP_FOOTER_SIZE()                    \
            (sizeof(TP_Footer_str))

/** 
 * @brief Max Body Size
 */            
#define TP_BODY_SIZE()                      \
        (TP_MAX_MESSAGE_SIZE)
        
/**
 * @brief Delimiter Size
 */        
#define TP_DELIMITER_CFG_SIZE()             \
        (sizeof(TP_DELIMITER_CFG))

/**
 * @brief 
 */
#define TP_MESSAGE_INDICATOR_SIZE()         \
        (sizeof(TP_MESSAGE_INDICATOR))


/*--- Defines to Initialize Messages ------------------------------------------------------------*/

/**
 * @brief
 */
#define TP_NEW_MESSAGE(msgName,msgId,msgLength,msgStart_i,msgDelim_Str)                \
        static uint8_t msgName##_av[msgLength];                                        \
        static TP_Message_t msg_##msgName =                                            \
        {                                                                              \
            .header.header_str =                                                       \
            {                                                                          \
                .dataLen  = 0u,                                                        \
                .id       = msgId,                                                     \
                .msgStart = msgStart_i,                                                  \
            },                                                                         \
            .body =                                                                    \
            {                                                                          \
                .dataAv   = msgName##_av,                                              \
                .size     = msgLength,                                                 \
            },                                                                         \
            .footer.footer_str =                                                       \
            {                                                                          \
                .delim    = msgDelim_Str,                                              \
                .sqc      = 0,                                                         \
                .crc      = 0,                                                         \
            },                                                                         \
        }                                                       
        

#define TP_GET_MESSAGE_REFERENCE(msgName)                                               \
        ((TP_Message_t*) &msg_##msgName)

/*--- TP Message Types Definition ---------------------------------------------------------------*/

/**
 * @brief Header Structure Definition
 */            
typedef struct
{
    uint16_t msgStart;
    uint16_t id;
    uint8_t  dataLen;
}TP_Header_str;

/**
 * @brief Header Union Definition
 */
typedef union
{
    TP_Header_str header_str;
    uint8_t header_b[TP_HEADER_SIZE()];
    
}TP_Header_t;

/**
 * @brief Body Definition
 */
typedef struct 
{
    uint8_t *dataAv;
    uint8_t size;
}TP_Body_t;

/**
 * @brief Footer Structure Definition
 */
typedef struct
{
    uint8_t sqc;
    uint8_t crc;
    uint8_t delim[];
            
}TP_Footer_str;

/**
 * @brief Footer Union Definiton
 */
typedef union
{
    TP_Footer_str footer_str;
    uint8_t footer_b[TP_FOOTER_SIZE()];
    
}TP_Footer_t;

/**
 * @brief TP Message Definition
 */
typedef struct 
{
    TP_Header_t header;
    TP_Body_t   body;
    TP_Footer_t footer;
    
}TP_Message_t;



#endif /* TP_TYPES_H_ */
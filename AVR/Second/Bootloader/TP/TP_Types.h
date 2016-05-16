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
#define TP_BODY_SIZE(msgPtr)                      \
        (msgPtr->body->size)
        
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

/*--- Getter Macros definition ------------------------------------------------------------------*/

#define TP_GET_MESSAGE_ID(msgPtr)           \
        (msgPtr->header.header_str.id)

#define TP_GET_BODY_LENGTH(msgPtr)          \
        (msgPtr->header.header_str.dataLen)
        
#define TP_GET_CURRENT_BODY_LENGTH(msgPtr)  \
        (msgPtr->header.header_str.dataLen)

#define TP_GET_MAX_BODY_LENGTH(msgPtr)  \
        (msgPtr->body.size)

/*--- Defines to Initialize Messages ------------------------------------------------------------*/

/**
 *  @brief New Message
 *  
 *  @param [in] msgName Name of the new message
 *  @param [in] msgId Id which should be used for this message
 *  @param [in] msgLength Length of this message
 *  @param [in] msgStart_i Start sign of the message
 *  @param [in] msgDelim_Str Delimiter of this message
 *  @return None
 *  
 *  @details This macro should be used for each definition of messages. This macro defines 
 *           automatically a buffer array and the corresponding message. 
 *           This parameter will be set as static (local).
 *           To get the message as reference, use @see TP_GET_MESSAGE_REFERENCE to the a pointer 
 *           reference.
 */
#define TP_NEW_MESSAGE(msgName,msgId,msgLength,msgStSign,msgDelim)                     \
        static uint8_t msgName##_av[msgLength];                                        \
        static TP_Message_t msg_##msgName =                                            \
        {                                                                              \
            .header.header_str =                                                       \
            {                                                                          \
                .dataLen   = 0u,                                                       \
                .id        = msgId,                                                    \
                .startSign = msgStSign,                                                \
            },                                                                         \
            .body =                                                                    \
            {                                                                          \
                .dataAv   = msgName##_av,                                              \
                .size     = msgLength,                                                 \
            },                                                                         \
            .footer.footer_str =                                                       \
            {                                                                          \
                .delim    = msgDelim,                                                  \
                .sqc      = 0,                                                         \
                .crc      = 0,                                                         \
            },                                                                         \
        }                                                       
        
/**
 *  @brief Get Message Reference 
 *  
 *  @param [in] msgName Name of the message which was defined and the reference needed.
 *  @return Message Pointer of type TP_Message_t*
 *  
 *  @details This macro should be used to get a pointer reference of a message which was defined 
 *           with the macro @see TP_NEW_MESSAGE
 */
#define TP_GET_MESSAGE_REFERENCE(msgName)                                               \
        ((TP_Message_t*) &msg_##msgName)

/*--- TP Message Types Definition ---------------------------------------------------------------*/

/**
 * @brief Header Structure Definition
 */            
typedef struct
{
    uint16_t startSign;  /**< Message Start Sign to identify a TP Message                                */
    uint16_t id;        /**< Id of the current Message. This allows a to define specific messages       */
    uint8_t  dataLen;   /**< Length of the Message                                                      */
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
 * @brief Footer Union Definition
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

/**
 * @brief TP Configuration
 */
typedef struct 
{
    
    TP_Message_t *rxList;
    uint8_t rxListSize;
    TP_Message_t *txList;
    uint8_t txListSize;
    uint8_t startSign;
    uint8_t delim[];   
}TP_Config_t;


typedef enum 
{
    TP_TIMER_OFF        = 0x00,
    TP_TIMER_RUN        = 0x01,
    TP_TIMER_READY      = 0x02,
}TP_TimerStatus_t;

typedef struct 
{
    int8_t msThreshold;
    int8_t msCurrTime;
    TP_TimerStatus_t timerStatus;    

}TP_Timer_t;

typedef enum 
{
    TP_MAX_BODY_LENGTH,
    TP_MAX_MESSAGE_LENGTH,
    TP_CURR_MESSAGE_LENGTH,
    TP_FOOTER_LENGTH,
    TP_HEADER_LENGTH,
    TP_BODY_LENGTH,
    
}TP_SizeValue_t;

#endif /* TP_TYPES_H_ */
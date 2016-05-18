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
        (msgPtr->body.size)
        
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

/**
 * @brief 
 */
#define TP_GET_MESSAGE_ID(msgPtr)           \
        (msgPtr->header.header_str.id)
/**
 * @brief 
 */
#define TP_GET_BODY_LENGTH(msgPtr)          \
        (msgPtr->body.size)

/**
 * @brief 
 */
#define TP_GET_MESSAGE_LENGTH(msgPtr)  \
        (msgPtr->header.header_str.dataLen)
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


#define TP_INIT_TIMER(msTime, initStatus)                                               \
        {                                                                               \
           .msThreshold = msTime,                                                       \
           .msCurrTime  = msTime,                                                       \
           .timerStatus  = initStatus,                                                  \
        }                                                                               \
/*--- TP Message Types Definition ---------------------------------------------------------------*/

/**
 * @brief Header Structure Definition
 */            
typedef struct
{
    uint16_t startSign;  /**< Message Start Sign to identify a TP Message                                */
    uint16_t id;         /**< Id of the current Message. This allows a to define specific messages       */
    uint8_t  dataLen;    /**< Length of the Message                                                      */
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

/*--- Timer Types Definition --------------------------------------------------------------------*/

/**
 * @brief Timer Status
 *
 * This type will be used, to show the status of a timer. 
 */
typedef enum
{
    TP_TIMER_OFF        = 0x00, /**< Timer is disabled and not running.        */
    TP_TIMER_RUN        = 0x01, /**< Timer is active and will be counted down .*/
    TP_TIMER_EXPIRED    = 0x02, /**< Timer is active but expired. Timer has to be reloaded*/
}TP_TimerStatus_t;

/**
 * @brief Timer Type Definition
 *
 * This structure defines a Timer. 
 */
typedef struct
{
    int16_t msThreshold;             /**< Threshold in ms. If timer will be reloaded this time will be set */
    int16_t msCurrTime;              /**< Count down time. Also current expired time of this timer         */
    TP_TimerStatus_t timerStatus;   /**< Status of the timer. @see TP_TimerStatus_t                       */
}TP_Timer_t;

/*--- Other Types -------------------------------------------------------------------------------*/


typedef enum
{
    TP_MESSAGE_DATA_LENGTH,
    TP_MESSAGE_TP_LENGTH,
    TP_FOOTER_LENGTH,
    TP_HEADER_LENGTH,
    TP_BODY_LENGTH,
    
}TP_SizeValue_t;


/*--- TP Configuration Defines ------------------------------------------------------------------*/

/**
 * @brief Message TP Configuration
 *
 * This type contains a list of messages and the amount of messages.
 * It is needed as RX and TX list for the TP.
 */
typedef struct  
{
    uint8_t       size;         /**< The size of the list                             */
    TP_Message_t* list[];         /**< Pointer to a list of TP Messages                 */
}TP_MessageConfig_t;
/**
 * @brief TP Settings Configuration
 *
 * Standard configuration for the TP.
 */
typedef struct 
{
    uint16_t startSign;      /**< Start Sign which will identify a TP message */
    uint8_t delimiter[];    /**< Delimiter which identify the end of a TP message*/
}TP_Settings_t;

/**
 * @brief TP Timer Configuration 
 *
 * Configuration  of timer especially needed for the TP Tx Messages.
 */
typedef struct 
{
    uint8_t     size;       
    TP_Timer_t  list[];    
}TP_TimerConfig_t;

/**
 * @brief TP Configuration
 */
typedef struct 
{
    
    TP_MessageConfig_t *rxConfig;           /**< Rx Message configuration               */
    TP_MessageConfig_t *txConfig;           /**< Tx Message configuration               */
    TP_Settings_t      *settings;           /**< Std Settings configuration             */
    TP_TimerConfig_t   *txTmConfig;         /**< Tx Message timer configuration         */
    void (*txClbk)(char *data);             /**< Tx Callback to transmit TP data        */
    void (*rxClbk)(char *str, int size);    /**< Rx Callback to receive TP data         */
    uint8_t             curTxIndex;
}TP_Config_t;

#endif /* TP_TYPES_H_ */
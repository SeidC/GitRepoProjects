/*
 * TP.h
 *
 * Created: 06.05.2016 22:16:53
 *  Author: AP02
 */ 


#ifndef TP_H_
#define TP_H_

#include "PR_DEF.h"


/*--- Configuration Defines ---------------------------------------------------------------------*/

/**
 * @brief Maximum Message Size
 */
#define TP_MAX_MESSAGE_SIZE         50

/**
 * @brief Delimiter Configuration
 */
#define TP_DELIMITER_CFG           "\r\n"

/**
 * @brief Broadcast Id
 */
#define TP_BROADCAST_ID             0xFF

/*--- Size Calculation Defines ------------------------------------------------------------------*/
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
 * @brief Header Structure Definition
 */            
typedef struct
{
    uint8_t id;
    uint8_t dataLen;
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
typedef uint8_t TP_Body_t;
/**
 * @brief Footer Structure Definition
 */
typedef struct
{
    uint8_t sqc;
    uint8_t crc;
    uint8_t delim[TP_DELIMITER_CFG_SIZE()];
            
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
    TP_Body_t body[TP_MAX_MESSAGE_SIZE];
    TP_Footer_t footer;
    
}TP_Message_t;



uint8_t TP_SetMessage(TP_Message_t *msg, uint8_t *data);
void TP_SetId(TP_Message_t *msg, uint8_t id);
void TP_CreateMessage(TP_Message_t *msg, uint8_t id, uint8_t *data);

#endif /* TP_H_ */
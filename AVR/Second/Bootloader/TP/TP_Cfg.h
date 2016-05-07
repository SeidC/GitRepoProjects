/*
 * TP_Cfg.h
 *
 * Created: 06.05.2016 22:17:55
 *  Author: AP02
 */ 


#ifndef TP_CFG_H_
#define TP_CFG_H_

#include "PR_DEF.h"

#define TP_DELIMITER_CFG                                "|"

#define TP_START_TOKEN_CFG                          0xAAAA


#define TP_MAX_MESSAGE_LENGHT_CFG                       20u

#define TP_ACK_CFG                                     0xFF

#define TP_NACK_CFG                                     0x00


typedef enum
{
    TP_REQUEST          = 0x10,
    TP_RESPONSE         = 0x20,
        
}TP_ServiceType_t;

/**
 * @brief TP Subservices Definiton
 */
typedef enum
{
    TP_ENTER_BOOTLOADER         = 0x01,
    TP_DATA                     = 0x02,
    TP_END_OF_DATA              = 0x03,
    TP_KEEP_ALIVE               = 0x04,
}TP_SubserviceType_t;








#endif /* TP_CFG_H_ */
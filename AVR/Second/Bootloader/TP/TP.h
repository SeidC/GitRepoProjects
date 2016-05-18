/*
 * TP.h
 *
 * Created: 06.05.2016 22:16:53
 *  Author: AP02
 */ 


#ifndef TP_H_
#define TP_H_

#include "PR_DEF.h"
#include "TP_Cfg.h"
#include "TP_Types.h"

/*--- Configuration Defines ---------------------------------------------------------------------*/

/**
 * @brief Broadcast Id
 */
#define TP_BROADCAST_ID                                                 0xFF

/*--- Size Calculation Defines ------------------------------------------------------------------*/


/**
 *  @brief Brief
 *  
 *  @param [in] msg Parameter_Description
 *  @param [in] data Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
uint8_t TP_SetMessageData(TP_Message_t *msg, uint8_t *data);
/**
 *  @brief Brief
 *  
 *  @param [in] msg Parameter_Description
 *  @param [in] id Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void TP_SetId(TP_Message_t *msg, uint8_t id);



void TP_TimerTask(TP_Config_t *config);


void TP_Task(TP_Config_t *config);

#endif /* TP_H_ */
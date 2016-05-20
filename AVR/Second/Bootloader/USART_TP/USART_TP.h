/*
 * USART_TP.h
 *
 * Created: 07.05.2016 15:41:12
 *  Author: AP02
 */ 


#ifndef USART_TP_H_
#define USART_TP_H_

#include "PR_DEF.h"
#include "TP.h"
#include "USART.h"
#include "USART_TP_Cfg.h"


void USART_TP_Init(TP_Config_t *config);

void USART_TP_MainFunction(void);

void USART_TP_TimerTask(void);

void USART_TP_SetData(USART_TP_TxIdHandle_t hndl, uint8_t *data, uint8_t size);




#endif /* USART_TP_H_ */
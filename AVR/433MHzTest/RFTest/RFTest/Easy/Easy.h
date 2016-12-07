/*
 * Easy.h
 *
 * Created: 08.10.2016 00:58:54
 *  Author: AP
 */ 


#ifndef EASY_H_
#define EASY_H_
#include "PR_DEF.h"
#include "Easy_Types.h"
#include "Easy_Cfg.h"


#define EASY_SET_TX()								\
		  (EASY_TX_PORT |= (1 << EASY_TX_PIN))
		
#define EASY_CLEAR_TX()								 \
		  (EASY_TX_PORT &= ~(1 << EASY_TX_PIN))
	
void Easy_Init(Easy_Config_t *cfgPtr);

void Easy_TransmitChar(char p);

void Easy_TransmitSyncField(void);

void Easy_TransmitString(char* string, uint8_t stringLength, uint16_t* buffer);

EASY_INLINE void Easy_RxInterruptRoutine(void);

EASY_INLINE void Easy_NextState(EASY_RXFSM_EVENT_T state);

#endif /* EASY_H_ */
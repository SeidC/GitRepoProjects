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

#define EASY_IS_RX_EDGE_IN_TIME(t)                    \
        ((t >= EASY_RX_MIN_EDGE_TIME) && (t <= EASY_RX_MAX_EDGE_TIME))

#define EASY_MAX_RX_TIME()							  \
		(EASY_RX_MAX_EDGE_TIME * 2)
		
		
void Easy_Init(Easy_Config_t *cftPtr);

void Easy_TransmitChar(char p);

void Easy_TransmitSyncField(void);

void Easy_TransmitString(char* string, uint8_t stringLength, uint16_t* buffer);

EASY_INLINE void Easy_RxInterruptRoutine(void);

EASY_INLINE void Easy_SetFsmSignal(EASY_RXFSM_EVENT_T signal);

EASY_INLINE void Easy_RxNoIndication(void);

EASY_INLINE void Easy_RxFinished(void);

EASY_INLINE void Easy_RxPreStart(void);

EASY_INLINE void Easy_RxReceiveError(void);

EASY_INLINE void Easy_RxReceive(void);

#endif /* EASY_H_ */
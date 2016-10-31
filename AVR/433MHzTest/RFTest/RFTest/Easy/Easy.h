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
		
		
void Easy_Init(void);

void Easy_TransmitChar(char p);

void Easy_TransmitSyncField(void);

void Easy_TransmitString(char* string, uint8_t stringLength, uint16_t* buffer);

#endif /* EASY_H_ */
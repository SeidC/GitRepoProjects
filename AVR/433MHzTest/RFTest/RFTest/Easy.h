/*
 * Easy.h
 *
 * Created: 08.10.2016 00:58:54
 *  Author: AP
 */ 


#ifndef EASY_H_
#define EASY_H_
#include <avr/io.h>
#include "Easy_Cfg.h"


#define EASY_SET_TX()							 \
		(EASY_TX_PORT |= (1 << EASY_TX_PIN))
		
#define EASY_CLEAR_TX()							\
		(EASY_TX_PORT &= ~(1 << EASY_TX_PIN))

typedef enum 
{
	EASY_NO_INDICATION = 0x00,
	EASY_EXTERN_RX			 ,
	EASY_INTERN_RX			 ,
}Easy_RxIndication_t;

void Easy_Init(void);

void Easy_TransmitChar(char p);

void Easy_TransmitSyncField(void);

void Easy_TransmitString(char* string, uint8_t stringLength, uint16_t* buffer);

#endif /* EASY_H_ */
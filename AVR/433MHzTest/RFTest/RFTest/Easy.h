/*
 * Easy.h
 *
 * Created: 08.10.2016 00:58:54
 *  Author: AP
 */ 


#ifndef EASY_H_
#define EASY_H_
#include <avr/io.h>


/*--- Tx Port Configuration ----------------------------------------------------------------*/
#define EASY_TX_PORT						PORTD
#define EASY_TX_DDR							DDRD
#define EASY_TX_PIN							PIND1

#define EASY_RX_PORT						PORTD
#define EASY_RX_DDR							DDRD
#define EASY_RX_PIN							PIND2
/*--- Interrupt Rx Configuration ----------------------------------------------------------*/
#define EASY_RX_INTERRUPT_REG_A				MCUCR
#define EASY_RX_INTERRUPT_REG_B				GICR

#define EASY_RX_INTERRUPT					INT0_vect
#define EASY_RX_INTERRUPT_EDGE_CONFIG		(1 << ISC00)
#define EASY_RX_INTERRUPT_ENABLE			(1 << INT0)


#define EASY_RX_BUFFER_SIZE					20u

#define EASY_TRANSMIT_TICKS_PER_MS				1u

#define EASY_SET_TX()							 \
		(EASY_TX_PORT |= (1 << EASY_TX_PIN))
		
#define EASY_CLEAR_TX()							\
		(EASY_TX_PORT &= ~(1 << EASY_TX_PIN))


void Easy_Init(void);

void Easy_TransmitChar(char p);

void Easy_TransmitSyncField(void);

void Easy_TransmitString(char* string, uint8_t stringLength, uint16_t* buffer);

#endif /* EASY_H_ */
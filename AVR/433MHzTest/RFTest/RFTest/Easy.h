/*
 * Easy.h
 *
 * Created: 08.10.2016 00:58:54
 *  Author: AP
 */ 


#ifndef EASY_H_
#define EASY_H_
#include <avr/io.h>

#define EASY_RX_PORT			PORTA

#define EASY_TX_PORT			PORTB

#define EASY_RX_PIN				PINA0
#define EASY_TX_PIN				PINB0

#define EASY_BYTE_TRANSMIT_TIME_MS 1u

void Easy_Init(void);

void Easy_TransmitChar(char p);


#endif /* EASY_H_ */
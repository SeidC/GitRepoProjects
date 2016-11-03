/*
 * Easy_Cfg.h
 *
 * Created: 28.10.2016 23:08:19
 *  Author: AP
 */ 


#ifndef EASY_CFG_H_
#define EASY_CFG_H_
#include "avr/io.h"
#include "avr/interrupt.h"
#include "util/delay.h"
#include "Timer1.h"


#define EASY_RX_INTERRUPT_ON_ANY_EDGE		(1 << ISC00)
#define EASY_RX_INTERRUPT_ENABLE			   (1 << INT0)

/*--- Tx Port Configuration ----------------------------------------------------------------*/
#define EASY_TX_PORT						PORTD
#define EASY_TX_DDR						DDRD
#define EASY_TX_PIN						PIND1

#define EASY_RX_PORT						PORTD
#define EASY_RX_DDR						DDRD
#define EASY_RX_PIN						PIND2
/*--- Interrupt Rx Configuration ----------------------------------------------------------*/
#define EASY_RX_INTERRUPT_REG_A				   MCUCR
#define EASY_RX_INTERRUPT_REG_B				   GICR

#define EASY_RX_INTERRUPT_VECTOR_CONFIG		INT0_vect
#define EASY_RX_INTERRUPT_EDGE_CONFIG		   EASY_RX_INTERRUPT_ON_ANY_EDGE
#define EASY_RX_INTERRUPT_ENABLE_CONFIG		EASY_RX_INTERRUPT_ENABLE

#define EASY_RX_POS_US_TIME_OFFSET			((uint16_t)20u)	
#define EASY_RX_EDGE_US_TIME				   ((uint16_t)650u)
#define EASY_RX_NEG_US_TIME_OFFSET			((uint16_t)20u)


/*--- Rx/Tx Settings -----------------------------------------------------------------------*/
#define EASY_SYNC_SIGN							((char)0x55u)
#define EASY_TX_EDGE_US_DELAY					((uint16_t)250u)
#define EASY_RX_BUFFER_SIZE				   ((uint8_t)30u)

#define EASY_TRANSMISSION_START_TIME      ((uint16_t)300u)


/*--- Other Required Interfaces ------------------------------------------------------------*/
#define EASY_GET_TIME	TIMER1_GET_ACTUAL_COUNTER_VALUE


#define EASY_CONVERT_TIME(t)



#endif /* EASY_CFG_H_ */
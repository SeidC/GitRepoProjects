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


/*--- Tx Port Configuration ----------------------------------------------------------------*/
#define EASY_TX_PORT						PORTD
#define EASY_TX_DDR						DDRD
#define EASY_TX_PIN						PIND1

#define EASY_RX_PORT						PORTD
#define EASY_RX_DDR						DDRD
#define EASY_RX_PIN						PIND6
/*--- Interrupt Rx Configuration ----------------------------------------------------------*/

#define EASY_RX_INTERRUPT_VECTOR_CONFIG		TIMER1_CAPT_vect

#define EASY_RX_INTERRUPT_EDGE_CONFIG		   TIMER1_CAPTURE_RISING_EDGE

#define EASY_RX_INTERRUPT_TIME_OFFSET        25u

/*--- Rx/Tx Settings -----------------------------------------------------------------------*/

#define EASY_SYNC_SIGN					   ((char)0x55u)

#define EASY_RX_BUFFER_SIZE            ((uint8_t)30u)




EASY_INLINE void Easy_Cfg_SwitchCapturedEdge(void);

EASY_INLINE uint8_t Easy_Cfg_GetCapturedEdge(void);

/*--- Other Required Interfaces ------------------------------------------------------------*/
#define EASY_GET_TIME	                              \
        Timer1_GetInputCaptureCount


#define EASY_CONVERT_TIME                             \
        TIMER1_CALCULATE_US_TIME_TO_TICKS

#define EASY_CALCULATE_TIME_DIFF               \
        Timer1_CalculateTimeDiffBetweenTimes

#define EASY_WAIT_US                            \
         Timer1_WaitUsHard 

       
extern Easy_Config_t Easy_config;


#endif /* EASY_CFG_H_ */
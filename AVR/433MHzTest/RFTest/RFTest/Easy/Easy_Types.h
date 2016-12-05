/*
 * Easy_Types.h
 *
 * Created: 30.10.2016 11:21:25
 *  Author: AP02
 */ 


#ifndef EASY_TYPES_H_
#define EASY_TYPES_H_
#include "avr/io.h"
#include "Timer1.h"

#define EASY_VOL                                      \
        volatile

#define EASY_VOL_STAT_CONST                           \
        volatile static const

#define EASY_VOL_STAT                                 \
        volatile static

#define EASY_INLINE  
      

#define EASY_LOW				(0u)

#define EASY_HIGH				(1u)

typedef struct 
{
   Timer1_Time_t lastTime;
   Timer1_Time_t currentTime;
   
}Easy_RxStatus_t;


typedef struct
{  
   uint16_t txIndicationMaxTime;
   uint16_t txIndicationMinTime;
   uint16_t txIndicationTime; 
   
   uint16_t baudMax;
   uint16_t baudMin;
   uint16_t baudrate;
}Easy_Config_t; 


typedef enum
{
	EASY_RX_PRE_START=0U,
	EASY_RX_FINISHED,
	EASY_RX_RECEIVE,
	EASY_RX_NO_INDICATION,
	EASY_RX_ERROR,
	EASY_RXFSM_NO_MSG
} EASY_RXFSM_EVENT_T;


#endif /* EASY_TYPES_H_ */
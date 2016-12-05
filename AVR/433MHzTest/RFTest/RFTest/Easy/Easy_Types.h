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

  /*
typedef enum
{
   EASY_NO_INDICATION			= 0x00 ,
   EASY_RX_PRE_START          = 0x01 ,
   EASY_RX_RECEIVE            = 0x02
   
}Easy_RxIndication_t;

          */
typedef struct 
{
   
   uint8_t oBit;
   uint8_t nBit;
   Timer1_Time_t oTime;
   Timer1_Time_t nTime;
   uint16_t timeDiff;
   bool_t start;
   
   uint16_t bitBuffer;
   uint16_t bitCount;
}Easy_RxStatus_t;


typedef struct
{      
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
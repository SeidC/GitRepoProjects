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
      

#define EASY_FALLING_EDGE				(0u)

#define EASY_RISING_EDGE				(1u)


typedef struct 
{
   bool_t firstRxInterrupt;
   Timer1_Time_t lastTime;
   Timer1_Time_t currentTime;

   uint8_t tickCount;
   uint16_t bitBuffer;
}Easy_RxStatus_t;


typedef struct
{  
   uint16_t indicationTime; 
   uint16_t baudrate;
   uint16_t jitter;
}Easy_Config_t; 


typedef struct  
{
     
   uint32_t rxMin;
   uint32_t rxMax;
   uint32_t rxMinDouble;
   uint32_t rxMaxDouble;
   
   uint32_t startMin;
   uint32_t startMax;
        
}Easy_InternalConfig_t;


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
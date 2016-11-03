/*
 * Easy_Types.h
 *
 * Created: 30.10.2016 11:21:25
 *  Author: AP02
 */ 


#ifndef EASY_TYPES_H_
#define EASY_TYPES_H_
#include "avr/io.h"

#define EASY_VOL_STAT_CONST                           \
        volatile static const

#define EASY_VOL_STAT                                 \
        volatile static
        
#define EASY_RX_INTERRUPT                             \
        InterruptRoutine

#define EASY_LOW				(0u)

#define EASY_HIGH				(1u)


typedef enum
{
   EASY_NO_INDICATION			= 0x00 ,
   
   EASY_EXTERN_RX_STA         = 0x10,
   EASY_EXTERN_RX_FIN			= 0x11,
   EASY_EXTERN_RX_RUN			= 0x12,
   
   EASY_INTERN_RX_STA         = 0x20,
   EASY_INTERN_RX_FIN			= 0x21,
   EASY_INTERN_RX_RUN			= 0x22,
}Easy_RxIndication_t;

typedef struct 
{
   uint8_t rxStartBit;
   uint8_t lastBit;
   uint16_t bitBuffer;
   uint16_t bitCount;
   Easy_RxIndication_t indication;
}Easy_RxStatus_t;


typedef struct
{
	uint16_t rxPosOffset;
	uint16_t rxEdgeTime;
	uint16_t rxNegOffset;
	
	uint16_t txBaudrate;
	uint16_t trStTime;
}Easy_Config_t;



#endif /* EASY_TYPES_H_ */
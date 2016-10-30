/*
 * Easy_Types.h
 *
 * Created: 30.10.2016 11:21:25
 *  Author: AP02
 */ 


#ifndef EASY_TYPES_H_
#define EASY_TYPES_H_

#define EASY_VOL_STAT_CONST                           \
        volatile static const

#define EASY_VOL_STAT                                 \
        volatile static
        
#define EASY_RX_INTERRUPT                             \
        InterruptRoutine

typedef enum
{
   EASY_NO_INDICATION = 0x00,
   EASY_EXTERN_RX			 ,
   EASY_INTERN_RX			 ,
}Easy_RxIndication_t;

typedef struct 
{
   uint8_t oldValue;
   uint8_t newValue;
   
}Easy_RxEdge_t;


#endif /* EASY_TYPES_H_ */
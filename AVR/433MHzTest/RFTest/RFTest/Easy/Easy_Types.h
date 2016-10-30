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

#define EASY_LOW				(0u)

#define EASY_HIGH				(1u)


typedef enum
{
   EASY_NO_INDICATION			= 0x00 ,
   
   EASY_EXTERN_RX_FIN			= 0x10,
   EASY_EXTERN_RX_RUN			= 0x11,
   
   EASY_INTERN_RX_FIN			= 0x20,
   EASY_INTERN_RX_RUN			= 0x22,
}Easy_RxIndication_t;

typedef struct 
{
   uint8_t oldValue;
   uint8_t newValue;
   Easy_RxIndication_t indication;
}Easy_RxStatus_t;


#endif /* EASY_TYPES_H_ */
/*
 * CommonTypes.h
 *
 * Created: 08.09.2016 19:53:27
 *  Author: AP
 */ 


#ifndef COMMONTYPES_H_
#define COMMONTYPES_H_
#include "avr/io.h"
#include "avr/interrupt.h"

#ifndef F_CPU
   #warning F_CPU not defined
#endif


typedef volatile uint8_t vuint8_t;

typedef volatile uint16_t vuin16_t;

/*--- Type definiton of Datatype Status_t ---------------------------------------------*/
typedef uint8_t Status_t;
/*--- Possible Parameter of Status_t --------------------------------------------------*/
#define HIGH				((Status_t)1u)
#define LOW					((Status_t)0u)

#define ON					((Status_t)1u)
#define OFF					((Status_t)0u)


typedef uint8_t bool;

#define TRUE  1u
#define FALSE 0u

#endif /* COMMONTYPES_H_ */
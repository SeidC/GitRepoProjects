/*
 * CommonTypes.h
 *
 * Created: 08.09.2016 19:53:27
 *  Author: AP
 */ 


#ifndef COMMONTYPES_H_
#define COMMONTYPES_H_
#include "avr/io.h"

#ifndef F_CPU
   #warning F_CPU not defined
#endif


typedef volatile uint8_t vuint8_t;



#define HIGH				1u

#define LOW					0u
typedef uint8_t Status_t;

#endif /* COMMONTYPES_H_ */
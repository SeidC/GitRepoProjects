/*
 * AVRConfig.h
 *
 * Created: 13.07.2016 21:59:43
 *  Author: AP
 */ 


#ifndef AVRCONFIG_H_
#define AVRCONFIG_H_


#include <stddef.h>
#include "BaseTypes.h"


extern Timer8Config_t timer0;
extern Timer8Config_t timer2;


extern PortConfig_t portA;
extern PortConfig_t portB;
extern PortConfig_t portC;
extern PortConfig_t portD;

#endif /* AVRCONFIG_H_ */
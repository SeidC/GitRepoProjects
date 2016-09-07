/*
 * AVRConfig.h
 *
 * Created: 13.07.2016 21:59:43
 *  Author: AP
 */ 


#ifndef AVRCONFIG_H_
#define AVRCONFIG_H_

#include "BaseTypes.h"




#define INFO_DISPLAY                OFFs


#define OS_NUMBER_OF_TASKS          2u



extern const Timer8Config_t timer0Cfg;
extern const Timer8Config_t timer2Cfg;


extern const PortConfig_t portACfg;
extern const PortConfig_t portBCfg;
extern const PortConfig_t portCCfg;
extern const PortConfig_t portDCfg;

extern UartConfig_t uartCfg;


void * operator new(size_t n);
void operator delete(void * p);

#endif /* AVRCONFIG_H_ */
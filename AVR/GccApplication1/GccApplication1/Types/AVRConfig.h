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


extern Timer8Config_t timer0Cfg;
extern Timer8Config_t timer2Cfg;


extern PortConfig_t portACfg;
extern PortConfig_t portBCfg;
extern PortConfig_t portCCfg;
extern PortConfig_t portDCfg;

extern UartConfig_t uartCfg;

#endif /* AVRCONFIG_H_ */
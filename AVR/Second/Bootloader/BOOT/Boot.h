/*
 * Boot.h
 *
 * Created: 05.05.2016 15:19:57
 *  Author: AP
 */ 


#ifndef BOOT_H_
#define BOOT_H_

#include "Boot_Cfg.h"

void (*Bott_ApplicationStart)( void ) = BOOT_APPLICATION_START_ADDRESS;


#endif /* BOOT_H_ */
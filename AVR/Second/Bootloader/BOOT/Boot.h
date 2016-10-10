/*
 * Boot.h
 *
 * Created: 05.05.2016 15:19:57
 *  Author: AP
 */ 


#ifndef BOOT_H_
#define BOOT_H_

#include "Boot_Cfg.h"

void (*Boot_ApplicationStart)( void ) = BOOT_APPLICATION_ADDRESS;

void (*Boot_BootloaderStart)( void ) =  BOOT_BOOTLOADER_ADDRESS;
#endif /* BOOT_H_ */
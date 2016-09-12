/*
 * HBDrv.h
 *
 * Created: 12.09.2016 22:19:45
 *  Author: AP
 */ 


#ifndef HBDRV_H_
#define HBDRV_H_
#include "CommonTypes.h"
#include "Io.h"

#defines HBDRV_NUMBER_OF_BRIDGES			2

typedef struct 
{
	Io_Port_t port,
	Io_Pin_t  pin,
}HBDrv_Io_t;

typedef struct  
{
	HBDrv_Io_t ioIn1,
	HBDrv_Io_t ioIn2,
	HBDrv_Io_t ioEna,
		
}HBDrv_PortConfig_t;



#endif /* HBDRV_H_ */
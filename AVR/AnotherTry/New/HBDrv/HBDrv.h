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



typedef enum
{
	HBDRV_MOTOR_BRIDGE_1 = 0x00,
	HBDRV_MOTOR_BRIDGE_2	   ,
	HBDRV_NUMBER_OF_BRIDGES

}HBDrv_Bridge_t;


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
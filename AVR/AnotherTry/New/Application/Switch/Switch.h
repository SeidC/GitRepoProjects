/*
 * Switch.h
 *
 * Created: 01.10.2016 23:20:00
 *  Author: AP
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_
#include "Io.h"

#define SWITCH_NUMBER_OF_SWITCHES			((uint8_t)SWITCH_QUANTITY)


typedef enum 
{
	SWITCH_TO_OPEN			= 0x00,
	SWITCH_TO_CLOSE			      ,
	SWITCH_QUANTITY			      ,	

}Switch_Switches_t;


typedef struct 
{
	Status_t autoOn;
	uint16_t timeToAuto;
}Switch_Automation_t;

typedef struct
{
	Io_Config_t io;
	Switch_Automation_t auto;
	
}Switch_Config_t;



void Switch_Init(void);






#endif /* SWITCH_H_ */
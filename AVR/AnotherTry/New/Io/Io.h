/*
 * Io.h
 *
 * Created: 09.09.2016 23:15:08
 *  Author: AP
 */ 


#ifndef IO_H_
#define IO_H_
#include "CommonTypes.h"


typedef enum 
{
	IO_PORT_A		= 0x00,
	IO_PORT_B		= 0x01,
	IO_PORT_C		= 0x02,
	IO_PORT_D		= 0x03,
}Io_Port_t;


typedef enum 
{
	IO_DISABLE		= 0x00,
	IO_ENABLE		= 0x01,
		
}Io_Status_t;


typedef enum 
{
	IO_INPUT		= 0x01,
	IO_OUTPUT		= 0x00,
	
}Io_Direction_t;



void Io_Configure(Io_Port_t port, uint8_t pin,Io_Direction_t dir);

void Io_SetPinStatus(Io_Port_t port, uint8_t pin, Status_t status);

Status_t Io_GetPinStatus(Io_Port_t port, uint8_t pin);


#endif /* IO_H_ */
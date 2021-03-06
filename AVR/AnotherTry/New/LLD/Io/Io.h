/*
 * Io.h
 *
 * Created: 09.09.2016 23:15:08
 *  Author: AP
 */ 


#ifndef IO_H_
#define IO_H_
#include "CommonTypes.h"

#define IO_DDX_OFFSET			0x03u
#define IO_PIN_OFFSET			0x03u
#define IO_PORT_OFFSET			0x03u


typedef enum 
{
	IO_PORT_D		= 0x00,
	IO_PORT_C		= 0x01,
	IO_PORT_B		= 0x02,
	IO_PORT_A		= 0x03,
}Io_Port_t;


typedef enum 
{
	IO_PIN_0		= 0x00,
	IO_PIN_1		      ,
	IO_PIN_2		      ,
	IO_PIN_3		      ,
	IO_PIN_4		      ,
	IO_PIN_5		      ,
	IO_PIN_6		      ,
	IO_PIN_7 	          ,
	
}Io_Pin_t;

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

typedef struct  
{
   Io_Port_t port;
   Io_Pin_t  pin;
}Io_Config_t;

void Io_Configure(Io_Port_t port, Io_Pin_t pin,Io_Direction_t dir);

void Io_SetPinStatus(Io_Port_t port, Io_Pin_t pin, Status_t status);

Status_t Io_GetPinStatus(Io_Port_t port, Io_Pin_t pin);


#endif /* IO_H_ */
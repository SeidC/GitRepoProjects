/*
 * Io.c
 *
 * Created: 09.09.2016 23:14:57
 *  Author: AP
 */ 
#include "Io.h"


void Io_Configure(Io_Port_t port, Io_Pin_t pin, Io_Direction_t dir)
{
	vuint8_t *ddr;
	
	ddr  = (&DDRD + IO_DDX_OFFSET * (uint8_t)port);

	if(dir == IO_INPUT)
	{
		*ddr &= ~(1 << (uint8_t)pin);
	}
	else
	{
		*ddr |= (1 << (uint8_t)pin);
	}
	return;
}



Status_t Io_GetPinStatus(Io_Port_t port, Io_Pin_t pin)
{
	vuint8_t *pinReg;
	pinReg = (&PIND + IO_PIN_OFFSET * (uint8_t)port);
	return (*pinReg & (1 << (uint8_t)pin));
}



void Io_SetPinStatus(Io_Port_t port, Io_Pin_t pin, Status_t status)
{
	vuint8_t *portReg;
	portReg = (&PORTD + IO_PORT_OFFSET * (uint8_t)port);
	if(status == HIGH)
	{
		*portReg |= (1 << (uint8_t)pin);
	}
	else
	{
		*portReg &= ~(1 << (uint8_t)pin);
	}
	return;
}
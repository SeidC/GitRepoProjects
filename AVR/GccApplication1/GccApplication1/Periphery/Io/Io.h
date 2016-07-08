/* 
* Io.h
*
* Created: 08.07.2016 20:04:40
* Author: AP02
*/


#ifndef __IO_H__
#define __IO_H__

#include <avr/io.h>
#include <stdint.h>
#include "Ddr.h"
#include "Port.h"
#include "Pin.h"


class Io : public Ddr, public Port , public Pin
{
//types    
public: 

//variables
public:
protected:

private:
     

//functions
public:
	Io(volatile uint8_t* port);
	~Io();
protected:
private:
	Io( const Io &c );
	Io& operator=( const Io &c );

}; //Io

#endif //__IO_H__

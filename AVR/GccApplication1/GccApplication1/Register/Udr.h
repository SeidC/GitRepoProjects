/* 
* Udr.h
*
* Created: 11.07.2016 22:08:10
* Author: AP
*/


#ifndef __UDR_H__
#define __UDR_H__
#include "RegIf.h"


class Udr : public RegIf
{
//variables
public:
protected:
private:

//functions
public:
	Udr();
	~Udr();
protected:
private:
	Udr( const Udr &c );
	Udr& operator=( const Udr &c );

}; //Udr

#endif //__UDR_H__

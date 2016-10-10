/* 
* TccrB.h
*
* Created: 17.07.2016 00:14:01
* Author: AP
*/


#ifndef __TCCRB_H__
#define __TCCRB_H__
#include "RegIf8.h"

class TccrB : public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	TccrB();
	~TccrB();
protected:
private:
	TccrB( const TccrB &c );
	TccrB& operator=( const TccrB &c );

}; //TccrB

#endif //__TCCRB_H__

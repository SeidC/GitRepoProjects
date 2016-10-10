/* 
* TccrA.h
*
* Created: 17.07.2016 00:13:52
* Author: AP
*/


#ifndef __TCCRA_H__
#define __TCCRA_H__
#include "RegIf8.h"

class TccrA : public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	TccrA();
	~TccrA();
protected:
private:
	TccrA( const TccrA &c );
	TccrA& operator=( const TccrA &c );

}; //TccrA

#endif //__TCCRA_H__

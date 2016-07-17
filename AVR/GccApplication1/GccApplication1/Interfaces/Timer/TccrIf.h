/* 
* TccrIf.h
*
* Created: 17.07.2016 13:18:46
* Author: AP02
*/


#ifndef __TCCRIF_H__
#define __TCCRIF_H__


class TccrIf
{
//functions
public:
	virtual ~TccrIf(){}
	virtual void Method1() = 0;
	virtual void Method2() = 0;

}; //TccrIf

#endif //__TCCRIF_H__

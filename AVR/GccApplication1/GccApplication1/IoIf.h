/* 
* IoIf.h
*
* Created: 08.07.2016 21:27:40
* Author: AP02
*/


#ifndef __IOIF_H__
#define __IOIF_H__


class IoIf
{
//functions
public:
	virtual ~IoIf(){}
	virtual void Method1() = 0;
	virtual void Method2() = 0;

}; //IoIf

#endif //__IOIF_H__

/* 
* TcntIf.h
*
* Created: 17.07.2016 00:57:47
* Author: AP
*/


#ifndef __TCNTIF_H__
#define __TCNTIF_H__
#include "BaseTypes.h"

class TcntIf : public BaseTypes
{
//functions
public:
	virtual ~TcntIf(){}
    virtual uint16_t getTime(void) { return 0;}

}; //TcntIf

#endif //__TCNTIF_H__

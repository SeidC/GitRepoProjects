/* 
* OcrA.h
*
* Created: 17.07.2016 00:15:17
* Author: AP
*/


#ifndef __OCRA_H__
#define __OCRA_H__
#include "RegIf16.h"

class OcrA : public RegIf16 
{
//variables
public:
protected:
private:

//functions
public:
	OcrA();
	~OcrA();
    
protected:
private:
	OcrA( const OcrA &c );
	OcrA& operator=( const OcrA &c );

}; //OcrA

#endif //__OCRA_H__

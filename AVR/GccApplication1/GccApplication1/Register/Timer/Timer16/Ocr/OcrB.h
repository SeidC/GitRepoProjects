/* 
* OcrB.h
*
* Created: 17.07.2016 00:15:28
* Author: AP
*/


#ifndef __OCRB_H__
#define __OCRB_H__
#include "RegIf16.h"

class OcrB : public RegIf16
//variables
public:
protected:
private:

//functions
public:
	OcrB();
	~OcrB();
protected:
private:
	OcrB( const OcrB &c );
	OcrB& operator=( const OcrB &c );

}; //OcrB

#endif //__OCRB_H__

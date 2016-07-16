/* 
* OcrB.h
*
* Created: 17.07.2016 00:15:28
* Author: AP
*/


#ifndef __OCRB_H__
#define __OCRB_H__
#include "RegIf16.h"
#include "OcrIf.h"

class OcrB : public RegIf16 , public OcrIf
{
//variables
public:
protected:
private:

//functions
public:
	OcrB();
	~OcrB();
    void setOutputCompare(uint16_t value);
    void getOutputCompare(uint16_t *ptr);
protected:
private:
	OcrB( const OcrB &c );
	OcrB& operator=( const OcrB &c );

}; //OcrB

#endif //__OCRB_H__

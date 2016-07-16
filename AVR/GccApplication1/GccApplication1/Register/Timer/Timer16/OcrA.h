/* 
* OcrA.h
*
* Created: 17.07.2016 00:15:17
* Author: AP
*/


#ifndef __OCRA_H__
#define __OCRA_H__
#include "RegIf16.h"
#include "OcrIf.h"

class OcrA : public RegIf16 , public OcrIf
{
//variables
public:
protected:
private:

//functions
public:
	OcrA();
	~OcrA();
       
    void setOutputCompare(uint16_t value);
    void getOutputCompare(uint16_t *ptr);
protected:
private:
	OcrA( const OcrA &c );
	OcrA& operator=( const OcrA &c );

}; //OcrA

#endif //__OCRA_H__

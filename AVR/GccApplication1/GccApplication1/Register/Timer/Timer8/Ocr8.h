/* 
* Ocr8.h
*
* Created: 17.07.2016 13:12:44
* Author: AP02
*/


#ifndef __OCR8_H__
#define __OCR8_H__
#include "OcrIf.h"
#include "RegIf8.h"

class Ocr8 : public OcrIf, public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	Ocr8();
	~Ocr8();
protected:
private:
	Ocr8( const Ocr8 &c );
	Ocr8& operator=( const Ocr8 &c );

}; //Ocr8

#endif //__OCR8_H__

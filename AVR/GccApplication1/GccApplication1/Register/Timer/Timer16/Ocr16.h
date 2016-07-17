/* 
* Ocr16.h
*
* Created: 17.07.2016 13:14:18
* Author: AP02
*/


#ifndef __OCR16_H__
#define __OCR16_H__
#include "OcrA.h"
#include "OcrB.h"
#include "OcrIf.h"

class Ocr16 : public OcrIf
{
//variables
public:
protected:
private:
    OcrB ocrb;
    OcrA ocra;
//functions
public:
	Ocr16();
	~Ocr16();
protected:
private:
	Ocr16( const Ocr16 &c );
	Ocr16& operator=( const Ocr16 &c );

}; //Ocr16

#endif //__OCR16_H__

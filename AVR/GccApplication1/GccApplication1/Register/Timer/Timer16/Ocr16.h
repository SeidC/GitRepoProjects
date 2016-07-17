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
//types 
public: 
    enum OutputCompareRegister_e
    {
        OCR_A,
        OCR_B  
    };     
    
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
    
    void setOutputCompare(OutputCompareRegister_e ocr, uint16_t value);
    void getOutputCompare(OutputCompareRegister_e ocr, uint16_t* ptr);
protected: 
private:
	Ocr16( const Ocr16 &c );
	Ocr16& operator=( const Ocr16 &c );

}; //Ocr16

#endif //__OCR16_H__

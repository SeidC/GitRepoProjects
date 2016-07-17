/* 
* Ocr16.cpp
*
* Created: 17.07.2016 13:14:18
* Author: AP02
*/


#include "Ocr16.h"

// default constructor
Ocr16::Ocr16()
{
} //Ocr16

// default destructor
Ocr16::~Ocr16()
{
} //~Ocr16


 void Ocr16::setOutputCompare(OutputCompareRegister_e ocr, uint16_t value)
 {
     if(ocr == OCR_A) 
     {
         ocra.setValue(value);
     }
     else
     {
        ocrb.setValue(value);        
     }
 }
 
 void Ocr16::getOutputCompare(OutputCompareRegister_e ocr, uint16_t* ptr)
 {
     if(ocr == OCR_A)
     {
         ocra.getValue(ptr);
     }
     else
     {
         ocrb.getValue(ptr);
     }
 }
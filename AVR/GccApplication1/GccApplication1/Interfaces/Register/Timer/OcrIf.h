/* 
* OcrIf.h
*
* Created: 17.07.2016 00:57:17
* Author: AP
*/


#ifndef __OCRIF_H__
#define __OCRIF_H__
#include "RegIf16.h"

class OcrIf : public RegIf16 
{
//types
public:
   enum OutputCompareRegister_e
   {
      OCR_A,
      OCR_B
   };

//functions
public:
	virtual ~OcrIf(){}
	virtual void setOutputCompare(uint8_t value) {};            	
   virtual uint16_t getOutputCompare(void)  {};
   virtual void setOutputCompareTime(uint8_t msTime) {};
   virtual uint16_t getOutputCompareTime(void) {};
    
}; //OcrIf

#endif //__OCRIF_H__

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
protected::
   enum OutputCompareRegister_e
   {
      OCR_A,
      OCR_B
   };

//functions
public:
	virtual ~OcrIf(){}
	virtual void setOutputCompare(uint8_t value) = 0;            	
   virtual uint16_t getOutputCompare(void) = 0;
   virtual void setOutputCompareTime(uint8_t msTime) = 0;
   virtual uint16_t getOutputCompareTime(void) = 0;
    
}; //OcrIf

#endif //__OCRIF_H__

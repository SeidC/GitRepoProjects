/* 
* Ocr16.h
*
* Created: 17.07.2016 13:14:18
* Author: AP02
*/


#ifndef __OCR16_H__
#define __OCR16_H__
#include "OcrIf.h"
#include "RegIf16.h"

class Ocr16 : public OcrIf , public RegIf16
{
//types 
public: 
  
    
//variables
public:
protected:
private:
   
//functions
public:
	Ocr16();
	~Ocr16();
    
   void setOutputCompare(uint16_t rawValue);
   uint16_t getOutputCompare(void);
   void setOutputCompareTime(uint8_t msTime);
   uint16_t getOutputCompareTime(void);
protected: 
private:
	Ocr16( const Ocr16 &c );
	Ocr16& operator=( const Ocr16 &c );

}; //Ocr16

#endif //__OCR16_H__

/* 
* OcrIf.h
*
* Created: 17.07.2016 00:57:17
* Author: AP
*/


#ifndef __OCRIF_H__
#define __OCRIF_H__
#include "BaseTypes.h"

class OcrIf : public BaseTypes
{
//functions
public:
	virtual ~OcrIf(){}
        
	virtual void     setOutputCompare(uint8_t value)  = 0;
    	
    virtual uint16_t getOutputCompare(void)           = 0;
    
}; //OcrIf

#endif //__OCRIF_H__

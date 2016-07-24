/* 
* Ocr8.cpp
*
* Created: 17.07.2016 13:12:44
* Author: AP02
*/


#include "Ocr8.h"

// default constructor
Ocr8::Ocr8(vuint8_t* ocrPtr)
{
    setRegister(ocrPtr);
} //Ocr8

// default destructor
Ocr8::~Ocr8()
{
} //~Ocr8

void Ocr8::setOutputCompare(uint8_t value)
{
    setValue(value);
}

uint16_t Ocr8::getOutputCompare(void)
{
    return getValue();
}
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


 void Ocr16::setOutputCompare(uint16_t rawValue)
 {
   setValue(rawValue);
 }
 
 uint16_t Ocr16::getOutputCompare(void)
 {  
   return getValue();
 }



void Ocr16::setOutputCompareTime(uint8_t msTime)
{

}
 
uint16_t Ocr16::getOutputCompareTime(void)
{


}
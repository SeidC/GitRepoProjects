/* 
* Port.h
*
* Created: 08.07.2016 20:59:14
* Author: AP02
*/


#ifndef __PORT_H__
#define __PORT_H__
#include "RegIf.h"

class Port : public RegIf
{
//variables
public:
protected:

//functions
public:
	Port();
	~Port();
    void setOutput(BaseTypes::Bits_e bit,BaseTypes::boolean status);
    void setPullUp(BaseTypes::Bits_e bit,BaseTypes::boolean status);
    
private:
	Port( const Port &c );
	Port& operator=( const Port &c );

}; //Port

#endif //__PORT_H__

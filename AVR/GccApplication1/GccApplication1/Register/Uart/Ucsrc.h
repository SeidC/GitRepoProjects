/* 
* Ucsrc.h
*
* Created: 11.07.2016 22:08:34
* Author: AP
*/


#ifndef __UCSRC_H__
#define __UCSRC_H__
#include "RegIf8.h"

class Ucsrc : public RegIf8
{
//types
public:
    enum ParityMode_t
    {
       PARITY_DISABLED        = 0x00,
       EVEN_PARITY            = 0x02,
       ODD_PARITY             = 0x03,
        
    };
    
    /**
 * @brief 
 */
    enum TransmitionMode_t
    {
        SYNCHRONOUS_MODE                  = 0x00,
        ASYNCHRONOUS_MODE                 = 0x01,
        ASYNCHRONOUS_MODE_W_DOUBLE_SPEED  = 0x00,
    };
    
    enum StopBit_t
    {
        ONE_STOP_BIT = 0x00,
        TWO_STOP_BIT = 0x01
    };

    /**
     * @brief 
     */
    enum DataSize_t
    {
       DATA_SIZE_5_BIT    = 0x00,
       DATA_SIZE_6_BIT    = 0x01,
       DATA_SIZE_7_BIT    = 0x02,
       DATA_SIZE_8_BIT    = 0x03,
       DATA_SIZE_9_BIT    = 0x07,
    };
//variables
public:
protected:
private:

//functions
public:
	Ucsrc(vuint8_t* ucsrcPtr);
	~Ucsrc();
    void setMode();
protected:
private:
	Ucsrc( const Ucsrc &c );
	Ucsrc& operator=( const Ucsrc &c );

}; //Ucsrc

#endif //__UCSRC_H__

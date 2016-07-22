/*
 * GccApplication1.cpp
 *
 * Created: 08.07.2016 19:59:56
 * Author : AP02
 */ 

#include <avr/io.h>
#include "Io.h"



int main(void)
{
    Io ioPortB(&PORTB);
    Io ioPortA(&PORTA);
    
    BaseTypes::BitStatus_e stat;
    ioPortB.setDirection(Io::BIT_0,Io::OUTPUT);
    ioPortA.setDirection(Io::BIT_0,Io::INPUT);
  
      
      
      
    
      //((value & (bit+1)) >> bit )
    
    /* Replace with your application code */
    while (1) 
    {
       
        
        stat = ioPortA.getPin(Pin::PIN_0);
        if(stat == BaseTypes::BIT_HIGH)
        {
            ioPortB.setPin(Port::PIN_0,Port::PIN_HIGH);
        }        
    }
}


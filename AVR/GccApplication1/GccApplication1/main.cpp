/*
 * GccApplication1.cpp
 *
 * Created: 08.07.2016 19:59:56
 * Author : AP02
 */ 

#include <avr/io.h>
#include "Io.h"
#include "AVRConfig.h"
#include "Os.h"
#include "Timer16.h"



int main(void)
{
    Os os;
    Timer16 timer;
    os.setOsTimer(&timer);
    /* Replace with your application code */
    while (1) 
    {
   
   
    }
}


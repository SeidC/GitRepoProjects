#include <stdio.h>
#include "Manchester.h"

uint8_t buffer[MANCHESTER_CALCULATE_DATA_SIZE(1)];


Manchester_t data =
{
  buffer,
  0,
};


int main(int argc, char *argv[])
{
    char i= 0x24;

    Manchester_EncodeChar(i,&data);
    return 0;
}

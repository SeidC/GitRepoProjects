#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0xFF;

    i += -(0 << 2);

    return 0;
}

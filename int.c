#include <stdio.h>

int main(int argc, char const *argv[])
{
    char i;

    i =  (150 >> 4) + (150 << 4);
    // printf("%d\n", i);
    // int b = i << 4;
    // i += b;0110 0000 + 1001
    printf("%d == %d == %d\n", i, 0b01101001, );
    return 0;
}

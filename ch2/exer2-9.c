#include <stdio.h>
#include <limits.h>

int bitcountFaster(unsigned x);
int bitcount(unsigned x);

int bitcountFaster(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1))
        ++b;
    return b;
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>=1)
        if (x & 01)
            b++;
    return b;
}

int main()
{
    unsigned long x = 46;
    printf("number of 1 bits in %lu = %d\n", x, bitcount(x));
    printf("number of 1 bits in %lu = %d\n", x, bitcountFaster(x));
}    

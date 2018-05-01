#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

unsigned setbits(unsigned x, int p, int n, unsigned y)
/* return x with n bits beginning at position p set to 
   rightmost n bits of y */
{
    
    return (x | (getbits(y, n+1, n) << p));
}

unsigned getbits(unsigned x, int p, int n)
/* get n bits of x from position p */
{
    // ~(~0 << n) makes mask for rightmost n bits
    // x >> (p+1-n) moves desired fields to the right
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main()
{
    printf("%d\n", setbits(14, 4, 3, 7));
}

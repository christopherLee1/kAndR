#include <limits.h>
#include <stdio.h>

/* Find ranges of certain types, exclude calculation for longs
   because the calculation takes forever. */

int main()
{
    signed char sc;
    unsigned char uc;
    signed int si;
    unsigned int ui;
    signed short ss;
    unsigned short us;
    signed long sl;
    unsigned long ul;
    int i;
    long li;

    printf("Ranges from limits.h\n");
    printf("Range of unsigned char: 0 -> %d\n",UCHAR_MAX);    
    printf("Range of unsigned short: 0 -> %d\n", USHRT_MAX);    
    printf("Range of unsigned int: 0 -> %u\n", UINT_MAX);    
    printf("Range of unsigned long: 0 -> %lu\n", ULONG_MAX);    
    printf("Range of signed char: %d -> %d\n", SCHAR_MIN, SCHAR_MAX);    
    printf("Range of signed short: %d -> %d\n", SHRT_MIN, SHRT_MAX);    
    printf("Range of signed int: %d -> %d\n", INT_MIN, INT_MAX);    
    printf("Range of signed long: %ld -> %ld\n", LONG_MIN, LONG_MAX);    

    printf("\nRanges via calculation\n");

    uc = 1;
    for (i = 0; uc > 0; ++i) {
        ++uc;
    }
    printf("Range of unsigned char = %d -> %d\n", uc, i);

    us = 1;
    for (i = 0; us > 0; ++i) {
        ++us;
    }
    printf("Range of unsigned short = %d -> %d\n", us, i);

    ui = 1;
    for (i = 0; ui > 0; ++i) {
        ++ui;
    }
    printf("Range of unsigned int = %u -> %u\n", ui, i);

    /*ul = 1;
    for (li = 0; ul > 0; ++li) {
        ++ul;
    }
    printf("Range of unsigned long = %ld -> %ld\n", ul, li);
    */

    sc = 1;
    for (i = 0; sc > 0; ++i) {
        ++sc;
    }
    printf("Range of signed char = %d -> %d\n", sc, i);

    ss = 1;
    for (i = 0; ss > 0; ++i) {
        ++ss;
    }
    printf("Range of signed short = %d -> %d\n", ss, i);

    si = 1;
    for (i = 0; si > 0; ++i) {
        ++si;
    }
    printf("Range of signed int = %d -> %d\n", si, i);

    /*
    sl = 1;
    for (li = 0; sl > 0; ++li) {
        ++sl;
    }
    printf("Range of signed long = %ld -> %ld\n", sl, li);
    */
}

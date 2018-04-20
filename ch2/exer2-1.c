#include <limits.h>
#include <stdio.h>

int main()
{
    printf("Ranges from limits.h\n");
    printf("Range of unsigned char: 0 -> %d\n",UCHAR_MAX);    
    printf("Range of unsigned short: 0 -> %d\n", USHRT_MAX);    
    printf("Range of unsigned int: 0 -> %d\n", UINT_MAX);    
    printf("Range of unsigned long: 0 -> %lu\n", ULONG_MAX);    
    printf("Range of signed char: %d -> %d\n", SCHAR_MIN, SCHAR_MAX);    
    printf("Range of signed short: %d -> %d\n", SHRT_MIN, SHRT_MAX);    
    printf("Range of signed int: %d -> %d\n", INT_MIN, INT_MAX);    
    printf("Range of signed long: %ld -> %ld\n", LONG_MIN, LONG_MAX);    

    printf("Ranges via calculation\n");
    printf("Range of unsigned char: %d -> %d\n", 0, ((unsigned char) ~0));
    /*printf("Range of unsigned short: %d -> %d\n", tmp1, tmp2);
    printf("Range of unsigned int: %d -> %d\n", tmp1, tmp2);
    printf("Range of unsigned long: %d -> %d\n", tmp1, tmp2);
    */
    printf("Range of signed char: %d -> %d\n", -(char)((unsigned char) ~0 >> 1) - 1, ((unsigned char) ~0 >> 1));
    /*printf("Range of signed short: %d -> %d\n", tmp1, tmp2);
    printf("Range of signed int: %d -> %d\n", tmp1, tmp2);
    printf("Range of signed long: %d -> %d\n", tmp1, tmp2);*/
}

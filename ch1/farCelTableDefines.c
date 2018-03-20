#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main () 
{
    int far;
    for (far=LOWER; far <= UPPER; far+=STEP)
        printf("%3d\t%6.2f\n", far, (5.0/9.0) * (far-32));
}

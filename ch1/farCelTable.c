#include <stdio.h>

int main()
{
    float far, cel;
    int lower,upper,step;

    lower = 0;
    upper = 300;
    step = 20;
 
    cel = lower;
    printf("celsius\tfahrenheit\n");
    while (cel <= upper)
    {
        far = (cel / (5.0/9.0)) + 32;
        printf("%3.0f\t%6.2f\n", cel, far);
        cel += step;
    }
}

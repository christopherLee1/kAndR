#include <stdio.h>
#define square(x) x * x
#define swap(t,x,y) t temp = x; x = y; y = x;

int main()
{
int z = 1;
printf("%d\n", square(z+1));
z = 2;
printf("%d\n", square(z+1));
int x = 6; int y = 4;
swap(int, x, y);
printf("swap(int,6,4)=%d\n", y);
}

#include <stdio.h>

int main()
{
    int c;
    while (c = getchar() != EOF) {
        if (c == 0)
            putchar(c);
        else putchar('1');
    }
}

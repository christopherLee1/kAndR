#include <stdio.h>

int lower(int c);

/* conditional expression version */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main()
{
    printf("%c\n", lower('A'));
}

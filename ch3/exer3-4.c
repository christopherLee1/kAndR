#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse (char s[]);
void itoa (int n, char s[]);

/* reverse: reverse string s in place */
void reverse (char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa (int n, char s[])
{
    int i, sign;
    unsigned pos;
    if ((sign = n) < 0) // record sign
        /* if n is maximum negative number, then making it positive can't
            be represented by regular ints because they only go to 2^(wordize-1)-1
        */
        pos = -n; // make n positive
    i = 0;
    do {
        s[i++] = pos % 10 + '0';
    } while ((pos /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n = -INT_MIN;
    char s[128];
    itoa(n, s);
    printf("n = %d, s = %s\n", n, s);
}

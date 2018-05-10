#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse (char s[]);
void itoa (int n, char s[], int b);

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

/* itoa: convert n character representation into s, with b number padding */
void itoa (int n, char s[], int b)
{
    int i, sign;
    unsigned pos;
    if ((sign = n) < 0) // record sign
        pos = -n; // make n positive
    else
        pos = n;
    i = 0;
    do {
        s[i++] = '0' + pos % 10;
    } while ((pos /= 10) > 0);
    while (i < b)
        s[i++] = '0';
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n = -16;
    char s[128];
    int b = 5;
    itoa(n, s, b);
    printf("n = %d, s = %s\n", n, s);
}

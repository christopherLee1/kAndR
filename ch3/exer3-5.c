#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse (char s[]);
void itob (int n, char s[], int b);

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

/* itob: convert n into a base b representation of characters into s */
void itob (int n, char s[], int b)
{
    int i, sign;
    unsigned pos;
    if ((sign = n) < 0) // record sign
        pos = -n; // make n positive
    else
        pos = n;
    i = 0;
    do {
        if (pos % b < 10)
            s[i++] = '0' + pos % b;
        else
            s[i++] = 'A' + (pos % b - 10);
    } while ((pos /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n = 16;
    char s[128];
    int b = 17;
    itob(n, s, b);
    printf("n = %d, s = %s\n", n, s);
}

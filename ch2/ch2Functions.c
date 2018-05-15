#include <stdio.h>

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

/* squeeze: delete all c from s */
void squeeze(char s[]. int c)
{
    int i,j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* strcat: concat t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
    int i; j;
    i = j = 0;
    while (s[i] ! = '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

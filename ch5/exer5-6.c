#include <stdio.h>
#include <ctype.h>
#include <string.h> // for strlen only

int getLine(char *s, int lim)
{
int c;
char *p = s; // need this pointer so s still points to the beginning
while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    *p++ = c;
if (c == '\n')
    *p++ = c;
*p = '\0';
return p-s;
}

/* atoi with pointers */
int atoi1(char *s)
{
int n, sign;
for (; isspace(*s); s++)
    ;
sign = (*s == '-') ? -1 : 1;
if (*s == '+' || *s == '-')
    s++;
for (n = 0; isdigit(*s); s++)
    n = 10 * n + (*s - '0');
return sign *n;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
int i, k;
for (i = 0; *s != '\0'; s++, i++)
{
    for (k = 0; *t != '\0' && *s == *t; k++)
    {
        ++s;
        ++t;
    }
    if (k > 0 && *t == '\0')
        return i;
    else
    {
        s -= k;
        t -= k;
    }
}
return -1;
}

#define MAXLINE 1000

int main()
{
    // strindex test
    //char *s = "index 0 negative 1";
    //char *t = "negative";
    //printf("strindex(%s,%s): %d, should be 8\n", s, t, strindex(s,t));

    // atoi test
    //char *s = "123456";
    //printf("atoi(%s) = %d\n", s, atoi1(s));

    // getline test
    int len, i;
    char s[MAXLINE];
    while ((len = getLine(s, MAXLINE)) > 0)
    {
        for  (i = 0; i < len/2; i++) // only print half the line as a simple test
            printf("%c", s[i]);
        printf("\n");
    }
}

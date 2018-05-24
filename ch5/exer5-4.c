#include <stdio.h>

int strlenMy(char *s)
{
int i = 0;
while (*s++)
    ++i;
return i;
}

int strendMy(char *s, char *t)
{
int i = 0, j = 0;
i = strlenMy(t);
j = strlenMy(s);
if (j < i)
    return 0;
s += j - i;
while (*t != '\0')
{
    if (*s != *t)
        return 0;
    t++;
    s++;
}
return 1;
}

int main()
{
    char s[] = "hello oh";
    char t[] = "oh";
    printf("return %d\n", strendMy(s, t));
}

#include <stdio.h>

void strcatMy(char *s, char *t)
{
while (*s != '\0') /* get to end of array */
    s++;
while ((*s++ = *t++)) /* copy t into s */
    ;
}

int main()
{
    char s[100] = "hello";
    char t[] = " world";
    strcatMy(s, t);
    printf("s after strcat = %s\n", s);
}

#include <stdio.h>

int strlenMy(char *s)
{
char *i = s;
while (*i != '\0')
    i++;
return i-s;
}

/* copies n chars of t to beginning of s */
char *strncpyMy(char *s, char *t, int n)
{
if (n > strlenMy(t))
    n = strlenMy(t);
int i = 0;
char *r = s;
while (i < n)
{
    *r++ = *t++;
    ++i;
}
return r-n;
}

/* copy at most n chars of t onto s */
char *strncatMy(char *s, char *t, int n)
{
if (n > strlenMy(t))
    n = strlenMy(t);
int i = strlenMy(s);
int j = 0;
char *r = s;
r += i;
while (j < n)
{
    *r++ = *t++;
    *r = '\0'; // plug if we're about to finish
    ++j;
}
return r-i-n;
}

/* compare at most n chars of s with t */
int strncmpMy(char *s, char *t, int n)
{
if (n > strlenMy(t))
    n = strlenMy(t);
int i = 0;
for (; *s == *t && i < n; s++, t++, i++)
{
    if (*(t+1) == '\0')
        return 0;
}
return *s - *t;
}

int main()
{
    char *r1, *r2;
    int r3, r4, r5;
    char s1[] = "hello oh";
    char t1[] = "oh";

    char s2[] = "hello oh";
    char t2[] = "world";
    
    char s3[] = "hello oh";
    char t3[] = "oh";

    char s4[] = "x1ello oh";
    char t4[] = "x1el";

    char s5[] = "hello oh";
    char t5[] = "ae";

    printf("strncpyMy(%s, %s, 2): ", s1, t1);
    r1 = strncpyMy(s1, t1, 3); // "ohllo oh"
    printf("%s\n", r1);

    printf("strncat(%s, %s, 2): ", s2, t2);
    r2 = strncatMy(s2, t2, 2); // "hello ohoh"
    printf("%s\n", r2);
    r3 = strncmpMy(s3, t3, 2); // " return -number
    r4 = strncmpMy(s4, t4, 2); // " return 0
    r5 = strncmpMy(s5, t5, 4); // " return +number
    
    printf("strncmp(%s, %s, 2): %d\n", s3, t3, r3);
    printf("strncmp(%s, %s, 2): %d\n", s4, t4, r4);
    printf("strncmp(%s, %s, 2): %d\n", s5, t5, r5);
}

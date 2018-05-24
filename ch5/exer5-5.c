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
return 0;
}

/* return 1 if t is at the end s, 0 otherwise */
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
    char *r1, *r2;
    int r3, r4;
    char s1[] = "hello oh";
    char t1[] = "oh";

    char s2[] = "hello oh";
    char t2[] = "world";
    
    char s3[] = "hello oh";
    char t3[] = "oh";

    char s4[] = "hello oh";
    char t4[] = "he";

    printf("strncpyMy(%s, %s, 2): ", s1, t1);
    r1 = strncpyMy(s1, t1, 3); // "ohllo oh"
    printf("%s\n", r1);

    printf("strncat(%s, %s, 2): ", s2, t2);
    r2 = strncatMy(s2, t2, 2); // "hello ohoh"
    printf("%s\n", r2);
    //r3 = strncmpMy(s3, t3, 2); // " return 0
    //r4 = strncmpMy(s4, t4, 2); // " return 1
    
    //printf("strncmp(%s, %s, 2): %s\n", s3, t3, strncmp(s3, t3, 2));
    //printf("strncmp(%s, %s, 2): %s\n", s3, t3, strncmp(s4, t4, 2));
}

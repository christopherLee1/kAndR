#include <ctype.h>
#include <stdio.h>
#include "ch5Code.h"

//#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
if (allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
{
    allocp += n;
    return allocp - n; /* old p */
} else /* not enough room */
    return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

/* strcpyA: copy t to s; array subscript version */
void strcpyA(char *s, char *t)
{
int i = 0;
while ((s[i] = t[i]) != '\0')
    i++;
}

/* strcpyB: copy t to s; pointer version */
void strcpyB(char *s, char *t)
{
while ((*s = *t) != '\0')
{
    s++;
    t++;
}
}

/* strcpyC: copy t to s, cool version */
void strcpyC(char *s, char *t)
{
while ((*s++ = *t++))
;
}

/* strcmpA: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmpA(char *s, char *t)
{
int i;
for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
        return 0;
    return s[i] - t[i];
}

/* strcmpB: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmpB(char *s, char *t)
{
for (; *s == *t; s++, t++)
    if (*s == '\0')
        return 0;
    return *s - *t;
}

int getch(void);
void ungetch(int);

/* getint : get next integer from input into *pn */
int getint(int *pn)
{
int c, sign;
while (isspace(c=getch())) /* skip white space */
    ;
if (!isdigit(c) && c!= EOF && c != '+' && c != '-')
    {
    ungetch(c);
    return 0;
    }
sign = (c == '-') ? -1 : 1;
if (c == '+' || c == '-')
    c = getch();
for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
*pn *= sign;
if (c != EOF)
    ungetch(c);
return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int getch(void) /* get a (possibly pushed back) character */
{
return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
else
    buf[bufp++] = c;
}

//#define MAXLEN 1000 /* max length of single line */

/* getLine: read at most lim chars into s */
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

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    if (p != NULL)
        //printf("freeing p\n");
        afree(p);
    return nlines;
}

/* writelines: write output lines to stdout */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/*
#define SIZE 10

int main()
{
int n, array[SIZE];//, getint(int *);
for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;
printf("array: ");
for (n = 0; n < SIZE; n++)
    printf("%d ", array[n]);
printf("\n");
}*/

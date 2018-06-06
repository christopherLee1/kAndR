#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

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

int main()
{
    int nlines; /* num input lines to read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return -1;
    }
}

#define MAXLEN 1000 /* max length of single line */
int getLine(char *, int);
char *alloc(int);

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
        printf("freeing p\n");
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

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
char *tmp; // each elem of v is also a pointer
tmp = v[i];
v[i] = v[j];
v[j] = tmp;
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
int i, last;
if (left >= right)
    return;
swap(v, left, (left + right) / 2);
last = left;
for (i = left+1; i <= right; i++)
{
    if (strcmp(v[i], v[left]) > 0)
        swap(v, ++last, i);
}
swap(v, left, last);
qsort(v, left, last-1);
qsort(v, last+1, right);
}

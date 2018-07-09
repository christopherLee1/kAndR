#include "ch5Code.h"

char *lineptr[MAXLINES];
int fold = 0;

int numCmp(char *s1, char *s2)
/* return <0 if s1<s2, 0 if s1==s2, >0 s1==s2 */
{
double v1, v2;
v1 = strtod(s1, NULL);
v2 = strtod(s2, NULL);
if (v1 < v2)
    return -1;
else if (v1 > v2)
    return 1;
else
    return 0;
}

int strCmp(char *s1, char *s2)
/* return <0 if s1<s2, 0 if s1==s2, >0 if s1>s2 */
{
for (; *s1 == *s2 || (fold && (tolower(*s1) == tolower(*s2))); s1++, s2++)
    {
    if (*s1 == '\0')
        {
        return 0;
        }
    }
return *s1 - *s2;
}

void swap(void *v[], int i, int j)
{
void *temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}

void qSort(void *v[], int left, int right, int reverse, int (*comp)(void *, void *))
/* sort v[left]..v[right] into order specified by comp */
{
int i, last;
char *tmp1, *tmp2;
if (left >= right)
    return;
swap(v, left, (left + right)/2);
last = left;
for (i = left + 1; i <= right; i++)
    {
    if (reverse && ((*comp)(v[i], v[left]) > 0))
        swap(v, ++last, i);
    if (!reverse && ((*comp)(v[i], v[left]) < 0))
        {
        swap(v, ++last, i);
        }
    }
swap(v, left, last);
qSort(v, left, last-1, reverse, comp);
qSort(v, last+1, right, reverse, comp);
}

int main(int argc, char *argv[])
{
int nlines, i, j;
int numeric = 0; // 1 if numeric sort
int reverse = 0; // 1 if reverse order
fold = 0; // 1 if fold case
if (argc > 1)
    {
    for (i = 1; i < argc; i++)
        {
        for (j = 0; j < strlen(argv[i]); j++)
            {
            if ('-' == argv[i][j])
                continue;
            else if ('n' == argv[i][j])
                numeric = 1;
            else if ('r' == argv[i][j])
                reverse = 1;
            else if ('f' == argv[i][j])
                fold = 1;
            else
                printf("unsupported switch -%c\n", argv[i][j]);
            }
        }
    }
printf("numeric = %d, reverse = %d\n", numeric, reverse);
if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
    qSort((void **)lineptr, 0, nlines - 1, reverse,
        (int (*)(void*, void*))(numeric ? numCmp : strCmp));
    writelines(lineptr, nlines);
    return 0;
    }
else
    {
    printf("input too large to be sorted\n");
    return 1;
    }
}

#include "ch5Code.h"

char *lineptr[MAXLINES];
int fold = 0;
int dict = 0;

int dictCmp(char *s1, char *s2)
/* consider only letters, numbers and blanks */
{
int advancedS1 = 0;
int advancedS2 = 0;
while (!(isspace(*s1) || isalnum(*s1)) && *s1 != '\0')
    {
    //printf("advancing s1=%s by one char\n", s1);
    s1++;
    }
while (!(isspace(*s2) || isalnum(*s2)) && *s2 != '\0')
    {
    //printf("advancing s2=%s by one char\n", s2);
    s2++;
    }
if (*s1 != *s2 && s1 == '\0')
    return -1;
else if (*s1 != *s2 && *s2 == '\0')
    return 1;
//printf("s1 = %s, s2 = %s before for\n", s1, s2);
for (; *s1 == *s2 ; s1++ , s2++ )//|| 
        //!(isalnum(*(s1)) || isspace(*(s1))) ||
        //!(isalnum(*(s2)) || isspace(*(s2)))
        //; )
    {
    /*
    printf("first line of for loop *s1 = %c, *s2 = %c\n", *s1, *s2);
    if (!(isalnum(*(s1)) || isspace(*(s1))) && *s2 != '\0')
        {
        printf("if in for s1 = %s, *s1 = %c\n", s1, *s1);
        advancedS1 = 1;
        s1++;
        }
    if (!(isalnum(*(s2)) || isspace(*(s2))) && *s2 != '\0')
        {
        printf("if in for s2 = %s, *s2 = %c\n", s2, *s2);
        advancedS2 = 1;
        s2++;
        }
    
    if (*s1 != *s2 && s1 == '\0')
        return -1;
    else if (*s1 != *s2 && *s2 == '\0')
        {
        printf("does print\n");
        return 1;
        }
    */
        
    //printf("*%s == *%s when %c = %c\n", s1, s2, *s1, *s2);
    if (*s1 == '\0')
        {
        //printf("for comparison %s : %s, returning 0 in for loop\n", s1, s2);
        return 0;
        }
    /*
    if (!advancedS1)
        {
        s1++;
        }
    advancedS1 = 0;
    if (!advancedS2)
        {
        s2++;
        }
    advancedS2 = 0;
    */
    }
//printf("for comparison %s : %s, returning %c-%c=%d\n", s1, s2, *s1, *s2, *s1 - *s2);
return *s1 - *s2;
}

int numCmp(char *s1, char *s2)
/* return <0 if s1<s2, 0 if s1==s2, >0 s1==s2

   strangely enough this does not match gnu sort -n
   on lines with mixed characters. For example:
gnu sort -n:                        this code:
$$$$$                               Sample line 6
&%#@#$fox                           Sample line 1
Sample line 1                       Sample1
Sample line 6                       &%#@#$fox
Sample1                             $$$$$
*/
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
if (dict)
    return dictCmp(s1, s2);
for (; *s1 == *s2 || (fold && (tolower(*s1) == tolower(*s2))); s1++, s2++)
    {
    if (*s1 == '\0')
        {
        return 0;
        }
    }
return *s1 - *s2;
}

void reverseArray(char *old[], char *new[], int nlines)
/* return ptr to reversed array */
{
//printf("reversing array\n");
int i;
//printf("nlines = %d\n", nlines);
for (i = 0; i < nlines; i++) //>= 0 && old[i] != '\0'; i--)
    {
    //printf("old[%d] = %s\n", i, old[i]);
    new[i] = old[nlines - 1 - i];
    }
}

void swap(void *v[], int i, int j)
{
void *temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}

void qSort(void *v[], int left, int right, int (*comp)(void *, void *))
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
    if ((*comp)(v[i], v[left]) < 0)
        {
        swap(v, ++last, i);
        }
    }
swap(v, left, last);
qSort(v, left, last-1, comp);
qSort(v, last+1, right, comp);
}

int main(int argc, char *argv[])
{
int nlines, i, j;
char *reversed[MAXLINES];
int numeric = 0; // 1 if numeric sort
int reverse = 0; // 1 if reverse order
fold = 0; // 1 if fold case
dict = 0;
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
            else if ('d' == argv[i][j])
                dict = 1;
            else
                printf("unsupported switch -%c\n", argv[i][j]);
            }
        }
    }
//printf("numeric = %d, reverse = %d, fold = %d, dictionary = %d\n", numeric, reverse, fold, dict);
if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
    qSort((void **)lineptr, 0, nlines - 1,
        (int (*)(void*, void*))(numeric ? numCmp : strCmp));
    if (reverse)
        {
        reverseArray(lineptr, reversed, nlines);
        writelines(reversed, nlines);
        }
    else
        writelines(lineptr, nlines);
    return 0;
    }
else
    {
    printf("input too large to be sorted\n");
    return 1;
    }
}

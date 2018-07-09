#include "ch5Code.h"

#define DEFAULT_LINES 5
//#define MAXLINES 5000

char *lineptr[MAXLINES];

/* transforms string into integer representation */
int toint(char *c)
{
int i = 0, ret = 0;
for (i = strlen(c)-1; i >= 0; i--)
    {
    if (c[i] == '-')
        ret *= -1;
    if (c[i] == '+')
        continue;
    if (c[i] <= '0' && c[i] >= '9')
        {
        printf("illegal character: %c in expression\n", c[i]);
        }
    else
        {
        ret += (10 * i) + (c[i] - '0');
        }
    }
return ret;    
}

int main(int argc, char **argv)
{
int nlines, i, tmp, n = DEFAULT_LINES;
char arg[8];

while (--argc > 0 && (*++argv)[0] == '-')
    {
    for (i = 1; i < strlen(*argv); i++)
        arg[i-1] = (*argv)[i];
    arg[i] = '\0';
    if ((tmp = toint(arg)) >= 0)
        n = tmp;
    else
        printf("using default %d number of lines\n", DEFAULT_LINES);
    }

if (argc != 0)
    {
    printf("Usage: tail -n file\n");
    }
else
    {
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
        {
        if (n > nlines)
            n = nlines;
        for (i = n - 1; i >= 0 && i < nlines; i--)
            // for n=10 lines printed, print from 9:0 
            {
            printf("%s\n", (lineptr[nlines-1-i]));
            }
        }
    }
}

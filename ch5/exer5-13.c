#include "ch5Code.h"

#define DEFAULT_LINES 5
#define MAXLINES 5000

char *lineptr[MAXLINES];

int main(int argc, char **argv)
{
int nlines, i, tmp, n = DEFAULT_LINES;

while (--argc > 0 && (*++argv)[0] == '-')
    {
    if ((tmp = *++argv[0]) >= 1)
        n = tmp;
    else
        printf("using default %d number of lines\n", DEFAULT_LINES);
    }

if (argc != 1)
    {
    printf("Usage: tail -n file\n");
    }
else
    {
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
        {
        for (i = n - 1; i >= 0 && i < nlines; i--)
            /* for n=10 lines printed, print from 9:0 */
            {
            printf("%s", *(lineptr-i));
            }
        }
    }
}

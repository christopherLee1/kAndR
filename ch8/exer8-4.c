#include "ch8Code.h"
#include <stdio.h>

int main(int argc, char *argv[])
/* test of _fseek */
{
_FILE *fp1;
FILE *fp2;
int i;
char *prog = argv[0]; /* prog name for errors */
if (argc > 2)
    error("only provide one file");
else
    {
    fp1 = _fopen1(argv[1], "r");
    fp2 = fopen(argv[1], "r");
    if (fp1 == _NULL || fp2 == NULL)
        {
        error("%s: can't open %s\n", prog, argv[1]);
        }
    else
        {
        printf("_fseek: first 5 chars of %s: ", argv[1]);
        _fseek(fp1, 0L, 0);
        for (i = 0; i < 5; i++)
            {
            char c = _getc(fp1);
            _putchar(c);
            }
        _fflush(_stdout);
        printf("\n");
        printf("_fseek: last 10 chars of %s: ", argv[1]);
        _fseek(fp1, -10L, 2);
        for (i = 0; i < 10; i++)
            {
            char c = _getc(fp1);
            _putchar(c);
            }
        _fflush(_stdout);
        printf("\n");
        printf("fseek: first 5 chars of %s: ", argv[1]);
        fseek(fp2, 0L, 0);
        for (i = 0; i < 5; i++)
            {
            char c = getc(fp2);
            putchar(c);
            }
        printf("\n");
        printf("fseek: last 10 chars of %s: ", argv[1]);
        fseek(fp2, -10L, 2);
        for (i = 0; i < 10; i++)
            {
            char c = getc(fp2);
            putchar(c);
            }
        printf("\n");
        }
    }
if (_ferror(_stdout))
    {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
    }
exit(0);
}

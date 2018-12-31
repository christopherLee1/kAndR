#include "ch8Code.h"
#include <stdio.h>

int main(int argc, char *argv[])
/* test of fsize, a special ls */
{
_FILE *fp1;
FILE *fp2;
int i;
char *prog = argv[0]; /* prog name for errors */
if (argc == 1)
    fsize(".");
else
    while (--argc > 0)
        fsize(*++argv);
exit(0);
}

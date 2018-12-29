#include "ch8Code.h"

void filecopy(_FILE *ifp, _FILE *ofp)
/* copy file ifp to file ofp */
{
int c;
while ((c = _getc(ifp)) != _EOFERR)
    {
    _putc(c, ofp);
    }
_fflush(ofp);
}

int main(int argc, char *argv[])
/* concatenate files */
{
_FILE *fp;
char *prog = argv[0]; /* prog name for errors */
if (argc == 1)
    filecopy(_stdin, _stdout);
else
    while (--argc > 0)
        if ((fp = _fopen1(*++argv, "r")) == _NULL)
            {
            printf("%s: can't open %s\n", prog, *argv);
            exit(1);
            }
        else
            {
            filecopy(fp, _stdout);
            _fclose(fp);
            }
if (_ferror(_stdout))
    {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
    }
exit(0);
}

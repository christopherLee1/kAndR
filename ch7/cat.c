#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp)
/* copy file ifp to file ofp */
{
int c;
while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}

int main(int argc, char *argv[])
/* concatenate files */
{
FILE *fp;
char *prog = argv[0]; /* prog name for errors */
if (argc == 1)
    filecopy(stdin, stdout);
else
    while (--argc > 0)
        if ((fp = fopen(*++argv, "r")) == NULL)
            {
            printf("%s: can't open %s\n", prog, *argv);
            exit(1);
            }
        else
            {
            filecopy(fp, stdout);
            fclose(fp);
            }
if (ferror(stdout))
    {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
    }
exit(0);
}

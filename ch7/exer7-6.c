#include "ch7Code.h"

int main(int argc, char *argv[])
/* crude version diff */
{
FILE *fp1;
FILE *fp2;
char line1[MAXSIZE];
char line2[MAXSIZE];
int size1;
int size2;

if (argc != 3)
    {
    fprintf(stderr, "Please specify two input files\n");
    exit(1);
    }

if ((fp1 = fopen(*++argv, "r")) == NULL)
    {
    fprintf(stderr, "Can't open file %s\n", *argv);
    exit(1);
    }
if ((fp2 = fopen(*++argv, "r")) == NULL)
    {
    fprintf(stderr, "Can't open file %s\n", *argv);
    exit(1);
    }

while((size1 = getLine(line1, MAXSIZE, fp1)) != 0 && 
        (size2 = getLine(line2, MAXSIZE, fp2)) != 0)
    if (strcmp(line1, line2) != 0)
        {
        printf("files differ:\n%s\n%s\n", line1, line2);
        exit(1);
        }
}

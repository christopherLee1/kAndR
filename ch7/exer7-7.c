#include "ch7Code.h"

int main(int argc, char *argv[])
/* crude version grep */
{
FILE *fp1;
char line[MAXSIZE];
char *searchString;
int size;

if (argc < 2)
    {
    fprintf(stderr, "error, no search text specified\n");
    exit(1);
    }

searchString = argv[1];

if (argc == 3)
    {
    if ((fp1 = fopen(argv[2], "r")) == NULL)
        {
        fprintf(stderr, "Can't open file %s\n", argv[2]);
        exit(1);
        }
    }
else
    {
    fp1 = stdin;
    }

while((size = getLine(line, MAXSIZE, fp1)) != 0)
    {
    if (strstr(line, searchString) != NULL)
        {
        printf("%s", line);
        }
    }
}

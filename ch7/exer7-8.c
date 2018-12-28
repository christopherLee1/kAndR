#include "ch7Code.h"

int main(int argc, char *argv[])
/* crude version grep */
{
FILE *fp1;
char line[MAXSIZE];
int size;
int pc = 1;
int lineNum = 1;

if (argc == 1)
    {
    printf("==== reading stdin\tpage %d====\n", pc++);
    while((size = getLine(line, MAXSIZE, stdin)) != 0)
        {
        if (lineNum == 10)
            {
            lineNum = 1;
            printf("\n==== reading stdin\tpage %d ====\n", pc++);
            }
        printf("%s", line);
        lineNum++;
        }
    }
else
    {
    while (--argc > 0)
        {
        if ((fp1 = fopen(*++argv, "r")) == NULL)
            {
            printf("%s: can't open %s\n", argv[0], *argv);
            exit(1);
            }
        else
            {
            printf("==== reading %s\tpage %d ====\n", *argv, pc++);
            while((size = getLine(line, MAXSIZE, fp1)) != 0)
                {
                if (lineNum == 10)
                    {
                    lineNum = 1;
                    printf("==== reading %s\tpage %d ====\n", *argv, pc++);
                    }
                printf("%s", line);
                lineNum++;
                }
            fclose(fp1);
            printf("\n");
            lineNum = 1;
            }
        }
    }
}

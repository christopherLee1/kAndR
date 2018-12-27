#include "ch7Code.h"


int main(int argc, char *argv[])
/* wrap lines over 80 chars */
{
char c;
char line[MAXLINEWIDTH+1];
zeroString(line, MAXLINEWIDTH+1);
char *copy = NULL;
int i = 0, j, currLineWidth = 0;

for (i = 0; i < MAXLINEWIDTH; i++)
    printf("*");
printf("\n");

while ((c = getchar()) != EOF)
    {
    if (c == '\n')
        {
        printf("%s\n", line);
        zeroString(line, MAXLINEWIDTH+1);
        currLineWidth = 0;
        }
    else
        {
        if (currLineWidth < MAXLINEWIDTH)
            {
            line[currLineWidth] = c;
            currLineWidth++;
            }
        else
            {
            copy = strdup(line);
            for (i = MAXLINEWIDTH; i >= 0; i--)
                if (isspace(line[i]))
                    break;
            copy[i] = '\0';
            while(isspace(line[i]))
                i++;
            currLineWidth = MAXLINEWIDTH - i;
            char temp[currLineWidth];
            zeroString(temp, currLineWidth);
            for (j = 0; j < currLineWidth; j++, i++)
                {
                temp[j] = line[i];
                }
            zeroString(line, MAXLINEWIDTH+1);
            for (i = 0; i < strlen(temp)-1; i++)
                {
                line[i] = temp[i];
                }
            line[currLineWidth] = c;
            currLineWidth++;
            printf("%s\n", copy);
            }
        }
    }
}

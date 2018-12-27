#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
/* converts stdin to upper case or lower case */
{
char c;
int i;
char *progName;
int lower = FALSE;

// get program name
if ((progName = strrchr(*argv, '/')) != NULL)
    {
    ++progName;
    }
else
    {
    while (!isalpha(progName[0]))
        ++*progName;
    }
if (!isupper(progName[0]))
    lower = TRUE;

while ((c = getchar()) != EOF)
    printf("%c", lower ? tolower(c) : c);
}

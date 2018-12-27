#include "ch7Code.h"

int main(int argc, char *argv[])
/* converts stdin to upper case or lower case */
{
char c;
int lower = FALSE;

char *progName = getProgName(argv[0]);
if (!isupper(progName[0]))
    lower = TRUE;

while ((c = getchar()) != EOF)
    printf("%c", lower ? tolower(c) : c);
}

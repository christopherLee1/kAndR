#include "ch7Code.h"

char *getProgName(char *s)
/* return name of invoked program with trimed off path */
{
char c;
int i;
char *progName;
int lower = FALSE;

// get program name
if ((progName = strrchr(s, '/')) != NULL)
    {
    ++progName;
    }
else
    {
    while (!isalpha(progName[0]))
        ++*progName;
    }
return progName;
}

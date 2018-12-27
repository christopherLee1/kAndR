#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAXCHARSTOREAD 200 // don't read in more than 200 chars at once
#define MAXLINEWIDTH 80 // "pretty print" line size

char *getProgName(char *s);
/* return name of invoked program with trimed off path */

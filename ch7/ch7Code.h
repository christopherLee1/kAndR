#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXCHARSTOREAD 200 // don't read in more than 200 chars at once
#define MAXLINEWIDTH 80 // "pretty print" line size

char *getProgName(char *s);
/* return name of invoked program with trimed off path */

void zeroString(char *s, int len);
/* null all chars of string */

void minprintfrevised(char *fmt, ...);
/* revised minimal printf to handle more printf features */

void minprintf(char *fmt, ...);
/* minimal printf with variable argument list */

void minscanf(char *fmt, ...);
/* minimal scanf with variable argument list */

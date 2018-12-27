#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXLINEWIDTH 80
#define MAXSIZE 100

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

int getLine(char *line, int max, FILE *fp);
/* read in max chars from fp */

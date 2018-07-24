#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key
{
    char *word; // C reserved word
    int count; // number of times word occurs
};


#define NKEYS (sizeof keytab / sizeof keytab[0])

#define BUFSIZE 100


void ungetch(int);
/* push a char back onto input */

int getch(void);
/* get a char of the input */

int binsearch(char *, struct key [], int);
/* binsearch: find word in tab[0] ... tab[n-1] */

int getword(char *, int);
/* getword: get next word or character from input */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key
{
    char *word; // C reserved word
    int count; // number of times word occurs
};

#define TRUE 1
#define FALSE 0

// globals signifying not check for keywords in this line
int inStr; //= FALSE;
int inUnderscore; // = FALSE;
int singleLineComment; // = FALSE;
int multiLineComment; // = FALSE;
int inPreproc; // = FALSE;

#define ALLOWED !(inStr || inUnderscore || singleLineComment || multiLineComment || inPreproc)


#define NKEYS (sizeof keytab / sizeof keytab[0])

#define BUFSIZE 100

int prevChar(char *word, char prev);
/* check if previous character in word is prev */

int startsWith(char *pre, char *word);
/* check if first strlen(pre) chars of word == pre */

int getword2 (char *word, int lim);
/* better getword that ignores preprocessor statements,
comments and _ in var names */

int binsearch(char *, struct key [], int);
/* binsearch: find word in tab[0] ... tab[n-1] */

void ungetch(int);
/* push a char back onto input */

int getch(void);
/* get a char of the input */

int getword(char *, int);
/* getword: get next word or character from input */

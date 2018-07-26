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

// globals for not looking for keywords
int inStr; //= FALSE;
int inUnderscore; // = FALSE;
int singleLineComment; // = FALSE;
int multiLineComment; // = FALSE;
int inPreproc; // = FALSE;

#define ALLOWED !(inStr || inUnderscore || singleLineComment || multiLineComment || inPreproc)


#define NKEYS (sizeof keytab / sizeof keytab[0])

#define BUFSIZE 100

int startsWith(char *pre, char *word);
/* check if first strlen(pre) chars of word == pre */

int checkAllowed(char c, char *word);
/* check if c is ",',_,/, or # 
   used to prevent checking for C keywords in these lines */

int binsearch(char *, struct key [], int);
/* binsearch: find word in tab[0] ... tab[n-1] */

void ungetch(int);
/* push a char back onto input */

int getch(void);
/* get a char of the input */

int getword(char *, int);
/* getword: get next word or character from input */

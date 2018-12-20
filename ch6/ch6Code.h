#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct key
    {
    char *word; // C reserved word
    int count; // number of times word occurs
    };

struct tnode 
    {
    char *word; // pointer to text
    int count; // number of times word has appeared
    struct tnode *left; // left child
    struct tnode *right; // right child
    };

extern struct key keytab[];

#define TRUE 1
#define FALSE 0

#define NKEYS (sizeof keytab / sizeof keytab[0])

#define BUFSIZE 100

struct tnode *talloc();
/* allocate storage for a tnode */

void treeprint(struct tnode *p);
/* print tree structure */

struct tnode *addtree(struct tnode *p, char *word);
/* add a  node with w, at or below p */

int prevChar(char *word, char prev);
/* check if previous character in word is prev */

int startsWith(char *pre, char *word);
/* check if first strlen(pre) chars of word == pre */

int getword2 (char *word, int lim);
/* better getword that ignores preprocessor statements,
comments and _ in var names */

int binsearch(char *, struct key [], int);
/* binsearch: find word in tab[0] ... tab[n-1] */

struct key *binsearch2(char *word, struct key *tab, int n);
/* binsearch2: binsearch but with pointer to struct */

void ungetch(int);
/* push a char back onto input */

int getch(void);
/* get a char of the input */

int getword(char *, int);
/* getword: get next word or character from input */

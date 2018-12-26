#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXCOUNT 100 // number of times a word can appear in a document
#define ALLOCSIZE 100

struct key
    {
    char *word; // C reserved word
    int count; // number of times word occurs
    };

struct tree
    {
    int count; // number of nodes in tree
    struct tnode *root; // root of tree
    };

struct tnode 
    {
    char *word; // pointer to text
    int count; // number of times word has appeared
    struct tnode *left; // left child
    struct tnode *right; // right child
    };

struct tnodeArray
    /* tnode but with an array of ints instead of a count */
    {
    char *word;
    int count; // number of ints in lineArray
    int lineArray[MAXCOUNT]; // line numbers where word appears
    struct tnodeArray *left;
    struct tnodeArray *right;
    };

extern struct key keytab[];
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

#define TRUE 1
#define FALSE 0

#define NKEYS (sizeof keytab / sizeof keytab[0])

#define BUFSIZE 100

struct tnode *talloc();
/* allocate storage for a tnode */

void treeprint(struct tnode *p);
/* print tree structure */

void sortAndPrintTree(struct tnode *tree);
/* make an array of pointers to nodes and then use qsort to sort the array */

struct tree *addNodeToTree(struct tree *p, char *word);
/* add a node with word, at or below p */

struct tnode *addtree(struct tnode *p, char *word);
/* add a  node with w, at or below p */

struct tnode *addtreeInOrder(struct tnode *p);
/* add p to tree in sorted order */

struct tnodeArray *tnodeArrayAlloc();
/* allocate storage for a tnode */

void treeArrayPrint(struct tnodeArray *p);
/* print tree structure */

struct tnodeArray *addTreeArray(struct tnodeArray *p, char *word, int lineNum);
/* add a  node with w, at or below p */

int prevChar(char *word, char prev);
/* check if previous character in word is prev */

int endsWith(char *word, char *suf);
/* check if last strlen(suf) chars of word == suf */

int startsWith(char *pre, char *word);
/* check if first strlen(pre) chars of word == pre */

void afree(char *p);
/* free storage pointed to by p */

char *alloc(int n);
/* return pointer to n characters */

int getLine(char *s, int lim);
/* getLine: read at most lim chars into s */

int readlines(char *lineptr[], int maxlines);
/* readlines: read input lines */

int getword2 (char *word, int lim, int *lineNum);
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

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALLOCSIZE 10000 /* size of available space */

//static char allocbuf[ALLOCSIZE]; /* storage for alloc */
//static char *allocp = allocbuf; /* next free position */

char *alloc(int n); /* return pointer to n characters */

void afree(char *p); /* free storage pointed to by p */

/* strcpyA: copy t to s; array subscript version */
void strcpyA(char *s, char *t);

/* strcpyB: copy t to s; pointer version */
void strcpyB(char *s, char *t);

/* strcpyC: copy t to s, cool version */
void strcpyC(char *s, char *t);

/* strcmpA: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmpA(char *s, char *t);

/* strcmpB: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmpB(char *s, char *t);

/* getint : get next integer from input into *pn */
int getint(int *pn);

#define BUFSIZE 100

//char buf[BUFSIZE]; // buffer for ungetch
//int bufp = 0; // next free position in buf

int getch(void); /* get a (possibly pushed back) character */

#define MAXLEN 1000 /* max length of single line */

/* getLine: read at most lim chars into s */
int getLine(char *s, int lim);

#define MAXLINES 5000

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines);

/* writelines: write output lines to stdout */
void writelines(char *lineptr[], int nlines);

void ungetch(int c); /* push character back on input */

#define SIZE 10

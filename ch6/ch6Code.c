/* Chapter 6: Structures */

#include "ch6Code.h"

//struct point {
//    int x;
//    int y;
//};
//
//struct point pt; // variable which is a structure of type point
//struct point maxpt = { 320, 200 }; // initialize structure

// use '.' operator to access members
//printf("%d, %d", pt.x, pt.y);
//double dist, sqrt(double);
//dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
//struct rect {
//    struct point pt1;
//    struct point pt2;
//};

//struct rect screen;
//screen.pt1.x refers to x coord of pt1 member of screen

// legal operations on structs:
//   copying or assigning to it as a unit
//   take address
//   access members
//
//struct point makepoint (int x, int y)
/* makepoint: make a point from x and y components */
//{
//struct point temp;
//temp.x = x;
//temp.y = y;
//return temp;
//}

//struct rect screen;
//struct point middle;
//screen.pt1 = makepoint(0,0);
//screen.pt2 = makepoint(XMAX, YMAX);
//middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);

//struct point addpoint (struct point p1, struct point p2)
/* addpoint: add two points */
//{
//p1.x += p2.x;
//p1.y += p2.y;
//return p1;
//}

//int ptinrect (struct point p1, struct rect r)
/* ptinrect: return 1 if p in r, 0 if not */
//{
//return (p.x >= r.pt1.x) && (p.x < r.pt2.x) && (p.y >= r.pt1.y) && (p.y < r.pt2.y);
//}

//#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a,b) ((a) > (b) ? (a) : (b))

//struct rect canonrect (struct rect r)
/* canonrect: canonicalize coordinates of rectangle */
//{
//struct rect temp;
//temp.pt1.x = min(r.pt1.x, r.pt2.x);
//temp.pt1.y = min(r.pt1.y, r.pt2.y);
//temp.pt2.x = max(r.pt1.x, r.pt2.x);
//temp.pt2.y = max(r.pt1.y, r.pt2.y);
//return temp;
//}

// pointers to structs
// struct point *pp;  pp is a pointer to a structure of type point
// if pp is a structure, *pp is the structure, (*pp).x and (*pp).y are members
// parens are necessary because *pp.x means *(pp.x) which is illegal because x
//   is not a pointer in this case

//struct point origin, *pp;
//pp = &origin;
//printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);

// -> is shorthand for (*pp).x, for example
//printf("origin is (%d,%d)\n", pp->x, pp->y);

//struct rect r, *rp = &r;
// r.pt1.x && rp->pt1.x && (r.pt1).x && (rp->pt1).x == TRUE

//struct {
//    int len;
//    char *str;
//} *p;

// ++p->len == ++(p->len) and increments len
// (++p)->len increments p before accessing len
// *p->str fetches whatever str points to
// *p->str++ increments str after accessing whatever it points to, just like (*s++)
// (*p->str)++ increments whatever str points to
// *p++->str increments p after accessing whatever str points to

// count C keywords program to illustrate array of structs
//char *keyword[NKEYS];
//int keycount[NKEYS];

// could instead be written as:
//struct key {
//    char *word;
//    int count;
//} keytab[NKEYS];

/*
struct key keytab[] =
{
    {"auto" , 0},    {"break" , 0},   {"case" , 0},    {"char" , 0},
    {"const" , 0},   {"continue" , 0},{"default" , 0}, {"do" , 0},
    {"double" , 0},  {"else" , 0},    {"enum" , 0},    {"extern" , 0},
    {"float" , 0},   {"for" , 0},     {"goto" , 0},    {"if" , 0},
    {"int" , 0},     {"long" , 0},    {"register" , 0},{"return" , 0},
    {"short" , 0},   {"signed" , 0},  {"sizeof" , 0},  {"static" , 0},
    {"struct" , 0},  {"switch" , 0},  {"typedef" , 0}, {"union" , 0},
    {"unsigned" , 0},{"void" , 0},    {"volatile" , 0},{"while" , 0}
};
*/

struct tnode *talloc()
/* allocate storage for a tnode */
{
return (struct tnode *)malloc(sizeof(struct tnode));
}

void treeprint(struct tnode *p)
/* print tree structure */
{
if (p != NULL)
    {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
    }
}

int treeCmp(const struct tnode *a, const struct tnode *b)
/* Comparison function for qsort */
{
return a->count - b->count;
}

void sortAndPrintTree(struct tnode *tree)
/* make an array of pointers to nodes and then use qsort to sort the array */
{
/*
struct tnode *begin = root;
int arrayLen = 0;
for (arrayLen = 0; root != NULL; root = root->left)
    arrayLen++;
*/
}
struct tree *addNodeToTree(struct tree *p, char *word)
/* add a  node with word, at or below p */
{
int cond;
if (p == NULL)
    {
    p->root = talloc();
    p->root->word = strdup(word);
    p->root->count = 1;
    p->root->left = p->root->right = NULL;
    p->count = 1;
    }
else if((cond = strcmp(word, p->root->word)) == 0)
    {
    p->root->count++;
    }
else if (cond < 0)
    p->root->left = addtree(p->root->left, word);
else
    p->root->right = addtree(p->root->right, word);
return p;
}

struct tnode *addtree(struct tnode *p, char *word)
/* add a  node with word, at or below p */
{
int cond;
if (p == NULL)
    {
    p = talloc();
    p->word = strdup(word);
    p->count = 1;
    p->left = p->right = NULL;
    }
else if((cond = strcmp(word, p->word)) == 0)
    {
    p->count++;
    }
else if (cond < 0)
    p->left = addtree(p->left, word);
else
    p->right = addtree(p->right, word);
return p;
}

struct tnodeArray *tnodeArrayAlloc()
/* allocate storage for a tnode */
{
return (struct tnodeArray *)malloc(sizeof(struct tnodeArray));
}

void treeArrayPrint(struct tnodeArray *p)
/* print tree structure */
{
int i;
if (p != NULL)
    {
    treeArrayPrint(p->left);
    printf("%s: ", p->word);
    if (p->count > 1)
        {
        for (i = 0; i < p->count-1; i++)
            printf("%d, ", p->lineArray[i]);
        printf("%d\n", p->lineArray[i]);
        }
    else
        printf("%d\n", p->lineArray[0]);
    treeArrayPrint(p->right);
    }
}

struct tnodeArray *addTreeArray(struct tnodeArray *p, char *word, int lineNum)
/* add a  node with w, at or below p */
{
int cond;
if (p == NULL)
    {
    p = tnodeArrayAlloc();
    p->word = strdup(word);
    p->count = 1;
    p->lineArray[0] = lineNum;
    p->left = p->right = NULL;
    }
else if((cond = strcmp(word, p->word)) == 0)
    {
    p->lineArray[p->count] = lineNum;
    p->count++;
    }
else if (cond < 0)
    p->left = addTreeArray(p->left, word, lineNum);
else
    p->right = addTreeArray(p->right, word, lineNum);
return p;
}

int prevChar(char *word, char prev)
/* check if previous character in word is prev */
{
int len = strlen(word);
return prev == word[len-1];
}

int endsWith(char *word, char *suf)
/* check if last strlen(suf) chars of word == suf */
{
//printf("checking suf=%s against word=%s\n", suf, word);
int len = strlen(suf);
int i;
if (len > strlen(word))
    return FALSE;
for (i = 0; i < len; ++i)
    if (word[strlen(word)-len+i] != suf[i])
        return FALSE;
return TRUE;
}

int startsWith(char *word, char *pre)
/* check if first strlen(pre) chars of word == pre */
{
//printf("checking pre=%s against word=%s\n", pre, word);
int len = strlen(pre);
int i;
if (len > strlen(word))
    return FALSE;
for (i = 0; i < len; ++i)
    {
    if (word[i] != pre[i])
        return FALSE;
    }
return TRUE;
}

void afree(char *p) /* free storage pointed to by p */
{
if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

char *alloc(int n) /* return pointer to n characters */
{
if (allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
{
    allocp += n;
    return allocp - n; /* old p */
} else /* not enough room */
    return 0;
}

int getLine(char *s, int lim)
/* getLine: read at most lim chars into s */
{
int c;
char *p = s; // need this pointer so s still points to the beginning
while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    *p++ = c;
if (c == '\n')
    *p++ = c;
*p = '\0';
return p-s;
}

int readlines(char *lineptr[], int maxlines)
/* readlines: read input lines */
{
    int len, nlines;
    char *p, line[MAXCOUNT];

    nlines = 0;
    while ((len = getLine(line, MAXCOUNT)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    if (p != NULL)
        //printf("freeing p\n");
        afree(p);
    return nlines;
}

int getword2 (char *word, int lim, int *lineNum)
/* better getword: get next word or character from input, and deal with underscores,
   string constants, comments and single line only preprocessor statements */
{
int c;
char *w = word;

while (isspace(c = getch()))
    if (c == '\n')
        {
        *w++ = '\0';
        ++(*lineNum);
        return '\n';
        }
if (c != EOF)
    *w++ = c;
if (c == '"') //jump to end of string
    {
    for (; --lim > 0; w++)
        if ((*w = getch()) == '"')
            {
            w++;
            if ((*w = getch()) == '\n')
                ++(*lineNum);
            *w++ = '\0';
            return word[0];
            }
    }
else if (c == '/') //check for comments
    {
    c = getch();
    if (c == '/')
        {
        *w++ = c;
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\n')
                {
                ++(*lineNum);
                break;
                }
        *w++ = '\0';
        return word[0];
        }
    else if (c == '*')
        {
        *w++ = c;
        for (; --lim > 0; w++)
            {
            if ((*w = getch()) == '\n')
                ++(*lineNum);
            if (*w == '*')
                {
                w++;
                if ((*w = getch()) == '/')
                    break;
                }
            w++;
            if ((*w = getch()) == '\n')
                ++(*lineNum);
            }
        *w++ = '\0';
        return word[0];
        }
    }
else if (c == '#') //jump to end of line
    {
    for (; --lim > 0; w++)
        if ((*w = getch()) == '\n')
            {
            ++(*lineNum);
            break;
            }
    *w++ = '\0';
    return word[0];
    }
else if (c == '*') // pointer
    {
    *w++ = '\0';
    return word[0];
    }
else if (c == '(')
    {
    *w++ = '\0';
    return word[0];
    }
for ( ; --lim > 0; w++)
    {
    if (!isalnum(*w = getch()))
        {
        if (*w == '_')
            continue;
        else if (*w == EOF)
            {
            return EOF;
            }
        else
            {
            ungetch(*w);
            break;
            }
        }
    }
*w = '\0';
return word[0];
}

int binsearch (char *word, struct key tab[], int n)
/* binsearch: find word in tab[0] ... tab[n-1] */
{
int cond;
int low, high, mid;
low = 0;
high = n - 1;
while (low <= high)
    {
    mid = (low + high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0)
        high = mid - 1;
    else if (cond > 0)
        low = mid + 1;
    else
        return mid;
    }
return -1;
}

struct key *binsearch2(char *word, struct key *tab, int n)
/* binsearch2: binsearch but with pointer to struct */
{
int cond;
struct key *low = &tab[0];
struct key *high = &tab[n];
struct key *mid;
while (low < high)
    {
    mid = low + (high - low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0)
        high = mid;
    else if (cond > 0)
        low = mid + 1;
    else
        return mid;
    }
return NULL;
}

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int getch(void) /* get a (possibly pushed back) character */
{
return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
else
    buf[bufp++] = c;
}
int getword (char *word, int lim)
/* getword: get next word or character from input */
{
int c;
char *w = word;

while (isspace(c = getch()))
    ;
if (c != EOF)
    *w++ = c;
if (!isalpha(c))
    {
    *w = '\0';
    return c;
    }
for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch()))
        {
        ungetch(*w);
        break;
        }
*w = '\0';
return word[0];
}

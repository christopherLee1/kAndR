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

// initialize globals for not looking for keywords
int inStr = FALSE;
int inUnderscore = FALSE;
int singleLineComment = FALSE;
int multiLineComment = FALSE;
int inPreproc = FALSE;

int endsWith(char *suf, char *word)
/* check if last strlen(suf) chars of word == pre */
{
int len = strlen(suf);
int i;
if (len > strlen(word))
    return FALSE;
for (i = 0; i < len; ++i)
    if (word[strlen(word)-len+i] != suf[i])
        return FALSE;
return TRUE;
}

int startsWith(char *pre, char *word)
/* check if first strlen(pre) chars of word == pre */
{
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

int checkAllowed(char c, char *word)
/* check if c is ",',_,/, or # 
   used to prevent checking for C keywords in these lines */
{
if (c == '\n')
    {
    inUnderscore = FALSE; //can't have varNames split over two lines
    inPreproc  = FALSE;  //explicitly don't allow split preprocessor lines with '\'
    singleLineComment = FALSE;
    //return ALLOWED;
    }
else if (c == '"' || c == '\'')
    {
    inStr = !inStr; // toggle based on whether we are closing or opening a new string constant
    //printf("inStr = %d because word = (%s)\n", inStr, word);
    }
else if (c == '_')
    {
    inUnderscore = !inUnderscore;
    }
else if (c == '/')
    {
    if (startsWith(word, "//"))
        {
        printf("startswith // true\n");
        singleLineComment = TRUE;
        }
    else if (startsWith(word, "*"))
        multiLineComment = TRUE;
    else if (endsWith(word, "*/"))
        multiLineComment = FALSE;
    //printf("inComment = %d because word = (%s)\n" , inComment, word);
    }
else if (c == '#')
    {
    inPreproc = TRUE;
    }
printf("ALLOWED : inStr = %d, sLComment = %d, mLComment = %d, inUnderscore = %d, inPreproc = %d\n", inStr, singleLineComment, multiLineComment, inUnderscore, inPreproc);
return ALLOWED;
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

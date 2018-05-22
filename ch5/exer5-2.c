#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getfloat : get next float from input into *pn 
        returns an int for end of file but puts float into pn*/
int getfloat(float *pn)
{
int c, sign;
float val = 0.0, power = 0.0;
while (isspace(c=getch())) /* skip white space */
    ;
if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
    ungetch(c);
    return 0;
    }
sign = (c == '-') ? -1 : 1;
if (c == '+' || c == '-' )
{
    c = getch();
    if (!isdigit(c))
    {
        ungetch(getfloat(pn));
        return 0;
    }
}
for (val = 0.0; isdigit(c); c = getch())
    val = 10.0 * val + (c - '0');
if (c == '.')
    c = getch();
for (power = 1.0; isdigit(c); c = getch())
{
    val = 10.0 * val + (c - '0');
    power *= 10.0;
}
*pn = sign * val / power;
if (c != EOF)
    ungetch(c);
return c;
}

#define BUFSIZE 100

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

#define SIZE 10

int main()
{
int n;
float array[SIZE];//, getint(int *);
for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;
printf("array: ");
for (n = 0; n < SIZE; n++)
    printf("%.3g ", array[n]);
printf("\n");
}

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void print(void);
void swap(void);
void duplicate(void);
void clear(void);
void printAll(void);

/* reverse Polish calculator */
int main()
{
    int type, i;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop() , op2));
                else
                    printf("error: modulo 0\n");
                break;
            case '^':
                push(pow(pop(), pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case '@':
                push(sin(pop()));
                break;
            case 'p': //print top of stack without popping
                print();
                break;
            case's': // swap top two elems
                swap();
                break;
            case 'd': // duplicate top elem and add it back
                duplicate();
                break;
            case 'c': // clear the stack
                clear();
                break;
            case 'a': // print the whole stack
                printAll();
                break;
            case '\n':
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* max of depth of val stack */

int sp = 0;
double elem1, elem2;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* print: print top item without removing it */
void print(void)
{
    elem1 = pop();
    printf("\t%.8g\n", elem1);
    push(elem1);
}

/* swap top two elems of stack */
void swap(void)
{
    elem1 = pop();
    elem2 = pop();
    push(elem1);
    push(elem2);
}

/* duplicate: add top of stack to top of stack */
void duplicate(void)
{
    elem1 = pop();
    push(elem1);
    push(elem1);
}

/* clear: clear stack */
void clear(void)
{
    sp = 0;
}

/* printAll: print each item in stack space separated */
void printAll(void)
{
    int i;
    for (i = 0; i < sp; i++)
        printf("%.8g ", val[i]);
    printf("\n");
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number
    i = 0;
    if (isdigit(c)) // get integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // get fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '-') {// negative number
        s[i] = c;
        if ((c = getch()) == ' ' || c == '\t' || c == '\n')
            return '-';
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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

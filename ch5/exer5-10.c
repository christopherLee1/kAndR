#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXLEN 16

int stack[MAXLEN];
int stackp = 0;

/* grab the latest value pushed onto the stack */
int pop()
{
if (stackp < 1)
    {
    printf("popping from an empty stack\n");
    }
return stack[--stackp];
}

/* push new value onto stack array */
void push(int x)
{
if (stackp + 1 > MAXLEN)
    {
    printf("pushing too many arguments\n");
    }
stack[stackp++] = x;
}

/* transforms string into integer representation */
int toint(char *c)
{
int i, ret = 0;
for (i = strlen(c)-1; i >= 0; i--)
    {
    if (c[i] == '-')
        ret *= -1;
    if (c[i] == '+')
        continue;
    if (c[i] <= '0' && c[i] >= '9')
        {
        printf("illegal character: %c in expression\n", c[i]);
        }
    else
        {
        printf("10 * %d = %d, c[%d] - '0' = %d\n", i, 10 * i, i, c[i] - '0');
        ret += (10 * i) + (c[i] - '0');
        }
    }
printf("returning %d\n", ret);
return ret;    
}

int main(int argc, char **argv)
{
int left, right;
int x, temp;
char *c;
while (--argc > 0)
    {
    c = *(++argv);
    if (strcmp(c,"+") == 0)
        {
        if (strlen(c) > 1)
            push(toint(c));
        else
            {
            right = pop();
            left = pop();
            push(left + right);
            }
        }
    else if (strcmp(c,"-") == 0)
        {
        if (strlen(c) > 1)
            push(toint(c));
        else
            {
            right = pop();
            left = pop();
            push(left - right);
            }
        }
    else if(strcmp(c,"*") == 0)
        {
        right = pop();
        left = pop();
        push(left * right);
        }
    else if (strcmp(c,"/") == 0)
        {
        right = pop();
        left = pop();
        if (right == 0)
            {
            printf("division by 0 error\n");
            }
        push(left / right);
        }
    else
        {
        push(toint(c));
        }
    }
temp = pop();
printf("final result = %d\n", temp);
} //main

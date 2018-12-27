/*
Calculator from chapter 4 rewritten with scanf:

#include <stdio.h>
main()
{
double sum, v;
sum = 0;
while (scanf("%lf", &v) == 1)
    printf("\t%.2f\n", sum+= v);
return 0
}

read a datestring with scanf:
int day, month, year;
scanf("%d/%d/%d", &month, &day, &year); // 11/27/1909
*/
#include "ch7Code.h"

char *getProgName(char *s)
/* return name of invoked program with trimed off path */
{
char c;
int i;
char *progName;
int lower = FALSE;

// get program name
if ((progName = strrchr(s, '/')) != NULL)
    {
    ++progName;
    }
else
    {
    while (!isalpha(progName[0]))
        ++*progName;
    }
return progName;
}

void zeroString(char *s, int len)
/* null all chars of string */
{
memset(s, 0, len);
}

void minprintfrevised(char *fmt, ...)
/* revised minimal printf to handle more printf features */
{
va_list ap; // points to unnamed arg in turn
char *p, *sval;
int ival;
double dval;
int hval;
int precision = 0;
char temp[5]; // no more than 5 digit length precision
int tempPtr = 0; // current position in temp
zeroString(temp, 5);

va_start(ap, fmt); // make ap point to first unnamed arg
for (p = fmt; *p; p++)
    {
    if (*p != '%')
        {
        putchar(*p);
        continue;
        }
    else
        {
        while (*++p)
            {
            if (*p == 'd')
                {
                char *toPrint = (char *)malloc(sizeof(char) * 15);;
                ival = va_arg(ap, int);
                precision = atoi(temp);
                if (precision > 0)
                    {
                    sprintf(toPrint, "%%%dd", precision);
                    printf(toPrint, ival);
                    }
                else
                    printf("%d", ival);
                zeroString(temp, 5);
                tempPtr = 0;
                break;
                }
            else if (*p == 'f')
                {
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
                }
            else if (*p == 's')
                {
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
                }
            else if (*p == 'x')
                {
                hval = va_arg(ap, int);
                printf("%x", hval);
                break;
                }
            else
                {
                temp[tempPtr] = *p;
                tempPtr++;
                }
            }
        }
    }
va_end(ap); // clean up when done
}

void minprintf(char *fmt, ...)
/* minimal printf with variable argument list */
{
va_list ap; // points to unnamed arg in turn
char *p, *sval;
int ival;
double dval;

va_start(ap, fmt); // make ap point to first unnamed arg
for (p = fmt; *p; p++)
    {
    if (*p != '%')
        {
        putchar(*p);
        continue;
        }
    switch(*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
va_end(ap); // clean up when done
}

void minscanf(char *fmt, ...)
/* minimal scanf with variable argument list */
{
va_list ap; // points to unnamed arg in turn
char *p, *sval;
int c;
int *ival;
double *dval;

va_start(ap, fmt); // make ap point to first unnamed arg
for (p = fmt; *p; p++)
    {
    if (*p != '%')
        {
        //getchar();
        continue;
        }
    switch(*++p)
        {
        case 'd':
            ival = va_arg(ap, int *);
            scanf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double *);
            scanf("%f", dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            scanf("%s", sval);
            break;
        default:
            getchar();
            break;
        }
    }
va_end(ap); // clean up when done
}

int getLine(char *line, int max, FILE *fp)
/* read in max chars from fp */
{
if (fgets(line, max, fp) == NULL)
    return 0;
else
    return strlen(line);
}

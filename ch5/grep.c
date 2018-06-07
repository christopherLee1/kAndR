#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/* getLine: read at most lim chars into s */
int getLine(char *s, int lim)
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

/* grep: print lines that match pattern from 1st arg
    invert -n for line number of match and
            -v for inversion of match */
int main(int argc, char *argv[])
{
char line[MAXLINE];
long lineno = 0;
int c, invert = 0, number = 0, found = 0;

while (--argc > 0 && (*++argv)[0] == '-') {
    while ((c = *++argv[0])) {
        switch(c) {
            case 'v':
                invert = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("grep: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
        }
    }
}
if (argc != 1) {
    printf("Usage: ./grep -n -v pattern\n");
} else {
    while (getLine(line, MAXLINE) > 0) {
        lineno++;
        if ((strstr(line, *argv) != NULL) != invert) {
            if (number)
                printf("%ld:", lineno);
            printf("%s", line );
            found++;
        }
    }
}
return found;
}

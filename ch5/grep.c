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

/* grep: print lines taht match pattern from 1st arg */
int main(int argc, char *argv[])
{
char line[MAXLINE];
int found = 0;
if (argc != 2)
    printf("Usage: ./grep pattern\n");
else {
    while (getLine(line, MAXLINE) > 0)
        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line ); // prints found line as it's found, doesn't wait for all input
            found++;
        }
}
return found;
}

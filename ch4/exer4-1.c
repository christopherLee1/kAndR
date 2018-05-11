#include <stdio.h>
#define MAXLINE 1000 /* maximum input length */

int getLine(char line[], int max);
int strindex2(char source[], char searchFor[]);

char pattern[] = "ould"; /* patter to search for */

/* find all lines matching patter */
int main()
{
    char line[MAXLINE];
    int found = 0;

    while (getLine(line, MAXLINE) > 0)
        if (strindex2(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

/* getLine: get line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex2: return rightmost index of t in s, -1 if none */
int strindex2(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            printf("found %s at position %d\n", pattern, i);
            return i;
    }
    return -1;
}

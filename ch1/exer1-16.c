#include <stdio.h>
#define MAXLINE 1000

/* Print longest line, version 2 */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("longest length: %d, line: %s", max, longest);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. */

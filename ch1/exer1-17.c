#include <stdio.h>
#define MAXLINE 1000
#define CUTOFF 80

/* Print lines longer than 80 chars. */
/* test line: this line is longer than 80 characters. padding padding padding padding. */

int getLine(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > CUTOFF) {
            //max = len;
            printf("over 80 characters: %s", line);
        }
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

/* this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. this is a very long line of text for testing this program. */

#include <stdio.h>
#define MAXLINE 1000
#define CUTOFF 80

/* Remove trailing blanks and tabs, delete empty lines. */
/* test line: this line is longer than 80 characters. padding padding padding padding. */

//void copy(char to[], char from[]);
int reverse(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    // 'line' is an array that gets modified by getline, so the '\0' is important
    // to add at the end of the array as I have painfully found out.
    while ((len = reverse(line, MAXLINE)) >= 0)
        printf("%s", line);
    return 0;
}

/* getline: read a line into s, return length. */
int reverse(char s[], int lim)
{
    int c, i, j;
    char rev[MAXLINE];
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        rev[i] = c;
    if (c == '\n') {
        //--i;
        //printf("i = %d\n", i);
        //printf("%s\n", rev);
        for (j = 0; j < i; ++j)
            //printf("rev[i-j-1=%d] = %c\n", i-j-1, rev[i-j-1]);
            s[j] = rev[i-j-1];
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

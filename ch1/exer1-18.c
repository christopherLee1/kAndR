#include <stdio.h>
#define MAXLINE 1000
#define CUTOFF 80

/* Remove trailing blanks and tabs, delete empty lines. */
/* test line: this line is longer than 80 characters. padding padding padding padding. */

//void copy(char to[], char from[]);
int getLine(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    // 'line' is an array that gets modified by getline, so the '\0' is important
    // to add at the end of the array as I have painfully found out.
    while ((len = getLine(line, MAXLINE)) >= 0)
        if (len > 0)
            printf("%s\n", line);
    return 0;
}

/* getline: read a line into s, remove trailing whitespace. If blank line return 0. */
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\0';
        if (i > 1) { // just return single character lines
            --i;
            // work backwards and strip trailing whitespace
            for (; i >= 0 && (s[i] == '\t' || s[i] == ' '); --i)
                s[i] = '\0';
        }
    }
    return i;
}

// this line has blanks at the end                    
// this line has tabs at the end 		

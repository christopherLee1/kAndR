#include <stdio.h>

// tab is 4 chars for purpose of this program
#define TABSTOP 4

/* detab: replace '\t' with 4 blanks */

int main()
{
    int i, c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < TABSTOP; ++i)
                printf(" ");
        } else
            printf("%c", c);
    }
    return 0;
}

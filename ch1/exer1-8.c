#include <stdio.h>

/* count blanks, tabs and newlines */

int main()
{
    int c, blanks;
    blanks = 0;
    while((c = getchar()) != EOF)
        if (c == '\n' || c == ' ' || c == '\t')
            ++blanks;
    printf("whitespace chars: %d\n", blanks);
}

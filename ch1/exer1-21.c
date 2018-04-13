#include <stdio.h>

// tab is 4 chars for purpose of this program
#define TABSTOP 4

/* entab: replace blanks with minimum number of tabs and spaces needed */

int main()
{
    int i, c, spaces;

    spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces++;
            if (spaces >= TABSTOP) {
                spaces = 0;
                printf("\t");
            }
        } else {
            if (spaces > 0) {
                for (i = 0; i < spaces; ++i)
                    printf(" ");
            }
            spaces = 0;
            printf("%c", c);
        }
    }
    return 0;
}

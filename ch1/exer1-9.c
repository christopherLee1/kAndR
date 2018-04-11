#include <stdio.h>

/* replace multiple blanks with single blank*/

int main()
{
    int c;
    int blanks = 0;
    while((c = getchar()) != EOF)
        if (c != ' ') {
            putchar(c);
            blanks = 0;
        } else {
            if (blanks == 0)
                putchar(c);
                ++blanks;
        }
}

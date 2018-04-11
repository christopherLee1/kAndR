#include <stdio.h>

/* replace tabs and backspace with \t and \b literals */

int main()
{
    int c;
    int blanks = 0;
    while((c = getchar()) != EOF)
        if (c != '\t' &&  c != '\b' && c != '\\') {
            putchar(c);
        } else if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\");
        }
}

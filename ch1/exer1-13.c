#include <stdio.h>

#define MAX 12

/* histogram of word lengths */

int main()
{
    int c, i, j, nc;
    int ndigit[MAX];
    nc = 0;
    for (i = 0; i < MAX; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) 
        if (c == ' ' || c == '\n' || c == '\t') {
            if (nc < MAX-1) {
                ++ndigit[nc-1];
            } else {
                ++ndigit[MAX-1];
            }
            nc = 0;
        } else {
            ++nc;
        }

    for (i = 0; i < MAX; ++i) {
        printf("%d: ", i+1);
        for (j = 0; j < ndigit[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

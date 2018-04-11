#include <stdio.h>

#define MAX 'z'-'0'

/* histogram of character frequencies, only counts 
   ASCII between '0' and 'z' (48 - 122)*/

int main()
{
    int c, i, j;
    int ndigit[MAX];

    for (i = 0; i < MAX; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) 
        if (c != ' ' || c != '\n' || c != '\t')
            ++ndigit[c-'0'];

    for (i = 0; i < MAX; ++i) {
        printf("%c: ", '0'+i);
        for (j = 0; j < ndigit[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

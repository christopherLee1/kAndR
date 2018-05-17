#include <stdio.h>
#include <string.h>

/* printd: print n in decimal */
void printd (int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

/* itoaR: convert int to string recursively */
void itoaR (int n, char s[])
{
    static int i = 0;
    if (n < 0) {
        s[0] = ('-');
        ++i;
        n = -n;
    }
    if (n / 10) {
        itoaR(n / 10, s);
        ++i;
    }
    s[i] = (n % 10 + '0');
    if (s[strlen(s)] != '\0')
        s[strlen(s)] = '\0';
}

/* reverse: reverse string s in place */
void reverse (char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    int i = -400;
    char s[] = "4004";
    printf("strlen(s) = %lu\n", strlen(s));
    itoaR(i,s);
    printf("itoaR(%d): %s\n", i,s); 
}

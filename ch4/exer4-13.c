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

void reverse(char []);

/* itoa: convert n to characters in s */
void itoa (int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) // record sign
        n = -n; // make n positive
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place recursively*/
void reverseR (char s[])
{
    static int i = 0;
    int j = strlen(s) - 1;
    char c = s[0];
    if (j - i >= 0) {
        c = s[i++];
        reverseR(s);
    }
    if (j-i >= 0) {
        s[j-i] = c;
    }
    --i;
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
    char s[] = "test";
    //char s1[] = "43104";
    reverseR(s);
    printf("reverseR(12345): %s\n", s); 
}

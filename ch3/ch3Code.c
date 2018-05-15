#include <stdio.h>

/* ambiguous if statements */
if (n >= 0)
    for (i = 0; i < n; i++)
        if (s[i] > 0) {
            printf("..");
            return i;
        }
else /* wrong, this else will be evaluated in the for loop */
    printf("error -- n is negative\n");

/* binsearch: find x in v[0]..v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1; /* no match */
}

#include <ctype.h>

/* atoi: convert s to integer; version 2 */
int atoi (char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++) //skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') //skip sign
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* shellsort: sort v[0]..v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

#include <string.h>
/* reverse: reverse string s in place */
void reverse (char s[])
{
    int c, i, j;
    for (i = 0; j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

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

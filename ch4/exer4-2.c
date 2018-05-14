#include <ctype.h>
#include <stdio.h>

double atoF(char s[]);

/* atoF: convert string s to double, allow input like 1.25e-6, with one exponent */
double atoF(char s[])
{
    double val, power;
    int i, j, sign;
    int expSign = -1;
    int exp;
    
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    j = 0;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        j++;
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        expSign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        exp = s[i] - '0';
        if (expSign == -1) {
            exp += j;
            j = 0;
        }
        power = 1.0;
        for (; j < exp; j++) {
            if (expSign == -1) {
                power *= 10.0;
            } else
                power /= 10.0;
        }
    }
    return sign * val / power;
}

int main()
{
    char s1[] = "3.25";
    char s2[] = "-400.1";
    char s3[] = "500.90";
    char s4[] = "1.25e3";
    printf("%6.4f\n", atoF(s1) + atoF(s2) + atoF(s3) + atoF(s4));
}

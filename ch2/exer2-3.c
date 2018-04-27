#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* htoi - convert hexadecimal string into integer value. */

#define MAXSIZE 8 // maximum length of hex string

int getLine(char input[], int maxsize);
int htoi(char input[], int length, int result);

int main()
{
    int result; //resulting converted number
    int len;  // length of input string
    char input[MAXSIZE]; // current input string
    
    len = 0;
    result = 0;

    while ((len = getLine(input, MAXSIZE)) > 0) {
        if (len <= MAXSIZE) {
            printf("%s == %u\n", input, htoi(input, len, MAXSIZE));
            break;
        } else {
            printf("input string %s too large\n", input);
            break;
        }
    }
}

int getLine(char input[], int maxsize)
{
    int c, i;
    for (i = 0; i < maxsize - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        if (isalnum(c))
            input[i] = c;
    }
    input[i] = '\0';
    return i;
}

int htoi(char input[], int length, int result)
/* assume input contains something like 0x1111111 */
{
    int i, j, digit, value;
    result = 0;
    //printf("htoi length = %d\n", length);
    for (i = length - 1; i < MAXSIZE; --i) {
        value = 0;
        if (i < 2 && (input[0] == '0' && (input[1] == 'x' || input[1] == 'X'))) // skip optional prefix
            continue; 
        if (isdigit(input[i])) {
            digit = input[i] - '0';
            value = pow(16, length - i - 1);
            result += (value * digit);
            //printf("digit = %d, value = %d, result = %d, i = %d\n", digit, value, result, i);
        }
        if (isalpha(input[i])) {
            digit = tolower(10 + input[i]) - 'a';
            value = pow(16, length - i - 1);
            result += (value * digit);
            //printf("digit = %d, value = %d, result = %d, i = %d\n", digit, value, result, i);
        }
    }
    return result;
}

#include <stdio.h>
#include <ctypes.h>

/* htoi - convert hexadecimal string into integer value. */

#define MAXSIZE 18 // maximum length of hex string

int getLine(char input[], int maxsize);
int htoi(char input[], int result);

int main()
{
    int result; //resulting converted number
    int len;  // length of input string
    char input[MAXSIZE]; // current input string
    
    len = 0;
    result = 0;

    while ((len = getline(input, MAXSIZE)) > 0) {
        if (len <= MAXSIZE) {
            printf("%s == %u\n", input, htoi(input, MAXSIZE));
        } else {
            printf("input string %s too large\n");

int getLine(char input[], int maxsize)
{
    int c, i;
    for (i = 0; i < lim -1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        if (isalnum(c))
            input[i] = c;
    }
    input[i] = '\0';
    return i;
}

int htoi(char input[], int result)
/* assume input contains something 0x1111111 */
{
    int i;
    for (i = 0; i < MAXSIZE; ++i) {
        if (i < 2 && input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) // skip optional prefix
            continue; 
        if (isdigit(input[i]))
            result += input[i] - '0';
        if (isalpha(input[i]))
            result += tolower(input[i]) - 'a';
    return result;
}

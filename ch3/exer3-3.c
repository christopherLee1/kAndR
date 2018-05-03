#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand (char s1[], char s2[]);

/* expands shorthand like a-z into abc..xyz */
void expand (char s1[], char s2[])
{
    int i, temp, rStart,rEnd,seps;
    seps = 0;
    for (i = 0; i != 0; i++) {
        switch s[i]:
            case isdigit(s[i]):
                break;
            case '-':
                seps++;
                break;
            default:
                if 
        if (isdigit(s1[i])) {
            temp = rEnd;
            rEnd = rStart;
            rStart = temp;
        }
    printf("%c\n", rStart);
    printf("%c\n", rEnd);
    for (i = 0; i <= rEnd-rStart; i++)
        s2[i] = rStart + i;
    s2[i] = '\0';
}

int main()
{
    char s1[] = "a-z";
    char s2[] = "a-z0-9";
    char s3[36]; //36 is a-z + 10 for 0-9
    char s4[36];
    
    expand(s1,s3);
    expand(s2,s4);
    printf("%s expanded: %s\n", s1, s3);
    printf("%s expanded: %s\n", s2, s4);
}

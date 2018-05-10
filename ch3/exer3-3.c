#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand (char s1[], char s2[]);

/* expands shorthand like a-z into abc..xyz */
void expand (char s1[], char s2[])
{
    int i, j, temp, rStart, rEnd, seps, len;
    rStart = rEnd = -1;
    seps = len = 0;
    for (i = 0,j = 0; s1[i] != '\0'; i++) {
        //printf("s1[%d] = %c\n", i, s1[i]);
        if (s1[i] == '-')
            continue;
        else if (rStart == -1) {
            //printf("setting rStart to %c\n", s1[i]);
            rStart = s1[i];
        } else if (rEnd == -1 && s1[i+1] != '-') {
            //printf("setting rEnd to %c\n", s1[i]);
            rEnd = s1[i];
        }
        if ((rStart > -1) && (rEnd > -1)) {
            //printf("%c\n", rStart);
            //printf("%c\n", rEnd);
            for (j = 0; j <= rEnd-rStart; j++) {
                s2[len] = rStart + j;
                ++len;
            }
            //printf("j = %d\n", j);
            //printf("s2: %s\n", s2);
            rStart = rEnd = -1;
        }
    }
    s2[len] = '\0';
}

int main()
{
    char s1[] = "a-z";
    char s2[] = "a-z0-9";
    char s3[] = "a-b-c0-9";
    char s4[36]; //36 is a-z + 10 for 0-9
    char s5[36];
    char s6[36];
    char s7[] = "1-5a-b-c0-9";
    char s8[36]; //36 is a-z + 10 for 0-9
    char s9[] = "A-Ca-r0-9";
    char s10[64]; //36 is A-Za-z + 10 for 0-9
    
    expand(s1,s4);
    expand(s2,s5);
    expand(s3,s6);
    expand(s7,s8);
    expand(s9,s10);
    printf("%s expanded: %s\n", s1, s4);
    printf("%s expanded: %s\n", s2, s5);
    printf("%s expanded: %s\n", s3, s6);
    printf("%s expanded: %s\n", s7, s8);
    printf("%s expanded: %s\n", s9, s10);
}

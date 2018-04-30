#include <stdio.h>

int any(char s1[], char s2[]);

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i)
        for (j = 0; s2[j] != '\0'; ++j) {
            //printf ("s1[%d] = %c, s2[%d] = %c\n",i,s1[i], j, s2[j]);
            if (s1[i] == s2[j])
                return i;
        }
    return -1;
}

int main()
{
    char s1[] = "abcd";
    char s2[] = "xyz";
    char s3[] = "abcd";
    char s4[] = "babb";
    char s5[] = "babb";
    char s6[] = "acbb";
    char s7[] = "efcb";
    char s8[] = "adcb";
    printf("any(%s, %s) = %d\n", s1, s2, any(s1, s2)); // -1
    printf("any(%s, %s) = %d\n", s3, s4, any(s3, s4)); // 0
    printf("any(%s, %s) = %d\n", s5, s6, any(s5, s6)); // 0
    printf("any(%s, %s) = %d\n", s7, s8, any(s7, s8)); // 2
}

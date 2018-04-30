#include <stdio.h>

void squeeze(char s[], int c);
void squeezeAlt(char s1[], char s2[]);

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i,j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* squeezeAlt: delete all chars in s1 that match any chars in s2 */
void squeezeAlt(char s1[], char s2[])
{
    int i,j,k;
    for (i = 0; s2[i] != '\0'; ++i)
        for (j = k = 0; s1[k] != '\0'; ++j)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
    s1[j] = '\0';
}

int main()
{
    char s1[] = "abcd";
    char s2[] = "babb";
    char c = 'a';

    printf("s1 start = %s\n", s1);
    printf("s2 start = %s\n", s2);
    squeeze(s1, c);
    printf("s1 after squeeze = %s\n", s1);


    char s3[] = "abcd";
    squeezeAlt(s3, s2);
    printf("s3 after squeezeAlt = %s\n", s3);

    char s4[] = "cd";
    squeezeAlt(s2, s4);
    printf("s2 after squeezeAlt = %s\n", s2);

    char s5[] = "acd";
    squeezeAlt(s2, s5);
    printf("s2 after squeezeAlt = %s\n", s2);
}

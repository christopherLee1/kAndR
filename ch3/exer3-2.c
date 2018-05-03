#include <stdio.h>
#include <string.h>

#define SIZE 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

void escape(char s[], char t[])
{
    //char c;
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++, j++){
        switch (t[i]) {
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            default:
                s[j] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; j++, i++){
        switch (t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'n':
                        s[j++] = '\n';
                        break;
                    default:
                        break;
                }
            default:
                s[j] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

int main()
{
    char original1[] = "a\nb";
    char converted1[strlen(original1)];
    escape(converted1, original1);
    printf("escape(converted, original):\norig: %s\nconverted: %s\n", original1,  converted1);

    char original2[] = "a\nb";
    char originalCopy[] = "a\\nb";
    char converted2[strlen(original2)];
    unescape(converted2, original2);
    printf("unescaped(original, converted):\norig: %s\nconverted: %s\n", originalCopy, converted2);
}

#include "ch6Code.h"

int getword2 (char *word, int lim)
/* better getword: get next word or character from input, and deal with underscores,
   string constants, comments and preprocessor lines */
{
int c;
char *w = word;

while (isspace(c = getch()))
    ;
if (c != EOF)
    *w++ = c;
if (!isalpha(c))
    {
    *w = '\0';
    return c;
    }
for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch()))
        {
        ungetch(*w);
        break;
        }
*w = '\0';
return word[0];
}

int main()
{
int n;
char word[MAXWORD];
while (getword2(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
        if ((n = binsearch(word, keytab, NKEYS)) >= 0)
            keytab[n].count++;
for (n = 0; n < NKEYS; n++)
    if (keytab[n].count > 0)
        printf("%4d %s\n", keytab[n].count, keytab[n].word);
return 0;
}

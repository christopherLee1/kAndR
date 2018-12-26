#include "ch6Code.h"

struct key keytab[] =
    {
    "auto" , 0,    "break" , 0,   "case" , 0,    "char" , 0,
    "const" , 0,   "continue" , 0,"default" , 0, "do" , 0,
    "double" , 0,  "else" , 0,    "enum" , 0,    "extern" , 0,
    "float" , 0,   "for" , 0,     "goto" , 0,    "if" , 0,
    "int" , 0,     "long" , 0,    "register" , 0,"return" , 0,
    "short" , 0,   "signed" , 0,  "sizeof" , 0,  "static" , 0,
    "struct" , 0,  "switch" , 0,  "typedef" , 0, "union" , 0,
    "unsigned" , 0,"void" , 0,    "volatile" , 0,"while" , 0
    };

int main()
{
struct key *p;
char word[MAXWORD];
int sum = 0;
int lineNum = 0;

while (getword2(word, MAXWORD, &lineNum) != EOF)
    {
    if (isalpha(word[0]))
        {
        if ((p = binsearch2(word, keytab, NKEYS)) != NULL)
            {
            p->count++;
            }
        }
    }
for (p = keytab; p < keytab + NKEYS; p++)
    if (p->count > 0)
        {
        printf("%4d %s\n", p->count, p->word);
        }
return 0;
}

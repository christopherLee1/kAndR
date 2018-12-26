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

int main(int argc, char *argv[])
/* sort variable names that share the first 6 letters */
{
struct tnode *root;
char word[MAXWORD];
char param[MAXWORD];
//char buf[];
struct key *p;
int nameSize = 6;
int i;
int lineNum = 0;
root = NULL;

if (argc > 1 && (*++argv)[0] == '-')
    {
    for (i = 1; i < strlen(argv[0]); i++)
        param[i-1] = argv[0][i];
    param[i] = '\0';
    nameSize = atoi(param);
    }
char buf[nameSize+1];

while (getword2(word, MAXWORD, &lineNum) != EOF)
    {
    if (isalpha(word[0]))
        if ((p = binsearch2(word, keytab, NKEYS)) == NULL)
            {
            if (strlen(word) > nameSize)
                {
                strncpy(buf, word, nameSize);
                buf[nameSize] = '\0';
                root = addtree(root, buf);
                }
            else
                root = addtree(root, word);
            }
    }
treeprint(root);
}

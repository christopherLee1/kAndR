#include "ch6Code.h"

struct key keytab[] = 
    {
    "the", 0, "and", 0, "but", 0
    };

int main(int argc, char *argv[])
/* sort variable names that share the first 6 letters */
{
struct tnodeArray *root;
int lineNum = 1;
char word[MAXWORD];
char param[MAXWORD];
struct key *p;
int i;
int c;
root = NULL;

while ((c = getword2(word, MAXWORD, &lineNum)) != EOF)
    {
    if (isalpha(word[0]))
        {
        root = addTreeArray(root, word, lineNum);
        }
    }
treeArrayPrint(root);
}

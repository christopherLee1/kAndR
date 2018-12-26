#include "ch6Code.h"

int main()
{
struct tnode *root;
char word[MAXWORD];
int lineNum = 0;
root = NULL;
while (getword2(word, MAXWORD, &lineNum) != EOF)
    {
    if (isalpha(word[0]))
        root = addtree(root, word);
    }
treeprint(root);
return 0;
}

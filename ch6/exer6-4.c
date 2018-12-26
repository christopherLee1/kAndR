#include "ch6Code.h"

struct key keytab[] = 
    {
    "the", 0, "and", 0, "but", 0
    };

int main(int argc, char *argv[])
/* print distinct words sorted by frequency of occurence */
{
struct tnode *tree;
int nodeCount = 0;
int lineNum = 1;
char word[MAXWORD];
char param[MAXWORD];
struct key *p;
int i;
int c;
tree = NULL;

while ((c = getword2(word, MAXWORD, &lineNum)) != EOF)
    {
    if (isalpha(word[0]))
        {
        tree = addtree(tree, word);
        }
    }
//treeprint(tree);
sortAndPrintTree(tree);
}

#include "ch6Code.h"

int main(int argc, char *argv[])
/* make a hash out of #define name val pairs. Only worry about
first two words after the #define */
{
char line[MAXWORD];
char *nameValArray[2];
int startingLen = strlen("#define"); // 7
int i, start = 0;
char *name;
char *val;
while (getLine(line, MAXWORD) != EOF)
    {
    if (startsWith(line, "#define"))
        {
        start = startingLen;
        while (isspace(line[start]))
            start++;
        int size = strlen(line) - start + 1;
        char tmpStr[size];
        for (i = 0; i < size, start < strlen(line); i++, start++)
            tmpStr[i] = line[start];
        tmpStr[i] = '\0';
        splitStringBySpaces(tmpStr, nameValArray, 2);
        name = nameValArray[0];
        val = nameValArray[1];
        install(name, val);
        }
    }
printHash();
}

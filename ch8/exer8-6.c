#include "ch8Code.h"
#include <stdio.h>

int main(int argc, char *argv[])
/*  test of _calloc */
{
int i;
char **nameArray = _calloc(5, sizeof(char) * 6); // 5 array elements that can hold "chris" plus null
for (i = 0; i < 5; i++)
    nameArray[i] = "chris";
for (i = 0; i < 5; i++)
    printf("nameArray[%d] = %s\n", i, nameArray[i]);
_free(&nameArray);
}

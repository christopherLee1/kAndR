#include "ch7Code.h"

int main(int argc, char *argv[])
/* test of minscanf */
{
int scan1;
int scan2;
char scan3[10];
char scan4[10];
zeroString(scan3, 10);
zeroString(scan4, 10);
scanf("%d\n", &scan1);
printf("%d\n", scan1);
minscanf("%d\n", &scan2);
printf("%d\n", scan2);
scanf("%s\n", scan3);
printf("%s\n", scan3);
minscanf("%s\n", scan4);
printf("%s\n", scan4);
}

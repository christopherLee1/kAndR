#include <stdio.h>

void echo(int, char *[]);

/* echo: print command line arguments to stdout */
int main(int argc, char *argv[])
{
int i;
for (i = 1; i < argc; i++) {
    printf("%s%s", argv[i], (i < argc-1) ? " " : "");
}
printf("\n");
echo(argc, argv);
return 0;
}

/* echo with pointer arithmetic */
void echo(int argc, char *argv[])
{
while (--argc > 0) {
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
}
printf("\n");
}

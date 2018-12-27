#include "ch7Code.h"

int main(int argc, char *argv[])
/* test of minprintfrevised */
{
minprintf("minprintf(\"%%d\\n\", 100): %d\n", 100);
printf("minprintfrevised(\"%%d\\n\", 100): ");
minprintfrevised("%d\n", 100);
printf("printf(\"%%5d\\n\", 100): %5d\n", 100);
printf("minprintfrevised(\"%%5d\\n\", 100): ");
minprintfrevised("%5d\n", 100);
}

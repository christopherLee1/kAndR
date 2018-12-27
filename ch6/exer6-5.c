#include "ch6Code.h"

int main()
/* test of adding and removing values from hash table */
{
install("test", "string");
install("chris", "lee");
install("chris", "matt");
install("table", "chair");
printf("initial hash:\n");
printHash();
printf("after undef:\n");
undef("chris");
undef("table");
printHash();
}

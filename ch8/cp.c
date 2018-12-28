#include "ch8Code.h"

#define PERMS 0666 /* RW for owner, group, everyone */

int main(int argc, char *argv[])
/* copy file1 to file 2 */
{
int f1, f2, n;
char buf[BUFSIZE];

if (argc != 3)
    error("USAGE: cp from to");
if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
    error("cp: can't open %s", argv[1]);
if ((f2 = creat(argv[2], PERMS)) == -1)
    error("cp: can't create %s, mode %03o", argv[2], PERMS);

while ((n = read(f1, buf, BUFSIZE)) > 0)
    if (write(f2, buf, n) != n)
        error("cp: write error on file %s", argv[2]);
return 0; // no need for close(int fd) because of return
}

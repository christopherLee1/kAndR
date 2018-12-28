#include "ch8Code.h"

/* example usage of read and write sys call */
int readwrite()
{
char buf[BUFSIZE];
int n;
// read from stdin (0) into buf
while ((n = read(0, buf, BUFSIZE)) > 0)
    write(1, buf, n); // similarly write from buf to stdout (1)
return 0;
}

int _getchar1()
/* get one character at a time off of stdin */
{
char c;

return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int _getchar2()
/* get BUFSIZE characters at a time off of stdin */
{
static char buf[BUFSIZE];
static char *bufp = buf;
static int n = 0;

if (n == 0) // for when buf empty
    {
    n = read(0, buf, sizeof buf);
    bufp = buf;
    }
/*
the static variables retain allocations across calls to _getchar2,
so we only need to call read() when bufp is off the end of the array
*/
return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

/* to open file for reading: int fd = open(char *name, O_RDONLY, 0);
def: open(filename, how to open file flag, permissions)
to create a file:
int fd = creat(char *name, int perms); -1 if fails
*/

void error(char *fmt, ...)
/* print an error message and die */
{
va_list args;
va_start(args,fmt);
fprintf(stderr, "error: ");
vfprintf(stderr, fmt, args);
fprintf(stderr, "\n");
va_end(args);
exit(1);
}

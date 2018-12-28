#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFSIZE 1024

int _getchar1();
/* get one character at a time off of stdin */

int _getchar2();
/* get BUFSIZE characters at a time off of stdin */

void error(char *fmt, ...);
/* print an error message and die */

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my_stdio.h"

//#define BUFSIZE 1024

int _getchar1();
/* get one character at a time off of stdin */

int _getchar2();
/* get BUFSIZE characters at a time off of stdin */

void error(char *fmt, ...);
/* print an error message and die */

int _get(int fd, long pos, char *buf, int n);
/* read n bytes from position pos */

_FILE * _fopen1(char *name, char *mode);
/* open file, return file ptr */

_FILE * _fopen2(char *name, char *mode);
/* open file, return file ptr, uses fields instead enum */

int _fillbuf2(_FILE *fp);
/* allocate and fill input buffer, use flags_field instead of enum */

int _fillbuf(_FILE *fp);
/* allocate and fill input buffer */

int _flushbuf(int x, _FILE *fp);
/* write current buffer to fp->fd */

int _fflush(_FILE *fp);
/* write fp buffer to fd, pass along any errors */

int _fclose(_FILE *fp);
/* close file descriptor */

int _fseek(_FILE *fp, long offset, int origin);
/* Position fp->buf and fp->ptr to offset and origin.
fp should be an already opened file. */

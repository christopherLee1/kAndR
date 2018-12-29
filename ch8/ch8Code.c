#include "ch8Code.h"

/* example usage of read and write sys call */
int readwrite()
{
char buf[_BUFSIZE];
int n;
// read from stdin (0) into buf
while ((n = read(0, buf, _BUFSIZE)) > 0)
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
static char buf[_BUFSIZE];
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

/*
file seek:
long lseek(int fd, long offset, int origin);
origin 0: begnning
       1: current position
       2: end
append example:
lseek(fd, 0L, 2);
to get back to beginning:
lseek(fd, 0L, 0);
lseek returns new position in file or -1 if error occurs
fseek is similar to lseek byt first arg is FILE* and returns non-zero on error
*/

int _get(int fd, long pos, char *buf, int n)
/* read n bytes from position pos */
{
if (lseek(fd, pos, 0) >= 0)
    return read(fd, buf, n);
else
    return -1;
}

#define PERMS 0666

_FILE _iob[_OPEN_MAX] = 
    {
    {0, (char *) 0, (char *) 0, _READ, 0},
    {0, (char *) 0, (char *) 0, _WRITE, 1},
    {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2},
    };
    
_FILE * _fopen1(char *name, char *mode)
/* open file, return file ptr */
{
int fd;
_FILE *fp;

if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
for (fp = _iob; fp < _iob + _OPEN_MAX; fp++)
    if ((fp->flag & (_READ | _WRITE)) == 0)
        break; // found free slot
if (fp >= _iob + _OPEN_MAX) // no free slots
    return _NULL;

if (*mode == 'w')
    fd = creat(name, PERMS);
else if (*mode == 'a')
    {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
        fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
    }
else
    fd = open(name, O_RDONLY, 0);

if (fd == -1) // couldn't access name
    return _NULL;

fp->fd = fd;
fp->cnt = 0;
fp->base = _NULL;
fp->flag = (*mode == 'r') ? _READ : _WRITE;
return fp;
}

_FILE * _fopen2(char *name, char *mode)
/* open file, return file ptr, uses fields instead enum */
{
int fd;
_FILE *fp;

if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
for (fp = _iob; fp < _iob + _OPEN_MAX; fp++)
    if ((flags_field._READ || flags_field._WRITE) == 0)
        break; // found free slot
if (fp >= _iob + _OPEN_MAX) // no free slots
    return NULL;

if (*mode == 'w')
    fd = creat(name, PERMS);
else if (*mode == 'a')
    {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
        fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
    }
else
    fd = open(name, O_WRONLY, 0);

if (fd == -1) // couldn't access name
    return NULL;

fp->fd = fd;
fp->cnt = 0;
fp->base = NULL;
if (*mode == 'r')
    {
    flags_field._READ = 1;
    flags_field._WRITE = 0;
    }
else
    {
    flags_field._READ = 0;
    flags_field._WRITE = 1;
    }
fp->flag = (*mode == 'r') ? _READ : _WRITE;
return fp;
}

int _fillbuf(_FILE *fp)
/* allocate and fill input buffer */
{
int bufsize;
if ((fp->flag & (_READ | _EOFERR | _ERR)) != _READ)
    return _EOFERR;
bufsize = (fp->flag & _UNBUF) ? 1 : _BUFSIZE;
if (fp->base == _NULL)
    if ((fp->base = (char *) malloc(bufsize)) == _NULL)
        return _EOFERR;
fp->ptr = fp->base;
fp->cnt = read(fp->fd, fp->ptr, bufsize);
if (--fp->cnt < 0)
    {
    if (fp->cnt == -1)
        fp->flag |= _EOFERR;
    else
        fp->flag |= _ERR;
    fp->cnt = 0;
    return _EOFERR;
    }
return (unsigned char) *fp->ptr++;
}

int _fillbuf2(_FILE *fp)
/* allocate and fill input buffer, use flags_field instead of enum */
{
int bufsize;
if ((flags_field._READ | flags_field._EOF | flags_field._ERR) != _READ)
    return _EOFERR;
bufsize = (flags_field._UNBUF) ? 1 : _BUFSIZE;
if (fp->base == _NULL)
    if ((fp->base = (char *) malloc(bufsize)) == _NULL)
        return _EOFERR;
fp->ptr = fp->base;
fp->cnt = read(fp->fd, fp->ptr, bufsize);
if (--fp->cnt < 0)
    {
    if (fp->cnt == -1)
        flags_field._EOF = 1;
    else
        flags_field._ERR = 1;
    fp->cnt = 0;
    return _EOFERR;
    }
return (unsigned char) *fp->ptr++;
}

int _flushbuf(int x, _FILE *fp)
/* write current buffer to fp->fd */
{
int bufsize, nw;
unsigned char c = x;
if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
    {
    return _EOFERR;
    }
bufsize = (fp->flag & _UNBUF) ? 1 : _BUFSIZE;
if (fp->base == _NULL)
    {
    if ((fp->base = (char *) malloc(bufsize)) == _NULL)
        {
        return _EOFERR;
        }
    }
else
    {
    nw = fp->ptr - fp->base;
    if ((write(fp->fd, fp->base, nw)) != nw)
        {
        fp->flag |= _ERR;
        return _EOFERR;
        }
    }
fp->ptr = fp->base;
*fp->ptr++ = c;
fp->cnt = bufsize - 1;
return fp->cnt;
}

int _fflush(_FILE *fp)
/* write fp buffer to fd, pass along any errors */
{
int x;
if ((fp->flag & _WRITE) != _WRITE)
    error("trying to flush file descriptor %d that is not open for write", fp->fd);    
x = _flushbuf(0, fp);
fp->cnt = 0;
fp->base = fp->ptr = _NULL;
return x;
}

int _fclose(_FILE *fp)
/* close file descriptor */
{
int x;
if (fp->flag != _EOFERR && (fp->flag & _WRITE) == _WRITE)
    // don't _fflush a file open for input
    {
    x = _fflush(fp);
    }
if (fp->base != _NULL)
    free(fp->base);
x = close(fp->fd);
fp->flag = 0;
fp->base = fp->ptr = _NULL;
fp->cnt = 0;
return x;
}

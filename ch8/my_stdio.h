#define _NULL 0
#define _EOFERR (-1)
#define _BUFSIZE 1024
#define _OPEN_MAX 20 // max open files at once

typedef struct _iobuf
    {
    int cnt; // characters left
    char *ptr; // next character position
    char *base; //location of buffer
    int flag; // mode of file access
    int fd; // file descriptor
    } _FILE;

extern _FILE _iob[_OPEN_MAX];

#define _stdin (&_iob[0])
#define _stdout (&_iob[1])
#define _stderr (&_iob[2])

struct
    {
    unsigned int _READ : 1;
    unsigned int _WRITE : 1;
    unsigned int _UNBUF : 1;
    unsigned int _EOF : 1;
    unsigned int _ERR : 1;
    } flags_field;

enum flags
    {
    _READ = 01, // file open for reading
    _WRITE = 02, // file open for writing
    _UNBUF = 04, // file is unbuffered
    _EOF = 010, // EOF has occurred on this file
    _ERR = 020, // error occurred on this file
    };

int _fillbuf(_FILE *fp);
/* allocate and fill input buffer */

int _fillbuf2(_FILE *fp);
/* allocate and fill input buffer, use flags_field instead of enum */

int _flushbuf(int x, _FILE *fp);
/* remove chars from input buffer */

int _fflush(_FILE *fp);
/* write fp buffer to fd */

int _fclose(_FILE *fp);
/* close file descriptor */

#define _feof(p) (((p)->flag & _EOF) != 0)
#define _ferror(p) (((p)->flag & _ERR) != 0)
#define _fileno(p) ((p)->fd)

#define _getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define _putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define _getchar() _getc(_stdin)
#define _putchar(x) _putc((x), _stdout)

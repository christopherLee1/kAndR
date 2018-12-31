#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NAME_MAX 14 // longest filename component

typedef struct
    {
    long ino; // inode number
    char name[NAME_MAX+1]; // name plus null
    } _Dirent;

typedef struct
    {
    int fd; // file descriptor for directory
    _Dirent d; // the directory entry
    } _DIR;

#define DIRSIZ 14

struct _direct
    {
    ino_t d_ino; // inode number
    char d_name[DIRSIZ];
    };

_DIR *_opendir(char *dirname);

_Dirent *_readdir(_DIR *dfd);

void _closedir(_DIR *dfd);

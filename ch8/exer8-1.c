#include "ch8Code.h"

void filecopy(int ifp, int ofp)
/* copy file ifp to file ofp */
{
int c;
char buf[_BUFSIZE];
while ((c = read(ifp, buf, _BUFSIZE)) > 0)
    write(ofp, buf, c);
}

int main(int argc, char *argv[])
/* concatenate files */
{
int fd;
char *prog = argv[0]; /* prog name for errors */
if (argc == 1)
    filecopy(0, 1);
else
    while (--argc > 0)
        if ((fd = open(*++argv, O_RDONLY)) == -1)
            {
            error("%s: can't open %s\n", prog, *argv);
            }
        else
            {
            filecopy(fd, 1);
            close(fd);
            }
if (ferror(stderr))
    {
    error("%s: error writing stdout\n", prog);
    }
exit(0);
}

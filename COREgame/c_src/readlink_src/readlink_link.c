#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

#include "../../c_src_headers/readlink_headers/readlink_link.h"

char *argv0;

#define ARGBEGIN    for (argv0 = *argv, argv++, argc--;\
                    argv[0] && argv[0][0] == '-'\
                    && argv[0][1];\
                    argc--, argv++) {\
                char argc_;\
                char **argv_;\
                int brk_;\
                if (argv[0][1] == '-' && argv[0][2] == '\0') {\
                    argv++;\
                    argc--;\
                    break;\
                }\
                for (brk_ = 0, argv[0]++, argv_ = argv;\
                        argv[0][0] && !brk_;\
                        argv[0]++) {\
                    if (argv_ != argv)\
                        break;\
                    argc_ = argv[0][0];\
                    switch (argc_)

#define ARGEND          }\
            }


static void eprintf(char *spec, ...)
{
    va_list list;
    va_start(list, spec);
    vfprintf(stderr, spec, list);
    va_end(list);
}

static void usage(void)
{
    eprintf("usage: %s [-fn] path\n");
}

static int flush(void)
{
    fflush(stdout);
    return 0;
}

int core_readlink(int argc, char *argv[])
{
    char buf[PATH_MAX];
    ssize_t n;
    int nflag = 0, fflag = 0;
    
    fflush(stdout);

    ARGBEGIN
    {
        case 'f':
            fflag = 1;
            break;
        case 'n':
            nflag = 1;
            break;
        default:
            usage();
    }
    ARGEND

    if (argc != 1)
        usage();

    if (strlen(argv[0]) >= PATH_MAX)
        eprintf("path is too long\n");

    if (fflag)
    {
        if (!realpath(argv[0], buf))
            eprintf("realpath is %s:", argv[0]);
    }
    else
    {
        if ((n = readlink(argv[0], buf, PATH_MAX - 1)) < 0)
            eprintf("readlink is %s:", argv[0]);
        
        buf[n] = '\0';
    }

    fputs(buf, stdout);
    if (!nflag)
        putchar('\n');

    return flush();
}

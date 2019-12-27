#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../c_src_headers/readlink_headers/readlink_link.h"
#include "../c_src_headers/readlink_headers/readlink_upload.h"
#include "../c_test_headers/readlink_test.h"

#define ARGC 3
#define STRL 24

int test_dl(void)
{
    int oargc = ARGC;
    char **oargv = NULL;

    oargv = realloc(oargv, sizeof(char *) * ARGC);
    oargv[0] = calloc(sizeof(char), STRL);
    oargv[1] = calloc(sizeof(char), STRL);
    oargv[2] = calloc(sizeof(char), STRL);

    strncpy(oargv[0], "readlink", STRL);
    strncpy(oargv[1], "-f", STRL);
    strncpy(oargv[2], "/bin/sh", STRL);

    int result = core_readlink(oargc, oargv);

    return result;
}

int test_link(void)
{
    fprot readlinkptr = get_core_readlink();
    if (!readlinkptr)
        return -1;
    
    int oargc = ARGC;
    char **oargv = NULL;

    oargv = realloc(oargv, sizeof(char *) * ARGC);
    oargv[0] = calloc(sizeof(char), STRL);
    oargv[1] = calloc(sizeof(char), STRL);
    oargv[2] = calloc(sizeof(char), STRL);

    strncpy(oargv[0], "readlink", STRL);
    strncpy(oargv[1], "-f", STRL);
    strncpy(oargv[2], "/bin/sh", STRL);

    int result = readlinkptr(oargc, oargv);

    return result;
}

int readlink_test(void)
{
    if (test_dl())
        return -1;

    if (test_link())
        return -1;

    return 0;
}

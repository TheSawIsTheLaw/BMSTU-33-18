#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../c_src_headers/readlink_headers/readlink_upload.h"

fprot get_core_readlink(void)
{
    void *readlink_lib = dlopen(READLINKLIBNAME, RTLD_LAZY);
    if (!readlink_lib)
    {
        fprintf(stderr, "failed to open lib %s\n", READLINKLIBNAME);
        return NULL;
    }

    void *fptr = dlsym(readlink_lib, READLINKNAME);
    if (!fptr)
    {
        fprintf(stderr, "failed to find symbols\n");
        return NULL;
    }

    return (fprot)fptr;
}

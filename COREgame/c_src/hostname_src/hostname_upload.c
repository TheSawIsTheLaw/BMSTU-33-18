#include "../../c_src_headers/hostname_headers/hostname_upload.h"

fprot get_hostname()
{
    void *lib = NULL;
    int (*hostname_util)(const char *const, char *const) = NULL;
    
    if (!(lib = dlopen("../../libs/libcore.so", RTLD_LAZY)))
    {
        printf("lib not loaded\n");
        return NULL;
    }

    if (!(hostname_util = dlsym(lib, "_hostname_")))
    {
        printf("can't get function\n");
        return NULL;
    }

    return hostname_util;
}
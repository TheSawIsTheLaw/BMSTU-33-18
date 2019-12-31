#include "../../c_src_headers/pwd_headers/pwd_upload.h"

fprot get_pwd()
{
    void *lib = NULL;
    int (*pwd_util)(const char *const, char *const) = NULL;

    if (!(lib = dlopen("../libs/libcore.so", RTLD_LAZY)))
    {
        printf("lib not loaded\n");
        return NULL;
    }

    if (!(pwd_util = dlsym(lib, "pwd")))
    {
        printf("can't get function\n");
        return NULL;
    }

    return pwd_util;
}

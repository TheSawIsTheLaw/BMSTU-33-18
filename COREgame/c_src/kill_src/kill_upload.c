#include "../../c_src_headers/kill_headers/kill_upload.h"

fprot get_hostid()
{
    void *lib = dlopen("../../libs/libcore.so", RTLD_LAZY);
    int (*kill_util)() = NULL;

    if (!lib)
    {
        printf("Lib open error\n");
        return NULL;
    }

    kill_util = dlsym(lib, "core_kill");

    if (!kill_util)
    {
        printf("Function access error\n");
        return NULL;
    }

    return kill_util;
}

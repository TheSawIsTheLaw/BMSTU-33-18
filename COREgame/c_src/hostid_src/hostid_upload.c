#include "../../c_src_headers/hostid_headers/hostid_upload.h"

#include <stdio.h>
#include <dlfcn.h>

fprot get_hostid()
{
    void *lib = dlopen("../../libs/libcore.so", RTLD_LAZY);
    int (*hostid_util)() = NULL;

    if (!lib)
    {
        printf("Error open file!\n");
        return NULL;
    }

    hostid_util = dlsym(lib, "hostid");

    if (!hostid_util)
    {
        printf("Error!\n");
        return NULL;
    }

    return hostid_util;
}

// int main()
// {
//     // get_hostid();

//     int (*hostid_util)() = get_hostid();
//     printf("Result: %d\n", (*hostid_util)());

//     return 0;
// }
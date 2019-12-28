#include "../../c_src_headers/nice_headers/nice_upload.h"

nice_fp get_nice()
{
    void *lib = NULL;
    int (*nice)(char **, int *, int *) = NULL;

    if (!(lib = dlopen("../libs/libcore.so", RTLD_LAZY)))
    {
        printf("lib is not loaded\n");
        return NULL;
    }

    if (!(nice = dlsym(lib, "nice")))
    {
        printf("can't get function\n");
        return NULL;
    }

    return nice;
}

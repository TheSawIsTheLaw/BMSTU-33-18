#include "../../c_src_headers/true_headers/true_upload.h"
#define OUTSTREAM stderr

fprot get_yes()
{
    void *lib = NULL;
    int (*true_util)() = NULL;
    
    if (!(lib = dlopen("../libs/libcore.so", RTLD_LAZY)))
    {
        fprintf(OUTSTREAM, "lib isnt loaded\n");
        return NULL; //*
    }
    
    if (!(true_util = dlsym(lib, "true")))
    {
        fprintf(OUTSTREAM, "function not reachable\n");
        return NULL; //*
    }
    
    return true_util;
}

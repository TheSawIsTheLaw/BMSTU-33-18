#include "../../c_src_headers/yes_headers/yes_upload.h"
fprot get_yes()
{
    void *lib = NULL;
    int (*yes_util)(const char* const, char* const) = NULL;
    
    if (!(lib = dlopen("../libs/libcore.so", RTLD_LAZY)))
    {
        printf("lib isnt loaded\n");
        return NULL; //*
    }
    
    if (!(yes_util = dlsym(lib, "yes")))
    {
        printf("function not reachable\n");
        return NULL; //*
    }
    
    return yes_util;

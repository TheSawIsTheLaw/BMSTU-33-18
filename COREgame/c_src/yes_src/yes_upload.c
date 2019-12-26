#include "../../c_src_headers/yes_headers/yes_upload.h"
#define OUTSTREAM stderr

fprot get_yes()
{
    void *lib = NULL;
    int (*yes_util)(const char* const, char* const) = NULL;
    
    if (!(lib = dlopen("../libs/libcore.so", RTLD_LAZY)))
    {
        fprintf(OUTSTREAM, "lib isnt loaded\n");
        return NULL; //*
    }
    
    if (!(yes_util = dlsym(lib, "yes")))
    {
        fprintf(OUTSTREAM, "function not reachable\n");
        return NULL; //*
    }
    
    return yes_util;
}

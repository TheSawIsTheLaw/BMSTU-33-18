#include <stdio.h>
#include <dlfcn.h>

#include "../../c_src_headers/rev_headers/rev_upload.h"



fprot get_rev(void)
{
    void *lib_rev = dlopen(REV_LIBNAME, RTLD_LAZY);
    if (!lib_rev)
    {
        fprintf(stderr, "Error!\nOpening '%s' failed!\n", REV_LIBNAME);
        return NULL;
    }

    fprot f_ptr = (fprot)dlsym(lib_rev, FUNC_NAME);
    if (!f_ptr)
    {
        fprintf(stderr, "Error!\nUploading '%s' failed!\n", FUNC_NAME);
        return NULL;
    }

    return f_ptr;
}

//wc - print the number of lines, words, and bytes in files
#include "../../c_src_headers/wc_headers/wc_upload.h"
#include <dlfcn.h>

fprot get_wc(void)
{
    void *wc_lib = dlopen(WCLIBNAME, RTLD_LAZY);
    if (!wc_lib)
    {
        fprintf(stderr, "failed to open lib %s\n", WCLIBNAME);
        return NULL;
    }

    void *fptr = dlsym(wc_lib, WCNAME);
    if (!fptr)
    {
        fprintf(stderr, "failed to find symbols\n");
        return NULL;
    }

    return (fprot)fptr;
}



#include "../../c_src_headers/dirname_headers/dirname_upload.h"

fprot get_dirname(void)
{
    void *wc_lib = dlopen("../../libs/libcore.so", RTLD_LAZY);
    if (!wc_lib)
    {
        fprintf(stderr, "failed to open lib %s\n", "libdirname.so");
        return NULL;
    }

    void *fptr = dlsym(wc_lib, "dirname");
    if (!fptr)
    {
        fprintf(stderr, "failed to find symbols\n");
        return NULL;
    }

    return (fprot)fptr;
}




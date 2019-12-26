#include "../../c_src_headers/cksum_headers/cksum_upload.h"

void get_cksum()
{
    uint32_t (*cksum)(FILE *, const char *);
    void *cksum_lib = dlopen("../../libs/libcore.so", RTLD_LAZY);
    if (!cksum_lib)
    {
        fprintf(stderr, "failed to open lib %s\n", "libcore.so");
        return NULL;
    }

    cksum = dlsym(cksum_lib, "cksum");
    if (!cksum)
    {
        fprintf(stderr, "failed to find cksum\n");
        return NULL;
    }
}

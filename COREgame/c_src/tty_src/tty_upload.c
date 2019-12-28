#include <dlfcn.h>
#include "../../c_src_headers/tty_headers/tty_upload.h"

fprot get_tty(void)
{
    void *tty_lib;
    char *err;
    tty_lib = dlopen(TTYLIBNAME, RTLD_LAZY);

    if (!tty_lib)
    {
        fputs(dlerror(), stderr);
        return NULL;
    }

    dlerror();
    void *fptr;
    fptr = dlsym(tty_lib, TTYNAME);
    if ((err = dlerror()) != NULL)
    {
        fputs(err, stderr);
        return NULL;
    }

    return (fprot)fptr;
}

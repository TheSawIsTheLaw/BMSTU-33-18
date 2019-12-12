#ifndef _WC_UPLOAD_H_
#define _WC_UPLOAD_H_

#include <stdio.h>
#include <stdlib.h>

#define WCLIBNAME "libwc.so"
#define WCNAME "core_wc"

typedef int (*fprot)(int argc, char *argv[]);

fprot get_wc(void);

#endif

#ifndef __HOSTNAME_UPLOAD_H__
#define __HOSTNAME_UPLOAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*fprot)(int, char **);

fprot get_dirname();

#endif

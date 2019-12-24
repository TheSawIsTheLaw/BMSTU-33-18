#ifndef _HOSTNAME_UPLOAD_H_

#define _HOSTNAME_UPLOAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*fprot)(const char *const, char *const);

fprot get_hostname();

#endif
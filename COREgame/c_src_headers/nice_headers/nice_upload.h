#ifndef _NICE_UPLOAD_H_
#define _NICE_UPLOAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*nice_fp)(char **, int *, int *);

nice_fp get_nice();

#endif
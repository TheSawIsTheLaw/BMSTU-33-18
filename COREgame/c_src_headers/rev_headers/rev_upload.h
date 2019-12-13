#ifndef _REV_UPLOAD_H_
#define _REV_UPLOAD_H_


#define REV_LIBNAME "librev.so"
#define FUNC_NAME "rev"

typedef int (*fprot)(int argc, char *argv);

fprot get_rev(void);

#endif
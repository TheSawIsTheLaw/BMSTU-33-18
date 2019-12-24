#ifndef _REV_UPLOAD_H_
#define _REV_UPLOAD_H_


#define REV_LIBNAME "../libs/libcore.so"
#define FUNC_NAME "rev"

typedef int (*fprot)(int argc, char *argv);

fprot get_rev(void);

#endif
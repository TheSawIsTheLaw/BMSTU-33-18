#ifndef _READLINK_UPLOAD_H_
#define _READLINK_UPLOAD_H_

#define READLINKLIBNAME "libreadlink.so"
#define READLINKNAME "core_readlink"

typedef int (*fprot)(int argc, char *argv[]);

fprot get_core_readlink(void);

#endif

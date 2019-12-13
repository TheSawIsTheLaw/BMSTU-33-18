#ifndef __TTY_UPLOAD_H__
#define __TTY_UPLOAD_H__

#define TTYLIBNAME "libtty.so"
#define TTYNAME "tty"

typedef int (*fprot)(int argc, char **argv);

fprot get_tty(void);

#endif // __TTY_UPLOAD_H__

#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>
#include "../../c_src_headers/nice_headers/nice_link.h"

extern int getpriority(__priority_which_t __which, id_t __who) __THROW;
extern int setpriority(__priority_which_t __which, id_t __who, int __prio) __THROW;
extern int execvp(const char *__file, char *const __argv[])
    __THROW __nonnull((1, 2));

#define GETNICENESS() getpriority(0, 0)

#define NZERO 20
#define MIN_ADJUSTMENT 1 - 2 * NZERO,
#define MAX_ADJUSTMENT 2 * NZERO - 1

#define OK 0
#define PERMISSION_ERROR 13
#define NICE_ERROR 17
#define ARGS_ERROR 21
#define EXEC_ERROR 22

#define EACCES 13

static int perm_related_errno(int err)
{
    return err == EACCES || err == EPERM;
}

int nice(char **program_argv, int *incr, int *value)
{
    int current_niceness = 0;
    if (!incr)
    {
        current_niceness = GETNICENESS();
        if (current_niceness == -1 && errno != 0)
            return perm_related_errno(errno) ? PERMISSION_ERROR : NICE_ERROR;
        if (value)
        {
            *value = current_niceness;
            return OK;
        }
        return ARGS_ERROR;
    }

    if (!program_argv || !(*program_argv))
        return ARGS_ERROR;
    int adjustment;
    int min = (*incr < MAX_ADJUSTMENT) ? *incr : MAX_ADJUSTMENT;
    adjustment = (min > 10) ? min : 10;
    int ok = (setpriority(0, 0, current_niceness + adjustment) == 0);
    if (!ok)
        return NICE_ERROR;

    execvp(*program_argv, program_argv);
    return EXEC_ERROR;
}

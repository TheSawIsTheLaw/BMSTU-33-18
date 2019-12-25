#include "../../c_src_headers/pwd_headers/pwd_link.h"

#define PATH_MAX 100

#define SUCCESS 0
#define MEMORY_ERROR 1
 
int pwd(void)
{
    char *cwd = NULL;

    cwd = getcwd(cwd, PATH_MAX);

    if (!cwd)
        return MEMORY_ERROR;

    puts(cwd);

    free(cwd);
 
    return SUCCESS;
}

int main ()
{
    int check = pwd();
    if (check)
        return MEMORY_ERROR;

    return SUCCESS;
}

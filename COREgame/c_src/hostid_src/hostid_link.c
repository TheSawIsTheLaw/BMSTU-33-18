#include "../../c_src_headers/hostid_headers/hostid_link.h"

#include <unistd.h>

#include <stdio.h>

#define EXIT_SUCCESS 0

int hostid()
{
    unsigned int id;

    id = gethostid();

    id &= 0xffffffff;

    printf("%08x\n", id);

    return EXIT_SUCCESS;
}
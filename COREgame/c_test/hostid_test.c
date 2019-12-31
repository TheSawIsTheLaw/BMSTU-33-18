#include <stdio.h>

#include "../c_src_headers/hostid_headers/hostid_link.h"

#define OK 0

void test_hostid()
{
    if (hostid() != OK)
        printf("failed!\n");
    else
        printf("Passed!\n");
}

int main()
{
    test_hostid();

    return OK;
}
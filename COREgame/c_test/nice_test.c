#include <stdlib.h>
#include <stdio.h>

#include "../c_src_headers/nice_headers/nice_link.h"
#include "../c_src_headers/nice_headers/nice_upload.h"
#include "../c_test_headers/nice_test.h"

#define ARGC 3
#define STRL 24

int test_link(void)
{
    int value = 0;
    int result = nice(NULL, NULL, &value);
    return result;
}

int test_dl(void)
{
    nice_fp niceptr = get_nice();
    if (!niceptr)
        return -1;

    int value = 0;
    int result = niceptr(NULL, NULL, &value);
    return result;
}

int nice_test(void)
{
    if (test_dl())
        return -1;

    if (test_link())
        return -1;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "../c_src_headers/wc_headers/wc_upload.h"
#include "../c_src_headers/wc_headers/wc_link.h"

int test_dl(int argc, char** argv)
{
    fprot wcptr = get_wc();

    if (wcptr)
        return wcptr(argc, argv);
    return -1;
}

int test_link(int argc, char** argv)
{
    return wc(argc, argv);
}

int main(int argc, char** argv)
{
    test_dl(argc, argv);
    
    test_link(argc, argv);
}
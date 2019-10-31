#include <stdio.h>
#include "../interfaces/actorfile_interface.h"

int main(int argc, char **argv)
{
    FILE *f_in = NULL, *f_out = NULL;

    f_in = fopen(argv[1], "rb");
    f_out = fopen(argv[2], "wb");
    remove_duplicates(f_in, f_out);
    fclose(f_in);
    fclose(f_out);

    f_out = fopen(argv[2], "rb");
    check_duplicates(f_out);
    fclose(f_out);

    return OK;
}
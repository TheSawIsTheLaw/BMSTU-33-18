#include <stdio.h>
#include "../interfaces/actorfile_interface.h"

int main(int argc, char **argv)
{
    FILE *f_in = NULL;

    f_in = fopen(argv[1], "rb+");
    sort_file_id_name(f_in, 0, 9336191);
    print_file(f_in);
    fclose(f_in);

    return OK;
}
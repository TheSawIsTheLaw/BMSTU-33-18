#include <stdio.h>
#include "actorfile_interface.h"

int main(int argc, char **argv)
{
    FILE *f_in = NULL;
    int needed_id;
    char actor_name[ACTOR_NAME_LEN];

    f_in = fopen(argv[1], "rb");
    scanf("%[^\n]", actor_name);
    needed_id = get_id_by_name(f_in, actor_name);
    printf("%d\n", needed_id);
    fclose(f_in);

    return OK;
}
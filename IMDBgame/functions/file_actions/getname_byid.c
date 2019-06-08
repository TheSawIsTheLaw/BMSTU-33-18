#include <stdio.h>
#include "actorfile_interface.h"

int main(int argc, char **argv)
{
    FILE *f_in = NULL;
    int needed_id, name_status;
    char actor_name[ACTOR_NAME_LEN];

    f_in = fopen(argv[1], "rb");
    scanf("%d", &needed_id);
    name_status = get_name_by_id(f_in, needed_id, actor_name);

    if (name_status != -1)
        printf("%s\n", actor_name);

    else
        printf("Actor not found\n");

    fclose(f_in);

    return OK;
}
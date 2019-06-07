#include <stdio.h>
#include "create_arrs.h"
#include "cleaner.h"


int main(void)
{
    setbuf(stdout, NULL);
    printf("heere");
    static int actor_to_actor_arr[FULL_FILE_SIZE][2];
    FILE *f;

    f = fopen("actors_file.bin", "rb");

    make_array(actor_to_actor_arr, f, FULL_FILE_SIZE);
    FILE *f2;
    f2 = fopen("clean_actors_file.bin", "wb");

	write_clean_array(actor_to_actor_arr, FULL_FILE_SIZE, f2);
    int size = get_file_size(f2);

    fclose(f);
    fclose(f2);
    printf("%d", size);
    return 0;
}

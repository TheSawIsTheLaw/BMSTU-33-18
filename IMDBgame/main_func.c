#include <stdio.h>
#include "functions/interfaces/actorfile_interface.h"
#include "functions/interfaces/graph_interface.h"

int main()
{
    setbuf(stdout, NULL);

    static int main_pairs_arr[CLEAN_FILE_SIZE][PAIR_LEN];
    static int main_tree[ACTORS_PAIRS_SIZE];
    int route[MAX_ROUTE_LEN];
    int from, to, size;
    FILE *f_cln_actors, *f_id_names;
    char actor[100];

    f_cln_actors = fopen("data/clean_actors_file.bin", "rb");
    make_array(main_pairs_arr, f_cln_actors, CLEAN_FILE_SIZE);
    fclose(f_cln_actors);
    
    f_id_names = fopen("data/ID_NAME_NODUPS.bin", "rb");

    printf("IMDB-based Bacon number finder\n\n");

    read_actor:
    printf("Input actor, whos distance you want to find: ");
    
    int i = -1;
    do
    {
        i++;
        scanf("%c", &actor[i]);
    } while (actor[i] != '\n');

    actor[i] = '\0';

    from = get_id_by_name(f_id_names, actor);

    if (from == NO_MATCHES)
    {
        printf("No matches for this actor in database\n");
        goto read_actor;
    }
    
    make_tree(main_tree, main_pairs_arr, CLEAN_FILE_SIZE, from);

    while (1)
    {
        read_actor_to:
        printf("Input actor, from which you need to find distance to base actor: ");
        
        int i = -1;
        do
        {
            i++;
            scanf("%c", &actor[i]);
        } while (actor[i] != '\n');

        actor[i] = '\0';

        to = get_id_by_name(f_id_names, actor);

        if (to == NO_MATCHES)
        {
            printf("No matches for this actor in database\n");
            goto read_actor_to;
        }

        size = get_route(main_tree, to, route);

        if (size > -1)
        {
            printf("\nDISTANCE = %d\n", size - 1);

            printf("WAY: ");
            for (int i = 0; i < size; i++)
            {
                get_name_by_id(f_id_names, route[i], actor);
                printf("%d %s ", route[i], actor);

                if (i != size - 1)
                    printf("-> ");
            }

            printf("\n\n");
        }

        else
            printf("No connection\n\n");
    }

    return 0;
}

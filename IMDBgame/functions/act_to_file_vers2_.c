#include <stdio.h>
#include "create_arrs.h"

#define COUNT 1000
#define COUNT_OF_C1CTIONS_ACTOR_FILMS SIZE
#define COUNT_OF_C1CTIONS_FILMS_ACTOR SIZE
#define COUNT_OF_ELEMENTS_IN_1_C1CTION 2

#define OK 1
#define NOT_OK 0

#define FALSE 0
#define TRUE 1

#define SUCCESS_EXIT 0


// бинарный поиск
int bin_search(int need_id ,int matrix[][COUNT_OF_ELEMENTS_IN_1_C1CTION], int len)
{
    int left, right, middle;
    left = 0;
    right = len - 1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (need_id < matrix[middle][0])
            right = middle - 1;
        else if (need_id > matrix[middle][0])
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

int search_start_index_for_film(int films_actors[][COUNT_OF_ELEMENTS_IN_1_C1CTION], int cur_film)
{
    int index = bin_search(cur_film, films_actors, COUNT_OF_C1CTIONS_FILMS_ACTOR);
    while (films_actors[index - 1][0] == films_actors[index][0] && index > 0)
    {
        --index;
    }
    return index;
}

void make_array_actor_to_actor(int actors_films[][COUNT_OF_ELEMENTS_IN_1_C1CTION], int films_actors[][COUNT_OF_ELEMENTS_IN_1_C1CTION], FILE *actors_file)
{
    int cur_actor = -1;
    int cur_film = -1;

    for (int el = 0; el < COUNT_OF_C1CTIONS_ACTOR_FILMS; el++)
    {
        cur_actor = actors_films[el][1];

        if (cur_actor == 0)
        {
            fclose(cur_file);
            return;
        }

        int index_for_film = search_start_index_for_film(films_actors, cur_film);

        while (films_actors[index_for_film][0] == cur_film)
        {
            fwrite(&cur_actor, sizeof(int), 1, actors_file);
            fwrite(&films_actors[index_for_film][1], sizeof(int), 1, actors_file);
            ++index_for_film;
        }
    }
}

int main()
{
    int actors_films[SIZE][2];
    int films_actors[SIZE][2];
    int size;

    create_mas(films_actors, &size, "out.bin");
    copy_mas(films_actors, actors_films);
    my_sort(films_actors, 0, size - 1, 0);
    my_sort(actors_films, 0, size - 1, 1);

    FILE *actors_file;

    actors_file = fopen("actors_file.bin", "wb");

    make_array_actor_to_actor(actors_films, films_actors, actors_file);
    fclose(actors_file);

    return SUCCESS_EXIT;
    
}
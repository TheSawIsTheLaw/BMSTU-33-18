#include <stdio.h>
#include "create_arrs.h"


void reverse(int actors_films)


int main()
{
    int actors_films[SIZE][2];
    int films_actors[SIZE][2];
    int size;

    create_mas(films_actors, &size, "out.bin");
    copy_mas(films_actors, actors_films);
    my_sort(films_actors, 0, size - 1, 0);
    my_sort(actors_films, 0, size - 1, 1);
    
}

#include <stdio.h>

#define ZERO 0
#define ONE 1

#define COUNT 1000
#define COUNT_OF_CONECTIONS_ACTOR_FILMS 6
#define COUNT_OF_CONECTIONS_FILMS_ACTOR 6
#define COUNT_OF_ELEMENTS_IN_ONE_CONECTION 2

#define OK 1
#define NOT_OK 0

#define SUCCESS_EXIT 0


// бинарный поиск
int bin_search(int need_id ,int matrix[][COUNT_OF_ELEMENTS_IN_ONE_CONECTION], int len)
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

//
int search_start_index_for_film(int matrix_films_actors[][COUNT_OF_ELEMENTS_IN_ONE_CONECTION], int cur_film)
{
    int index = bin_search(cur_film, matrix_films_actors, COUNT_OF_CONECTIONS_FILMS_ACTOR);
    while (matrix_films_actors[index - 1][0] == matrix_films_actors[index][0] && index > 0)
    {
        --index;
    }
    return index;
}

void reads_in_matrix_of_conections_actors(int finaly_matrix[][COUNT_OF_ELEMENTS_IN_ONE_CONECTION], int *n, int cur_actor, int *el)
{
    finaly_matrix[*n][0] = cur_actor;
    finaly_matrix[*n][1] = *el;
    printf("(%d %d)\n", cur_actor, *el);
    (*n)++;
}

int make_array_actor_to_actor(int matrix_actors_films[][COUNT_OF_ELEMENTS_IN_ONE_CONECTION], int matrix_films_actors[][COUNT_OF_ELEMENTS_IN_ONE_CONECTION], int finaly_matrix[][COUNT_OF_ELEMENTS_IN_ONE_CONECTION])
{
    int n = 0;
    int last_actor = -1;
    int cur_actor = -1;
    int cur_film = -1;
    for (int el = ZERO; el < COUNT_OF_CONECTIONS_ACTOR_FILMS; el++)
    {
        last_actor = cur_actor;
        cur_actor = matrix_actors_films[el][ONE];
        cur_film = matrix_actors_films[el][ZERO];
        
        int index_for_film = search_start_index_for_film(matrix_films_actors, cur_film);
        
        while (matrix_films_actors[index_for_film][ZERO] == cur_film) {
            if (cur_actor == last_actor)
            {
                if (finaly_matrix[n - 1][ONE] < matrix_films_actors[index_for_film][ONE])
                {
                    printf("%d %d - 01\n", finaly_matrix[n - 1][ONE], matrix_films_actors[index_for_film][ONE]);
                    reads_in_matrix_of_conections_actors(finaly_matrix, &n, cur_actor, &matrix_films_actors[index_for_film][ONE]);
                }
                ++index_for_film;
            }
            else
            {
                printf("0-0\n");
                reads_in_matrix_of_conections_actors(finaly_matrix, &n, cur_actor, &matrix_films_actors[index_for_film][ONE]);
                ++index_for_film;
            }
        }
    }
    
    return n;
}


int main(void)
{
    printf("start\n");
    
    int matrix_actors_films[COUNT_OF_CONECTIONS_ACTOR_FILMS][COUNT_OF_ELEMENTS_IN_ONE_CONECTION] ={{1, 11},
        {2, 11},
        {3, 11},
        {2, 22},
        {3, 22},
        {3, 33}
    };
    int matrix_films_actors[COUNT_OF_CONECTIONS_FILMS_ACTOR][COUNT_OF_ELEMENTS_IN_ONE_CONECTION] = {{1, 11},
        {1, 22},
        {2, 11},
        {3, 11},
        {3, 22},
        {3, 33}
    };
    
    int finaly_matrix[COUNT][COUNT_OF_ELEMENTS_IN_ONE_CONECTION] = {{0, 0}};
    
    int rc = make_array_actor_to_actor(matrix_actors_films, matrix_films_actors, finaly_matrix);
    printf("%d\n", rc);
    
    return SUCCESS_EXIT;
}

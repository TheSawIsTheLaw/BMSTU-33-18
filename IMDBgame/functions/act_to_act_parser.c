#include <stdio.h>
#include "create_arrs.h"

#define 0 0
#define 1 1

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

//
int search_start_index_for_film(int films_actors[][COUNT_OF_ELEMENTS_IN_1_C1CTION], int cur_film)
{
    int index = bin_search(cur_film, films_actors, COUNT_OF_C1CTIONS_FILMS_ACTOR);
    while (films_actors[index - 1][0] == films_actors[index][0] && index > 0)
    {
        --index;
    }
    return index;
}


//По заданной позиции, позволяет прочитать число в указанной позиции
int get_number_by_pos(FILE *f, const int position)
{
    int number;
    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fread(&number, sizeof(int), 1, f);
    return number;
}

//По заданной позиции, позволяет записать число в указанную позицию
void put_number_by_pos(FILE *f, const int position, const int number)
{
    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fwrite(&number, sizeof(int), 1, f);
}

void swap(FILE *cur_file, int right, int left)
{
    int a;
    int b;
    a = get_number_by_pos(cur_file, right);
    b = get_number_by_pos(cur_file, left);
    put_number_by_pos(cur_file, right, b);
    put_number_by_pos(cur_file, left, a);
}

void file_qsort(FILE *cur_file, int start, int stop)
{
    if (start >= stop)
    {
        return;
    }

    int left = start;
    int right = stop;
    int cur_el;

    int mid = get_number_by_pos(cur_file, (left + right) / 2);

    while (left <= right)
    {
        cur_el = get_number_by_pos(cur_file, left);
        while (cur_el < mid)
        {
            left += 1;
            cur_el = get_number_by_pos(cur_file, left);
        }

        cur_el = get_number_by_pos(cur_file, right);
        while (cur_el > mid)
        {
            right -= 1;
            cur_el = get_number_by_pos(cur_file, right);
        }

        if (left <= right)
        {
            swap(cur_file, right, left);
            left += 1;
            right -= 1;
        }
    }

    file_qsort(cur_file, start, right);
    file_qsort(cur_file, left, stop);
}

//Вывод содержимого файла на экран
void print_file(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    int temp_num;
    while (fread(&temp_num, sizeof(int), 1, f))
    {
        printf("%d ", temp_num);
    }
}

void print_actor_pairs(FILE *cur_file, FILE *actors_file, int actor, int *position)
{
    fseek(cur_file, 0, SEEK_SET);
    int temp_actor;

    while (fread(&temp_actor, sizeof(int), 1, cur_file))
    {
        fwrite(&actor, sizeof(int), 1, actors_file);
        fwrite(&temp_actor, sizeof(int), 1, actors_file);
    }
}

int check_unic(FILE *cur_file, int num, int n)
{
    rewind(cur_file);

    if (n == 0)
    {
        return TRUE;
    }

    for (int i = 0; i < n; i++)
    {
        if (get_number_by_pos(cur_file, i + 1) == num)
        {
            return FALSE;
        }
    }
    return TRUE;
}


void make_array_actor_to_actor(int actors_films[][COUNT_OF_ELEMENTS_IN_1_C1CTION], int films_actors[][COUNT_OF_ELEMENTS_IN_1_C1CTION], FILE *actors_file)
{
    int n;
    FILE *cur_file;
    int position = 0;
    int prev_actor = actors_films[0][1];
    int cur_actor = -1;
    int cur_film = -1;
    n = 0;

    cur_file = fopen("cur_file.bin", "w+b");

    for (int el = 0; el < COUNT_OF_C1CTIONS_ACTOR_FILMS; el++)
    {
        if (el != 0)
        {
            prev_actor = cur_actor;
        }
        cur_actor = actors_films[el][1];
        if (cur_actor == 0)
        {
            fclose(cur_file);
            return;
        }
        if (prev_actor != cur_actor)
        {
            file_qsort(cur_file, 1, n);
            rewind(cur_file);
            print_actor_pairs(cur_file, actors_file, prev_actor, &position);
            fclose(cur_file);
            cur_file = fopen("cur_file.bin", "w+b");
            n = 0;
        }
        cur_film = actors_films[el][0];


        int index_for_film = search_start_index_for_film(films_actors, cur_film);

        while (films_actors[index_for_film][0] == cur_film)
        {
            if (films_actors[index_for_film][1] != cur_actor)
            {

                if (check_unic(cur_file, films_actors[index_for_film][1], n))
                {
                    n += 1;
                    fwrite(&films_actors[index_for_film][1], sizeof(int), 1, cur_file);
                }
                ++index_for_film;
             }
            else
            {
                ++index_for_film;
            }
        }
    }
    fclose(cur_file);
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
    actors_file = fopen("actors_file.bin", "rb");
    //print_file(actors_file);
    fclose(actors_file);

    return SUCCESS_EXIT;
    
}

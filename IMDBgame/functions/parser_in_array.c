/*
Создание бинарного файла следующей структуры
Actor1(4б) Film1(4б)
Actor1 Film2
Actor1 FilmN
Actor2 Film1
..
*/

#include <stdio.h>

#define FILM_DETECTED 1
#define NO_FILMS_MORE 0
#define STOP_CONDITION -1
#define SPLIT -1
#define OK 1

int find_film(FILE *f, int actor_id, int *film_id)
{
    int film_local, actor_local;
    while (fread(&film_local, sizeof(int), 1, f) == 1)
    {
        fread(&actor_local, sizeof(int), 1, f);
        while (actor_local != STOP_CONDITION)
        {
            if (actor_local == actor_id)
            {
                *film_id = film_local;
                return FILM_DETECTED;
            }
            fread(&actor_local, sizeof(int), 1, f);
        }
    }
    return NO_FILMS_MORE;
}

void till_end(FILE *f)
{
    int local;
    fread(&local, sizeof(int), 1, f);
    while (local != -1)
        fread(&local, sizeof(int), 1, f);
}

void add_signal(FILE *f)
{
    int split = SPLIT;
    fwrite(&split, sizeof(int), 1, f);
}

void fill_out(FILE *in_1, FILE *in_2, FILE *out)
{
    int actor_id, film_id;
    while (fread(&actor_id, sizeof(int), 1, in_1) == 1)
    {
        char flag = 0;
        while (find_film(in_2, actor_id, &film_id))
        {
            till_end(in_2);
            fwrite(&actor_id, sizeof(int), 1, out);
            fwrite(&film_id, sizeof(int), 1, out);
            flag = 1;
        }
        if (flag)
            add_signal(out);
        fseek(in_1, 36L, SEEK_CUR);
        rewind(in_2);
    }
}

int main(int argc, char **argv)
{
    FILE *f_id_name = fopen(argv[1], "rb");
    FILE *f_film_actors = fopen(argv[2], "rb");
    FILE *out = fopen(argv[3], "wb");
    fill_out(f_id_name, f_film_actors, out);
    fclose(f_id_name);
    fclose(f_film_actors);
    fclose(out);
    return OK;
}

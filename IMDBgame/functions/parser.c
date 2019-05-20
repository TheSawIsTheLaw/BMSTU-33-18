// NEVER WRITE PARSERS IN C
#define FILE_NAMES "../data/name_basic-test.tsv"
#define FILE_PRINCIPALS "../data/title_principals-test.tsv"
#include <stdio.h>
#include "node.h"

#define N 200
#define STD_SHIFT 3
#define NAMES_PARS 74
#define CONNECTIONS_PARS 49
#define FILE_ERR 1
#define OK 0

// 2. THIS BLOCK PARS CONNECTIONS 

void shift_to_id_film(FILE *f)
{
    char shift_arr[N];
    int i = 0;
    while (i < STD_SHIFT - 1)
    {
        fscanf(f, "%s", shift_arr);
        ++i;
    }

    i = 0; 
    do
        if (fscanf(f, "%c", &shift_arr[i]) != EOF)
        {
            ++i;
        }
        else
        {
            return;
        }
    while (shift_arr[i - 2] != 't' || shift_arr[i - 1] != 't');
}

void shift_to_id_act(FILE *f)
{
    char shift_arr[N];
    fscanf(f, "%s", shift_arr);
    int i = 0;
    char tmp;
    while (i < STD_SHIFT) // FSEEK
    {
        fscanf(f, "%c", &tmp);
        ++i;
    }
}

int pars_films(FILE *f, int *arr, const int i)
{
    int len = 0;
    int film_id, actor_id;
    while (!feof(f))
    {
        fscanf(f, "%d", &film_id);
        shift_to_id_act(f);
        fscanf(f, "%d", &actor_id);

        if (graph[i].id == actor_id)
        {
            arr[len] = film_id;
            ++len;
        }
        shift_to_id_film(f);
    }

    return len;
}

int check_repeat(const int i, int j, const int actor_id)
{
    int len = graph[i].len;
    int checker = 0;

    for (int k = 0; k < len; k++)
    {
        if (graph[i].connection[k] == actor_id)
        {
            return j;
        }
    }

    graph[i].connection[j] = actor_id;
    graph[i].len += 1;
    return ++j;
}

void add_connections(FILE *f, const int i, const int film_id)
{
    int j = 0;
    int temp_film_id, actor_id;
    while (!feof(f)) 
    {
        shift_to_id_act(f);
        fscanf(f, "%u", &actor_id);
        if (actor_id != graph[i].id)
        {
            j = check_repeat(i, j, actor_id);
        }
        shift_to_id_film(f);
        fscanf(f, "%d", &temp_film_id);
        if (temp_film_id != film_id)
        {
            return;
        }
    }
}

void find_connections(FILE *f, int *arr, const int len, const int i)
{
    fseek(f, CONNECTIONS_PARS, SEEK_SET);
    int film_id;
    fscanf(f, "%d", &film_id);
    for (int j = 0; j < len; j++)
    {
        if (film_id == arr[j])
        {
            add_connections(f, i, film_id);
        }
    }
}

void pars_connections(FILE *f, const int i)
{
    int arr_films[N];
    int len = pars_films(f, arr_films, i);
    find_connections(f, arr_films, len, i);
}
// END BLOCK 2


// 1. THIS BLOCK PARSING NAMES + ID

void shift_to_name(FILE *f, const int i)
{
    char check_symb = ' ';
    while (check_symb == ' ')
    {
        fscanf(f, "%c", &check_symb);
    }
    graph[i].name[0] = check_symb;
}

void shift_to_id(FILE *f)
{
    char arr_check[N];
    while (arr_check[0] != 't' || arr_check[1] != 't')
    {
        fscanf(f, "%s", arr_check);
    }

    char check_symb; // FSEEK ! 
    int i = 0;
    while (i < STD_SHIFT)
    {
        fscanf(f, "%c", &check_symb);
        ++i;
    }
}

void pars_id(FILE *f, const int i)
{
    fscanf(f, "%u", &graph[i].id);
}

void pars_name(FILE *f, const int i)
{
    shift_to_name(f, i);
    char pars_name[32];
    int j = 0;
    pars_name[j] = '0';
    while (graph[i].name[j - 1] != '1' && graph[i].name[j - 1] != '2' && graph[i].name[j - 1] != 92)
    {
        fscanf(f, "%c", &graph[i].name[j]);
        ++j;
    }
    graph[i].name[j - 1] = '\0';
    shift_to_id(f);
}
// END BLOCK 1.

int parser()
{
    FILE *f;
    if ((f = fopen(FILE_NAMES, "r")) == NULL)
    {
        return FILE_ERR;
    }

    // BLOCK 1: PARS NAMES AND ID 
    fseek(f, NAMES_PARS, SEEK_SET);
    int count_people = 0;
    while (!feof(f))
    {
        pars_id(f, count_people);
        pars_name(f, count_people);
        ++count_people;
    }
    fclose(f);

    if ((f = fopen(FILE_PRINCIPALS, "r")) == NULL)
    {
        return FILE_ERR;
    }

    // BLOCK 2: PARS CONNECTIONS
    for (int i = 0; i < count_people; i++)
    {
        fseek(f, CONNECTIONS_PARS, SEEK_SET);
        pars_connections(f, i);
    }
    fclose(f);

    return OK;
}

int main(void)
{
    setbuf(stdout, NULL);
    int a = parser();
    
    for (int i = 0; i < 7; i++)
    {
        printf("Actor id: %u\n", graph[i].id);
        printf("Actor name: %s\n", graph[i].name);
        puts("Actor connections: ");
        if (0 == graph[i].len)
        {
            puts("No connections");
        }
        for (int j = 0; j < graph[i].len; j++)
        {
            printf("%d. %d\n", j, graph[i].connection[j]);
        }
        puts("\n--------------------------");
    } 
    
    return OK;
}
    

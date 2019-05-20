// NEVER WRIE PARSERS IN C
#define FILE_NAMES "../data/name_basic-test.tsv"
#define FILE_PRINCIPALS "../data/title_principals-test.tsv"
#include <stdio.h>
#include "node.h"

#define N 200
#define STD_SHIFT 3
#define START_PARS 74
#define FILE_ERR 1
#define OK 0

// 2. THIS BLOCK PARS CONNECTIONS 

void shift_to_id_act(FILE *f)
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

void shift_to_id_film(FILE *f)
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
    int film_id;
    int actor_id;
    while (!feof(f))
    {
        fscanf(f, "%d", &film_id);
        shift_to_id_film(f);
        fscanf(f, "%d", &actor_id);
        if (graph[i].id == actor_id)
        {
            arr[len] = film_id;
            ++len;
        }
        shift_to_id_act(f);
    }

    return len;
}

void pars_connections(FILE *f, const int i)
{
    int arr_films[N];
    int len = pars_films(f, arr_films, i);
    for (int j = 0; j < len; j++)
    {
        printf("%d ", arr_films[j]);
    }
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
    //puts(graph[i].name);
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
    fseek(f, START_PARS, SEEK_SET);
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
        fseek(f, 49, SEEK_SET);
        pars_connections(f, i);
    }
    fclose(f);

    return OK;
}

int main(void)
{
    setbuf(stdout, NULL);
    int a = parser();
    return OK;
}
    

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

void pars_id(FILE *f, const int i)
{
    fscanf(f, "%u", &graph[i].id);
}

void shift_to_name(FILE *f, const int i)
{
    char check_symb = ' ';
    while (check_symb == ' ')
    {
        fscanf(f, "%c", &check_symb);
    }
    graph[i].name[0] = check_symb;
}

// DEVELOPING 
void shift_to_film(FILE *f)
{
    char shift_arr[N];
    int i = 0;
    while (i < STD_SHIFT - 1)
    {
        fscanf(f, "%s", shift_arr);
        ++i;
    }

    i = 0; 
    while (shift_arr[i] != 't' || shift_arr[i + 1] != 't')
    {
        if (fscanf(f, "%c", &shift_arr[i]) != EOF)
        {
            //puts(shift_arr);
            ++i;
        }
        else
        {
            break;
        }
    }
}

void shift_to_id_f(FILE *f)
{
    char shift_arr[N];
    fscanf(f, "%s", shift_arr);
    fseek(f, 2, SEEK_CUR);
}

int pars_films(FILE *f, int *arr, const int i)
{
    int len = 0;
    int film_id;
    int actor_id;
    while (!feof(f))
    {
        fscanf(f, "%d", &film_id);
        shift_to_id_f(f);
        fscanf(f, "%d", &actor_id);
        if (graph[i].id == actor_id)
        {
            arr[len] = film_id;
            //printf("%d", arr[len]);
            ++len;
        }
        shift_to_film(f);
    }

    return len;
}

void pars_connections(FILE *f, const int i)
{
    int arr_films[N];
    int len = pars_films(f, arr_films, i);
    //fscanf(f, "%s", x);
    //puts(x);
}


void shift_to_id(FILE *f)
{
    char arr_check[N];
    while (arr_check[0] != 't' || arr_check[1] != 't')
    {
        fscanf(f, "%s", arr_check);
    }

    char check_symb; // NEED TO CHANGE FOR FSEEK (SOON)
    int i = 0;
    while (i < STD_SHIFT)
    {
        fscanf(f, "%c", &check_symb);
        ++i;
    }
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

int parser()
{
    FILE *f;
    if ((f = fopen(FILE_NAMES, "r")) == NULL)
    {
        return FILE_ERR;
    }

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
    fseek(f, 91, SEEK_SET);
    for (int i = 0; i < count_people; i++)
    {
        // PARS FOR CONNECTIONS HERE (SOON)
        pars_connections(f, i);
        return OK;
    }

    return OK;
}

int main(void)
{
    setbuf(stdout, NULL);
    int a = parser();
    return OK;
}
    

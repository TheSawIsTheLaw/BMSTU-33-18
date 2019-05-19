#define FILE_NAME "../data/name_basic-test.tsv"
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
/*
void pars_connection(FILE *f, const int i, char *connections)
{
    char connections[N];
    fscanf(f, "%s", connections);
    puts(connections);
}
*/

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
    if ((f = fopen(FILE_NAME, "r")) == NULL)
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

    for (int i = 0; i < count_people; i++)
    {
        // PARS FOR CONNECTIONS HERE (SOON)
        return OK;
    }

    return OK;
}

/* FOR TESTING
int main(void)
{
    setbuf(stdout, NULL);
    int a = parser();
    return OK;
}
*/
    

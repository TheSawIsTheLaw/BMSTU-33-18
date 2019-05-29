// NEVER WRITE PARSERS IN C
#define FILE_NAMES "../data/name_basic-test.tsv"
#define FILE_PRINCIPALS "../data/title_principals-test.tsv"
#define GRAPH_NAMES "../data/graph_id_names.txt"
#define GRAPH_CONNECT "../data/graph_connect.txt"
#include <stdio.h>

#define N 200
#define STD_SHIFT 3
#define NAMES_PARS 75
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

void add_connections(FILE *f, FILE *f1, const unsigned int film_id, const unsigned int self_id)
{
    unsigned int temp_film_id, actor_id;
    while (!feof(f)) 
    {
        shift_to_id_act(f);
        if (fscanf(f, "%u", &actor_id) != 1)
        {
            return;
        }
        if (actor_id != self_id)
        {
            fprintf(f1, "%u,", actor_id);
            printf("Actor connect ID: %u\n", actor_id);
        }

        shift_to_id_film(f);
        if (fscanf(f, "%u", &temp_film_id) != 1)
        {
            return;
        }
        if (temp_film_id != film_id)
        {
            return;
        }
    }
}

int pars_films(FILE *f, int *arr, unsigned int self_id)
{
    int len = 0;
    unsigned int film_id, actor_id;
    while (!feof(f))
    {
        if (fscanf(f, "%u", &film_id) == 1)
        {
            shift_to_id_act(f);
        }
        if (fscanf(f, "%u", &actor_id) != 1)
        {
            return len;
        }

        if (self_id == actor_id)
        {
            arr[len] = film_id;
            ++len;
        }
        shift_to_id_film(f);
    }

    return len;
}

void pars_connections(FILE *f, FILE *f1, const unsigned int self_id)
{
    int arr_films[N];
    printf("User ID: %u\n", self_id);
    int len = pars_films(f, arr_films, self_id);
    unsigned int film_id; 
    fseek(f, CONNECTIONS_PARS, SEEK_SET);
    fscanf(f, "%u", &film_id);
    printf("Film ID: %u\n", film_id);
    for (int j = 0; j < len; j++)
    {
        if (film_id == arr_films[j])
        {
            add_connections(f, f1, film_id, self_id);
        }
    }
    fprintf(f1, "%c", '\n');
}
// END BLOCK 2


// 1. THIS BLOCK PARSING NAMES + ID

void shift_to_name(FILE *f)
{
    char check_symb = ' ';
    while (check_symb == ' ')
    {
        fscanf(f, "%c", &check_symb);
    }
    fseek(f, -1, SEEK_CUR);
}

void shift_to_id(FILE *f)
{
    char arr_check[N];
    while (arr_check[0] != 't' || arr_check[1] != 't')
    {
        if (fscanf(f, "%s", arr_check) != 1)
        {
            return;
        }
    }

    char check_symb; // FSEEK ! 
    int i = 0;
    while (i < STD_SHIFT)
    {
        fscanf(f, "%c", &check_symb);
        ++i;
    }
}

void pars_id(FILE *f, FILE *f1)
{
    unsigned int id;
    fscanf(f, "%u", &id);
    fprintf(f1, "%u ", id);
    printf("%u\n", id);
}

void pars_name(FILE *f, FILE *f1)
{
    shift_to_name(f);
    char pars_name[120];
    int j = 0;
    do
    {
        fscanf(f, "%c", &pars_name[j]);
        ++j;
    }
    while (pars_name[j - 1] != '1' && pars_name[j - 1] != '2' && pars_name[j - 1] != 92);
    pars_name[j - 2] = '\0';
    puts(pars_name);

    fprintf(f1, "%s ", pars_name);
    shift_to_id(f);
}
// END BLOCK 1.

int parser()
{
    FILE *f, *f1;
    if ((f = fopen(FILE_NAMES, "r")) == NULL)
    {
        puts("File names err");
        return FILE_ERR;
    }
    if ((f1 = fopen(GRAPH_NAMES, "w")) == NULL)
    {
        puts("File graph err");
        return FILE_ERR;
    }

    // BLOCK 1: PARS NAMES AND ID 
    fseek(f, NAMES_PARS, SEEK_SET);
    int count_people = 0;
    while (!feof(f))
    {
        pars_id(f, f1);
        pars_name(f, f1);
        ++count_people;
        fprintf(f1, "%c", '\n');
    }
    fclose(f);
    fclose(f1);
    puts("Names pars OK.");

    if ((f = fopen(FILE_PRINCIPALS, "r")) == NULL)
    {
        puts("File principals error");
        return FILE_ERR;
    }
    if ((f1 = fopen(GRAPH_CONNECT, "w")) == NULL)
    {
        puts("Graph connect file error");
        return FILE_ERR;
    }

    // BLOCK 2: PARS CONNECTIONS
    ++count_people;
    for (int i = 1; i < (count_people); i++)
    {
        fseek(f, CONNECTIONS_PARS, SEEK_SET);
        pars_connections(f, f1, i);
    }
    fclose(f);
    fclose(f1);

    return OK;
}

int main(void)
{
    setbuf(stdout, NULL);
    int code = parser();
    if (code)
    {
        printf("Code error: %d", code);
        return code;
    }
    puts("All ok!");
    return OK;
}
    

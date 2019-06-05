#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 0

#define N 1000
#define ID_SIZE 16
#define TAB 9
#define COUNT 9336192
#define FILMS 33766111
//#define COUNT 7
//#define FILMS 7

void readline(FILE *const f, char *const line)
{
    int i = -1;
    do
    {
        ++i;
        fscanf(f, "%c", &line[i]);
    }
    while (line[i] != '\n');
    line[i] = '\0';
}

void pars_f2(FILE *const f2, const char *const id, const char *const line)
{
    int i = 0; 
    char id_film[ID_SIZE] = { '\0' };
    while (line[i] != TAB)
    {
        id_film[i] = line[i];
        ++i;
    }
    id_film[i] = '\0';
    ++i;
    
    while (line[i] != TAB)
    {
        ++i;
    }
    ++i;

    char id_check[ID_SIZE];
    int j = 0;
    while (line[i] != TAB && line[i] != ' ')
    {
        id_check[j] = line[i];
        ++j;
        ++i;
    }
    id_check[j] = '\0';

    if (!strcmp(id_check, id))
    {
        unsigned int num_film_id  = atoi(&id_film[2]);
        fprintf(f2, "%u", num_film_id);
        printf("%u ", num_film_id);
        fprintf(f2, "%c", ',');
    }
}

void find_films(FILE *const f1, FILE *const f2, const char *const line)
{
    int i = 0;
    char id_str[ID_SIZE] = { '\0' };
    while (line[i] != TAB)
    {
        id_str[i] = line[i];
        ++i;
    }
    id_str[i] = '\0';
    unsigned int id = atoi(&id_str[2]);
    printf("\nID: %u | ", id);
    fprintf(f2, "%u ", id);

    char line_f1[N] = { '\0' };
    for (int i = 0; i < FILMS; i++)
    {
        readline(f1, line_f1);
        pars_f2(f2, id_str, line_f1);
    }
}

int main(const int argc, const char *const argv[])
{
    setbuf(stdout, NULL);
    FILE *f, *f1, *f2;
    char line[N];

    f = fopen(argv[1], "r");
    f1 = fopen(argv[2], "r");
    f2 = fopen(argv[3], "w");

    for (int i = 0; i < 2; i++)
    {
        readline(f, line);
        find_films(f1, f2, line);
        rewind(f1);
        fprintf(f2, "%c", '\n');
    }
    
    puts("\nPars ok");
    return OK;
}

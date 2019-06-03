#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define N 400
#define TAB 9
#define ID_SIZE 16
#define NAME_SIZE 100
#define COUNT 9336192
#define OK 0

void pars_to_file(FILE *const f1, const char *const line)
{
    char id_str[ID_SIZE] = { '\0' }; 
    int i = 2;
    while (line[i] != TAB)
    {
        id_str[i - 2] = line[i];
        ++i;
    }
    id_str[i] = '\0';
    unsigned int id = atoi(id_str);
    fprintf(f1, "%u", id);
    printf("\nID %u | NAME: ", id);

    char name[NAME_SIZE] = "";
    do
    {
        printf("%s ", name);
        fprintf(f1, "%s ", name);
        ++i;
        int j = 0;
        while(line[i] != ' ' && line[i] != TAB)
        {
            name[j] = line[i];
            ++j;
            ++i;
        }
        name[j] = '\0';
    } while (name[0] != '\\' && !isdigit(name[0]));
    fprintf(f1, "%c", '\n');
}

void readline(FILE *const f, FILE *const f1)
{
    char line[N];
    int i = -1;
    do
    {
        ++i;
        fscanf(f, "%c", &line[i]);
    }
    while (line[i] != '\n');
    line[i] = '\0';
    pars_to_file(f1, line);
}

int main(int argc, char  *argv[])
{
    setbuf(stdout, NULL);
    FILE *f, *f1;

    f = fopen(argv[1], "r");
    f1 = fopen(argv[2], "w");

    for (int i = 0; i < COUNT; i++)
    {
        readline(f, f1);
    }
    
    printf("\nPars end");
    return  OK;
}


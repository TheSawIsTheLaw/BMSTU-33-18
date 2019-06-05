#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define N 400
#define MX_NAME 36
#define TAB 9
#define ID_SIZE 16
#define NAME_SIZE 100
#define COUNT 9336192
#define OK 0

void pars_to_file(FILE *const f1, char *const line)
{
    unsigned int check_id;
    line[9] = '\0';
    unsigned int id = atoi(&line[2]);
    fwrite(&id, sizeof(unsigned int), 1, f1); 

    int i = 9;
    char name[NAME_SIZE] = { '\0' };
    char full_name[NAME_SIZE] = { '\0' };
    do
    {
        strcat(full_name, name); 
        ++i;
        int j = 0;
        while(line[i] != ' ' && line[i] != TAB)
        {
            name[j] = line[i];
            ++j;
            ++i;
        }

        name[j] = ' ';
        name[++j] = '\0';
    } while (name[0] != '\\' && !isdigit(name[0]));

    full_name[35] = '\0';
    fwrite(&full_name, MX_NAME, 1, f1);
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
    f1 = fopen(argv[2], "wb+");

    for (int i = 0; i < COUNT; i++)
    {
        readline(f, f1);
    }
    
    printf("\nPars end");
    return  OK;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000
#define TAB 9
#define M 40
#define COUNT 9916880
#define FILMS 5906049

#define OK 0

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

void pars_line(FILE *const f1, char *const line, int *counter)
{
    line[9] = '\0';
    unsigned int id = atoi(&line[2]);
    int i = 9;
    
    char type[M];
    int j = 0;
    do
    {
        i++; 
        type[j] = line[i];
        ++j;
    }
    while (line[i] != TAB && line[i] != ' ');
    type[j - 1] = '\0';

    unsigned int tf = 1;
    if (!strcmp(type, "movie"))
    {
        fseek(f1, id * sizeof(unsigned int) - sizeof(unsigned int), SEEK_SET);
        fwrite(&tf, sizeof(tf), 1, f1);
        ++(*counter);
    }
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    FILE *f1 = fopen(argv[2], "wb");
    char line[N];
    unsigned int tf = 0;

    for (int i = 0; i < COUNT; i++)
    {
        printf("%d\n", i);
        fwrite(&tf, sizeof(tf), 1, f1);
    }

    int counter = 0;
    for (int i = 0; i < FILMS; i++)
    {
        readline(f, line);
        pars_line(f1, line, &counter);
    }
    printf("\nTotaly films: %d\n", counter);

    fclose(f);
    fclose(f1);

    puts("Pars OK");
    return OK;
}

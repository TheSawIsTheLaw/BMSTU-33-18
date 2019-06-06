#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 0

#define N 1000
#define ID_SIZE 16
#define TAB 9
#define COUNT 33766111


int fst_check = 0;
//int counter = 0;

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

void find_films(FILE *const f1, FILE *const f2, const char *const line, char *const checker)
{
    int i = 0;
    char id_str[ID_SIZE] = { '\0' };
    char actor_id[ID_SIZE] = { '\0' };
    while (line[i] != TAB)
    {
        id_str[i] = line[i];
        ++i;
    }
    id_str[i] = '\0';
    
    int id = atoi(&id_str[2]);
    fseek(f1, id * sizeof(id) - sizeof(id), SEEK_SET);
    int tf_ch;
    fread(&tf_ch, sizeof(tf_ch), 1, f1);
    if (!tf_ch)
    {
        return;
    }
    
    int end_f = -1;
    if (strcmp(checker, id_str))
    {
        /*
        counter++;
        if (counter > 10000)
        {
            int end_f = -1;
            fwrite(&end_f, sizeof(end_f), 1, f2);
            exit(0);
        }
        */
        if (fst_check)
        {
            fwrite(&end_f, sizeof(end_f), 1, f2);
        } 
        fwrite(&id, sizeof(id), 1, f2);
        fst_check++;
    }

    i = 10;
    while (line[i] != TAB && line[i] != ' ')
    {
        ++i;
    }
    ++i;
    
    int j = 0;
    while (line[i] != TAB && line[i] != ' ')
    {
       actor_id[j] = line[i]; 
       ++i;
       ++j;
    }
    actor_id[j] = '\0';

    int act_id_int  = atoi(&actor_id[2]);
    fwrite(&act_id_int, sizeof(act_id_int), 1, f2);

    strcpy(checker, id_str);
}

int main(const int argc, const char *const argv[])
{
    setbuf(stdout, NULL);
    FILE *f, *f1, *f2;
    char line[N];
    char checker[N] = { '\0' };

    f = fopen(argv[1], "r");
    f1 = fopen(argv[2], "rb");
    f2 = fopen(argv[3], "w+b");

    for (int i = 0; i < COUNT; i++)
    {
        readline(f, line);
        find_films(f1, f2, line, checker);
    }
    int end_f = -1;
    fwrite(&end_f, sizeof(end_f), 1, f2);
    
    puts("\nPars ok");
    return OK;
}

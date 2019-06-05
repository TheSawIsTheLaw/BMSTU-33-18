#include <stdio.h>

#define OK 0
#define FILE_NOT_EXIST_ERROR -1
#define EMPTY_FILE_ERROR -2
#define FILE_ERROR -3
#define WRONG_ARG -4

#define GOT_ARG 1

#define ACTOR_NAME_LEN 37

typedef struct actor
{
    unsigned int id;
    char name[ACTOR_NAME_LEN];
} actor_t;

void print_struct(const actor_t actor)
{
    printf("%d\n%s\n\n\n", actor.id, actor.name);
}

int get_struct_file_size(FILE *const f)
{
    int size = 0;

    fseek(f, 0, SEEK_END);
    size = ftell(f) / sizeof(actor_t);
    fseek(f, 0, SEEK_SET);

    return size;
}

int check_file(FILE *const f)
{
    actor_t cur_actor;

    if (!f)
        return FILE_NOT_EXIST_ERROR;

    int size = get_struct_file_size(f);

    fseek(f, 0, SEEK_SET);

    if (size == 0)
        return EMPTY_FILE_ERROR;

    for (int i = 0; i < size; ++i)
    {
        if (fread(&cur_actor, sizeof(actor_t), 1, f) != GOT_ARG)
        {
            fseek(f, 0, SEEK_SET);

            return WRONG_ARG;
        }
    }

    fseek(f, 0, SEEK_SET);

    return OK;
}

void print_file(FILE *const f)
{
    fseek(f, 0, SEEK_SET);

    int size = get_struct_file_size(f);
    actor_t actor;

    for (int i = 0; i < size; ++i)
    {
        fread(&actor, sizeof(actor_t), 1, f);
        print_struct(student);
    }
}

void get_actor_by_pos(FILE *const f, const int pos, actor_t *const get_actor)
{
    fseek(f, pos * sizeof(actor_t), SEEK_SET);
    fread(get_actor, sizeof(actor_t), 1, f);
}

void put_actor_by_pos(FILE *const f, const int pos, const actor_t put_actor)
{   
    fseek(f, pos * sizeof(actor_t), SEEK_SET);
    fwrite(&put_actor, sizeof(actor_t), 1, f);
}


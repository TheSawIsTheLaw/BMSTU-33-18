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
    printf("%d %s\n\n", actor.id, actor.name);
}

int get_struct_file_size(FILE *const f)
{
    int size = 0;

    fseek(f, 0, SEEK_END);
    size = ftell(f) / sizeof(actor_t);
    fseek(f, 0, SEEK_SET);

    return size;
}

void print_file(FILE *const f)
{
    fseek(f, 0, SEEK_SET);

    int size = get_struct_file_size(f);
    actor_t actor;

    for (int i = 0; i < size; ++i)
    {
        fread(&actor, sizeof(actor_t), 1, f);
        print_struct(actor);
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

void sort_file(FILE *const f, const unsigned int first, const unsigned int last)
{
    unsigned int i, j, pivot;
    actor_t f_actor, s_actor, p_actor;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i < j)
        {
            get_actor_by_pos(f, i, &f_actor);
            get_actor_by_pos(f, j, &s_actor);
            get_actor_by_pos(f, pivot, &p_actor);

            while(f_actor.id <= p_actor.id && i < last)
            {
                i++;
                get_actor_by_pos(f, i, &f_actor);
            }

            while(s_actor.id > p_actor.id)
            {
                j--;
                get_actor_by_pos(f, j, &s_actor);
            }
            
            if (i < j)
            {
                put_actor_by_pos(f, i, s_actor);
                put_actor_by_pos(f, j, f_actor);
            }
        }

        put_actor_by_pos(f, pivot, s_actor);
        put_actor_by_pos(f, j, p_actor);

        sort_file(f, first, i - 1);
        sort_file(f, j + 1, last);
    }
}

/*void fill_binary_file(FILE *const f)
{
    actor_t a1 = { 13211, "Roman Alexeev" };
    actor_t a2 = { 675, "Kovaliy Dmitriev" };
    actor_t a3 = { 13, "Koney Sergienko" };
    actor_t a4 = { 454111, "Pablo Pepperoni" };

    fwrite(&a1, sizeof(actor_t), 1, f);
    fwrite(&a2, sizeof(actor_t), 1, f);
    fwrite(&a3, sizeof(actor_t), 1, f);
    fwrite(&a4, sizeof(actor_t), 1, f);
}*/

int main(int argc, char **argv)
{
    FILE *f_in = NULL;

    /*f_in = fopen(argv[1], "wb");
    fill_binary_file(f_in);
    fclose(f_in);*/

    f_in = fopen(argv[1], "rb+");
    sort_file(f_in, 0, 10);
    print_file(f_in);
    fclose(f_in);

    return OK;
}
#define OK 0

#define ACTOR_NAME_LEN 36

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

void sort_file_id_name(FILE *const f, const unsigned int first, const unsigned int last)
{
    unsigned int i, j, pivot;
    actor_t f_actor, s_actor, p_actor;

    if (first < last)
    {
        pivot = (first + last) / 2;
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

        sort_file_id_name(f, first, i - 1);
        sort_file_id_name(f, j + 1, last);
    }
}

void remove_duplicates(FILE *const f_from, FILE *const f_to)
{
    int cur_id = -1;
    actor_t cur_actor;

    int size = get_struct_file_size(f_from);

    for (int i = 0; i < size; ++i)
    {
        get_actor_by_pos(f_from, i, &cur_actor);
        if (cur_actor.id != cur_id)
            fwrite(&cur_actor, sizeof(actor_t), 1, f_to);
        cur_id = cur_actor.id;
    }
}

void check_duplicates(FILE *const f)
{
    int cur_id = -1, duplicate_count = 0;
    actor_t cur_actor;

    int size = get_struct_file_size(f);

    for (int i = 0; i < size; ++i)
    {
        get_actor_by_pos(f, i, &cur_actor);
        if (cur_actor.id == cur_id)
            duplicate_count++;
        cur_id = cur_actor.id;
    }

    if (!duplicate_count)
        printf("No duplicates found\n\n");
    else
        printf("%d duplicates found\n\n", duplicate_count);
}
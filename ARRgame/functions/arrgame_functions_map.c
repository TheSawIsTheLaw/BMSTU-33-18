#include <stdlib.h>
#include "../headers/arrgame_headers_map.h"

#define SIZE_ADRS -3

typedef struct 
{
    void (*f) (int *);
    int *arr;
    int start;
    int end;
} args_t;

static void map_thread(args_t *args)
{
    for (int *i = args->arr + args->start; i < args->arr + args->end; i++)
    {
        args->f(i);
    }
}

void map(void (*f) (int *), int *arr)
{ 
    if (f == NULL || arr == NULL)
    {
        return;
    }

    args_t args;

    args.f = f;
    args.arr = arr; 
    args.start = 0;
    args.end =  *(arr + SIZE_ADRS);

    map_thread(&args);
}



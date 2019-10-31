#include <stdlib.h>
#include <stdio.h>
#include "../headers/arrgame.h"

#define SIZE_ADRS -3

typedef struct
{
    void (*f) (int *);
    int *arr;
    int end;
} args_t;

static void map_thread(args_t *args)
{
    for (int i = 0; i < args->end ; i++)
    {
        args->f((args->arr) + i);
    }
}

void arrgame_map(void (*f) (int *), int *arr)
{
    if (f == NULL || arr == NULL)
    {
        fprintf(stderr, "Error: pointers should be != NULL.\n");
        return;
    }

    args_t args;
    args.f = f;
    args.arr = arr;
    args.end =  *(arr + SIZE_ADRS);

    map_thread(&args);
}

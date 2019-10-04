#include <stdlib.h>
#include <stdio.h>
//#include <omp.h>

#include "../headers/arrgame.h"

#define  SIZE_ADRS -3

typedef struct
{
    int (*f) (int, int);
    int *arr;
    int end;
} args_t;

static int reduce_thread(args_t *args)
{
    int acc = 0;

    //#pragma omp parallel for reduction (+ : acc)
    for (int i = 0; i < args->end; i++)
    {
        acc = args->f(acc, *((args->arr) + i));
    }

    return acc;
}

int arrgame_reduce(int (*f) (int, int), int *arr)
{
    if (f == NULL || arr == NULL)
    {
        fprintf(stderr, "Error: pointers should be != NULL.\n");
        return 0;
    }

    args_t args;
    args.f = f;
    args.arr = arr;
    args.end = *(arr + SIZE_ADRS);

    return reduce_thread(&args);
}

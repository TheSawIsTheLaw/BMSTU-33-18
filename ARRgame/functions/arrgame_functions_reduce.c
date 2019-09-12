#include <stdlib.h>
#include <omp.h>
#include "../headers/arrgame_headers_reduce.h"

#define  SIZE_ADRS -3

typedef struct 
{
    int (*f) (int, int);
    int *arr;
    int end;
} args_t;

static int foo(int acc, int x)
{
    return acc + x;
}

static int reduce_thread(args_t *args)
{
    int acc = 0;
    
    #pragma omp parallel for reduction (+ : acc)
    for (int i = 0; i < args->end; i++)
    {
        acc = args->f(acc, *((args->arr) + i));
    }
    
    return acc;
}
    
int reduce(int (*f) (int, int), int *arr)
{
    if (f == NULL || arr == NULL)
    {
        return 0;
    }

    args_t args;
    args.f = f;
    args.arr = arr;
    args.end = *(arr + SIZE_ADRS);

    return reduce_thread(&args);
}


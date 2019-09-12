#include <stdlib.h>
#include "../headers/arrgame_headers_reduce.h"

#define  SIZE_ADRS -3

typedef struct 
{
    int (*f) (int, int);
    int *arr;
    int start;
    int end;
} args_t;

static int reduce_thread(args_t *args)
{
    int acc = 0;

    for (int *i = args->arr + args->start; i < args->arr + args->end; i++)
    {
        acc = args->f(acc, *i);
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
    args.start = 0;
    args.end = *(arr + SIZE_ADRS);

    return reduce_thread(&args);
}


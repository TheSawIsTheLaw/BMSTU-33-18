#include <stdlib.h>
#include "../headers/arrgame_headers_filter.h"

#define SIZE_ADRS -3

typedef struct 
{
    int (*f) (int);
    int *arr;
    int start;
    int end;
} args_t;

static void shift (int *arr_start, int *arr, int arr_end)
{
    for (int *i = arr_start; i < arr + (arr_end - 1); i++)
    {
        *i = *(i + 1);
    }
}

static int filter_thread(args_t *const args)
{
    short int remove_size = 0;

    for (int *i = args->arr + args->start; i < args->arr + args->end; i++)
    {
        if (!args->f(*i))
        {
            shift(i, args->arr, args->end);
            i--;
            args->end--;
            remove_size++;
        }
    }

    return remove_size;
}


void filter(int (*f) (int), int *arr)
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

    *(arr + SIZE_ADRS) -= filter_thread(&args);
}


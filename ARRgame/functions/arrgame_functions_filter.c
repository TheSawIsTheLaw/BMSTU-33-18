#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "../headers/arrgame_headers_filter.h"

#define SIZE_ADRS -3
#define FULLNESS_ADRS -1

typedef struct 
{
    int (*f) (int);
    int *arr;
    int end;
} args_t;

static void shift(int start, int end, int *const arr)
{
    for (int j = start; j < end - 1; j++)
    {
        *(arr + j) = *(arr + j + 1);
    }
}

static int filter_thread(args_t *const args)
{
    short int remove_size = 0;

    for (int i = 0; i < args->end; i++)
    {
        if (!args->f(*(args->arr + i)))
        {
            shift(i, args->end, args->arr);
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
        puts("INVALID DATA, TRY AGAIN!");
        return;
    }

    args_t args;
    args.f = f;
    args.arr = arr; 
    args.end =  *(arr + SIZE_ADRS);

    *(arr + SIZE_ADRS) -= filter_thread(&args);
    *(arr + FULLNESS_ADRS) = *(arr + SIZE_ADRS);
}


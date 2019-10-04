#include <stdio.h>
#include <stdlib.h>

#include "../headers/arrgame.h"

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

void arrgame_filter(int (*f) (int), int *arr)
{
    if (f == NULL || arr == NULL)
    {
        fprintf(stderr, "Error: pointers must be != NULL.\n");
        return;
    }

    args_t args;
    args.f = f;
    args.arr = arr;
    args.end =  *(arr + SIZE_ADRS);

    *(arr + SIZE_ADRS) -= filter_thread(&args);
    *(arr + FULLNESS_ADRS) = *(arr + SIZE_ADRS);
}

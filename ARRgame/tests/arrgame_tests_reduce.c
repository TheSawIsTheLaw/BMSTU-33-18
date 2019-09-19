#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define  SIZE_ADRS -3

#define META_DATA 3

void *create(int size)
{
    int *arr = calloc(size * 2 + META_DATA, sizeof(int));

    if (arr == NULL)
    {
        puts("ERROR, TRY AGAIN!");
        return NULL;
    }

    *arr = size;
    *(arr + 1) = size * 2;
    *(arr + 2) = 0;

    return arr + 3;
}


typedef struct
{
    int (*f) (int, int);
    int *arr;
    int end;
} args_t;

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
        puts("INVALID DATA, TRY AGAIN!");
        return 0;
    }

    args_t args;
    args.f = f;
    args.arr = arr;
    args.end = *(arr + SIZE_ADRS);

    return reduce_thread(&args);
}

int max(int acc, int elem)
{
    return (elem > acc) ? elem : acc;
}

int sum(int acc, int elem)
{
    return acc + elem;
}

void test_reduce(void)
{
    int *arr_one = create(2);
    int *arr_two = create(100);
    int *arr_three = create(100000);
    int err_counter = 0;
    int acc;

    // Тест 1
    for (int i = 0; i < 2; i++)
    {
        *(arr_one + i) = i;
    }
    acc = reduce(max,arr_one);
    if (acc != 1)
    {
        err_counter++;
    }

    // Тест 2
    for (int i = 0; i < 100; i++)
    {
        *(arr_two + i) = 1;
    }
    acc = reduce(sum, arr_two);
    if (acc != 100)
    {
        err_counter++;
    }

    //Тест 3
    for (int i = 0; i < 100000; i++)
    {
        *(arr_three + i) = 1;
    }
    acc = reduce(sum, arr_three);
    if (acc != 100000)
    {
        err_counter++;
    }


    printf("Error test of REDUCE function : %s\n", err_counter ? "FAILED" : "OK");

}

int main()
{
    test_reduce();
    return 0;
}

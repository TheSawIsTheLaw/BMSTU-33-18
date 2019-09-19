#include <stdio.h>
#include <stdlib.h>

#define META_DATA 3

#define SIZE_ADRS -3


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
    void (*f) (int *);
    int *arr;
    int end;
} args_t;

static void map_thread(args_t *args)
{
    #pragma omp parallel for
    for (int i = 0; i < args->end ; i++)
    {
        args->f((args->arr) + i);
    }
}

void map(void (*f) (int *), int *arr)
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

    map_thread(&args);
}



static void func_one(int *x)
{
    *x = 1;
}
static void func_multiply(int *x)
{
    *x *= 200;
}

static void func_zero(int *x)
{
    *x = 0;
}

void test_map(void)
{
    int *arr = create(25);
    int *arr_one = create(2500);
    int *arr_two = create(2500000);
    int err_counter = 0;
    //  1
    for (int i = 0; i < 25; i++)
    {
        *(arr + i) = i;
    }
    map(func_multiply, arr);
    for (int i = 0; i < 25; ++i)
    {
        if (*(arr + i) != (i * 200))
        {
            err_counter++;
        }
    }
    //  2
    for (int i = 0; i < 25; i++)
    {
        *(arr + i) = i*1000;
    }
    map(func_zero, arr);
    for (int i = 0; i < 25; ++i)
    {

        if (*(arr + i) != 0)
        {
            err_counter++;
        }
    }
    //  3
    map(func_zero, arr_one);
    map(func_one, arr_one);
    for (int i = 0; i < 2500; ++i)
    {
        if (*(arr_one + i) != 1)
        {
            err_counter++;
        }
    }

    //  4
    map(func_zero, arr_two);
    map(func_one, arr_two);
    for (int i = 0; i < 2500000; ++i)
    {
        if (*(arr_two + i) != 1)
        {
            err_counter++;
        }
    }

    printf("Error test of MAP function : %s\n", err_counter ? "FAILED" : "OK");



}


int main()
{
    test_map();
    return 0;
}

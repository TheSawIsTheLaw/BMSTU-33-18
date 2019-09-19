#include <stdlib.h>

#define SIZE_ADRS -3
#define FULLNESS_ADRS -1

typedef struct
{
    int (*f) (int);
    int *arr;
    int end;
} args_t;

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

int positive(x)
{
    if (x >= 0)
        return 1;
    else
        return 0;
}

int bigger_hundred(x)
{
    if (x >= 100)
        return 1;
    else
        return 0;
}

int bigger_hund_th(x)
{
    if (x >= 10000)
        return 1;
    else
        return 0;
}
void test_filter()
{
    int *arr_one = create(2);
    int *arr_two = create(100);
    int *arr_three = create(10000);
    int err_counter = 0;
    int acc;

    // Test 1
    for (int i = 0; i < 2;i++)
    {
        *(arr_one + i) = i - 1;
    }
    filter(positive, arr_one);
    if (*arr_one != 0)
    {
        err_counter++;
    }

    // Test 2
    for (int i = 0; i < 100; i++)
    {
        *(arr_two + i) = i + 1;
    }
    filter(bigger_hundred, arr_two);
    if (*arr_two != 100)
    {
        err_counter++;
    }

    // Test 3
    for (int i = 0; i < 10000; i++)
    {
        *(arr_three + i) = i + 1;
    }
    filter(bigger_hund_th, arr_three);
    if (*arr_three != 10000)
    {
        err_counter++;
    }
    printf("Error test of Filter function : %s\n", err_counter ? "FAILED" : "OK");

}
int main()
{
    test_filter();
    return 0;
}


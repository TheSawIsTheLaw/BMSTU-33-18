#include <stdlib.h>
#include <stdio.h>
#include "../headers/arrgame_headers_map.h"
#include "../headers/arrgame_headers_creat_v2.h"

#include <omp.h>

#define SIZE_ADRS -3

typedef struct 
{
    void (*f) (int *);
    int *arr;
    int start;
    int end;
} args_t;

#define META_DATA 3

static void *creat_v2(int size)
{
    int *arr = calloc(size * 2 + META_DATA, sizeof(int));

    if (arr == NULL)
    {
        return NULL;
    }

    *arr = size;
    *(arr + 1) = size * 2;
    *(arr + 2) = 0;

    return arr + 3;
}


static void foo (int *x)
{
    *x += 150;
}

static void map_thread(args_t *args)
{
    //for (int *i = args->arr + args->start; i < args->arr + args->end; i++)
    #pragma omp parallel for
    for (int i = 0; i < 100000000; i++)
    {
        args->f((args->arr) + i);
    }
}

void map(void (*f) (int *), int *arr)
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

    map_thread(&args);
}

int main(void)
{
    setbuf(stdout, NULL);
    int *arr = create_v2(100000000);
    printf("%d - size, %d - alloc mmry, %d busy mmry", *(arr - 3), *(arr - 2), *(arr));
    map(foo, arr);
    puts("\nmap completed");
    return 0;
}


#include <stdint.h>
#include <stdio.h>
#include "../../headers/arrgame_headers_reduce.h"
#include "../arrgame_functions_reduce.c"
#include "../../headers/arrgame_headers_create.h"
#include "../arrgame_functions_create.c"
#include "timer.h"

#define GHZ 3300000000

int foo(int acc, int element)
{
    return acc + element;
}

int main(void)
{
    int *arr = create(10000);

    for (int i = 0; i < 10000; i++)
    {
        *(arr + i) = 1;
    }
    
    uint64_t start_time = tick();
    for (int i = 0; i < 100000; i++)
    {
        int acc = reduce(foo, arr);
    }
    uint64_t end_time = tick();

    printf("%.10lf - time running reduce on C\n", (double)(end_time - start_time) / GHZ);
    return 0;
}

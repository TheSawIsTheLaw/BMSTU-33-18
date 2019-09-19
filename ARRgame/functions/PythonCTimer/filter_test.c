#include <stdint.h>
#include <stdio.h>
#include "../../headers/arrgame_headers_filter.h"
#include "../arrgame_functions_filter.c"
#include "../../headers/arrgame_headers_create.h"
#include "../arrgame_functions_create.c"
#include "timer.h"

#define GHZ 3300000000

int foo(int element)
{
    return (element > 0) ? 1 : 0;
}

int main(void)
{
    int *arr = create(10000);

    short int k = 1;
    for (int i = 0; i < 10000; i++)
    {
        *(arr + i) = k;
        k *= -1;
    }
    
    uint64_t start_time = tick();
    for (int i = 0; i < 1000; i++)
    {
        filter(foo, arr);
    }
    uint64_t end_time = tick();

    printf("%.10lf - time running filter on C\n", (double)(end_time - start_time) / GHZ);
    return 0;
}



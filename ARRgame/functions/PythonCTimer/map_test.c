/*
#include <stdint.h>
#include <stdio.h>
#include "../../headers/arrgame_headers_map.h"
#include "../arrgame_functions_map.c"
#include "../../headers/arrgame_headers_create.h"
#include "../arrgame_functions_create.c"
#include "timer.h"

#define GHZ 3300000000

void foo(int *element)
{
    *element += 1;    
}

int main(void)
{
    int *arr = create(10000);
    
    uint64_t start_time = tick();
    for (int i = 0; i < 1000; i++)
    {
        map(foo, arr);
    }
    uint64_t end_time = tick();

    printf("%.10lf - time running map on C\n", (double)(end_time - start_time) / GHZ);
    return 0;
}

*/

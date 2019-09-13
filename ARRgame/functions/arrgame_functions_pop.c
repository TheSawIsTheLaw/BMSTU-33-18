#include "../headers/arrgame_headers_pop.h"
#include <stdio.h>

int pop_base(int *arr, int n)
{
    return 0;
}

int var_pop(pop_args in)
{
    int *arr_out = in.arr ? in.arr : 0;
    int n_out = in.n ? in.n : 3;
    return pop_base(arr_out, n_out);
}
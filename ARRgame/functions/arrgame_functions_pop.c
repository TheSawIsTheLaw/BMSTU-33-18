#include "../headers/arrgame_headers_pop.h"
#include <errno.h>
#define OK 0
#define POS_ERROR 1
#define SERVICE_INFO 3
extern int errno;

int pop_base(int *arr, int n)
{
    if (!arr || (*(arr - SERVICE_INFO) - n <= 0 || n < 0))
    {
        errno = POS_ERROR;
        return 0;
    }
    int value = *(arr + n);
    int kol = *(arr - SERVICE_INFO);
    for (int i = n; i < kol - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    --*(arr - SERVICE_INFO);
    return value;
}

int var_pop(pop_args in)
{
    int *arr_out = in.arr ? in.arr : 0;
    int n_out = 0;
    if (arr_out)
        n_out = in.n ? in.n : *(in.arr - SERVICE_INFO) - 1;
    return pop_base(arr_out, n_out);
}
#include "../headers/arrgame.h"

#define OK 0
#define POS_ERROR 1
#define MEM_INFO 2
#define SIZE_INFO 3

/*
Delete an array[n] element.

Input data:
* int *arr - array to be modified.
* (optional) int n - number to be delete.
* if n not specifed, function delete arr[0]


Output data:
* Return arr[n] [and optional modified errno].
*/

static int pop_base(int *arr, int n)
{
    if (!arr || (*(arr - SIZE_INFO) - n <= 0 || n < 0))
    {
        return 0;
    }

    int value = *(arr + n);
    int kol = *(arr - SIZE_INFO);

    for (int i = n; i < kol - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }

    --*(arr - SIZE_INFO);
    *(arr - MEM_INFO) -= sizeof(int);

    return value;
}

int arrgame_pop_var(pop_args in)
{
    int *arr_out = in.arr ? in.arr : 0;
    int n_out = 0;

    if (arr_out)
        n_out = in.n ? in.n : 0;

    return pop_base(arr_out, n_out);
}

#include "../headers/arrgame_headers_extend.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET_LEN 0
#define OFFSET_ALLOC_COUNT 1
#define OFFSET_REAL_COUNT 2
#define OFFSET_START 3

#define GET_LEN(arr_ptr) *(arr_ptr + OFFSET_LEN)
#define GET_ALC(arr_ptr) *(arr_ptr + OFFSET_ALLOC_COUNT)
#define GET_REC(arr_ptr) *(arr_ptr + OFFSET_REAL_COUNT)
#define GET_START_PTR(arr_ptr) arr_ptr + OFFSET_START

#define SUCCESS 0
#define ALLOC_FAIL -1

#define TEST_SUCCESS 0
#define TEST_FAILURE 1

#define NOT_EQ 0
#define EQ 1

int cmp_arrays(int *arra, int *arrb)
{
    if (GET_REC(arra) != GET_REC(arrb))
        return NOT_EQ;

    const int num = GET_REC(arra);
    for (int i = 0; i < num; i++)
        if (arra[i + OFFSET_START] != arrb[i + OFFSET_START])
            return NOT_EQ;

    return EQ;
}

int test_extend(int *arra, int *arrb,
                int *expected)
{
    arra = extend(arra, arrb);

    if (cmp_arrays(arra, expected))
    {
        printf("test failed, do something\n");
        return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}

int dumb_create(int **arr, int count, int sample[])
{
    int *temp = (int*)calloc(count + OFFSET_START, sizeof(int));
    if (!temp)
        return ALLOC_FAIL;

    *arr = temp;
    GET_LEN(*arr) = count;
    GET_ALC(*arr) = count;
    GET_REC(*arr) = count;

    memcpy((*arr + OFFSET_START), sample, count * sizeof(int));

    return SUCCESS;
}

void dumb_destroy(int *arr)
{
    free(arr);
}

int first_test_extend()
{
    int errc = 0;

    int a_data[] = {1, 4, 2, 3};
    int b_data[] = {5, 4, 1};
    int e_data[] = {1, 4, 2, 3, 5, 4, 1};
    int *arra;
    int *arrb;
    int *expected;
    
    dumb_create(&arra, 4, a_data);
    dumb_create(&arrb, 3, b_data);
    dumb_create(&arra, 7, e_data);

    errc += test_extend(arra, arrb, expected);
    
    return errc;
}

int main(void)
{
    return 0;
}


#include "../headers/arrgame_headers_pop.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST_PASSED 0
#define TEST_FAILED 1
#define ALL_PASSED 0
#define ERROR_WHILE_TESTING 1

#include <errno.h>

#define OK 0
#define POS_ERROR 1
#define MEM_INFO 2
#define SIZE_INFO 3

typedef struct
{
    int *arr;
    int n;
} pop_args;

int pop_base(int *arr, int n)
{
    if (!arr || (*(arr - SIZE_INFO) - n <= 0 || n < 0))
    {
        errno = POS_ERROR;
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

int var_pop(pop_args in)
{
    int *arr_out = in.arr ? in.arr : 0;
    int n_out = 0;
    if (arr_out)
    {
        n_out = in.n ? in.n : *(in.arr - SIZE_INFO) - 1;
    }
    return pop_base(arr_out, n_out);
}

int test(int *array, int *array2, int size2, int pop_number)
{
    pop(array2[3], pop_number);
    int count_pass = 0;
    int pop_number_check = 0;
    for (int i = 2; i < size2; i++)
    {
        if (i == pop_number)
        {
            pop_number_check = 1;
        }
        if (pop_number_check == 0)
        {
            if (array[i] == array2[i])
            {
                count_pass++;
            }
        }
        else
        {
            if (array[i + 1] == array2[i])
            {
                count_pass++;
            }
        }
    }
    if (count_pass == size2)
    {
        return TEST_PASSED;
    }
    return TEST_FAILED;
}

int main(void)
{
    int test_count = 0;
    int failed_test_count = 0;
    int completed_test_count = 0;
    test_count++;
    int array_1[8] = {5, 0, 0, 1, 2, 0xDEADA52, 4, 5};
    int array_1_final[7] = {4, 0, 0, 1, 2, 4, 5};
    if (test(array_1, array_1_final, 7, 5) == TEST_PASSED)
    {
        completed_test_count++;
    }
    else
    {
        failed_test_count++;
    }
    int array_2[10] = {7, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    test_count++;
    int array_2_final[9] = {6, 0, 0, 0, 0, 0, 0, 0, 0};
    if (test(array_2, array_2_final, 9, 8) == TEST_PASSED)
    {
        completed_test_count++;
    }
    else
    {
        failed_test_count++;
    }
    int array_3[6] = {3, 0, 0, 2147483647, -2147483647, 1};
    test_count++;
    int array_3_final[5] = {2, 0, 0, -2147483647, 1};
    if (test(array_3, array_3_final, 5, 3) == TEST_PASSED)
    {
        completed_test_count++;
    }
    else
    {
        failed_test_count++;
    }
    int array_4[8] = {5, 0, 0, -1, -512, -723546, -3241, -544};
    test_count++;
    int array_4_final[7] = {4, 0, 0, -1, -723546, -3241, -544};
    if (test(array_4, array_4_final, 7, 4) == TEST_PASSED)
    {
        completed_test_count++;
    }
    else
    {
        failed_test_count++;
    }
    printf("Completed %d/%d \n", completed_test_count, test_count);
    printf("Failed %d/%d \n", failed_test_count, test_count);
    if (completed_test_count == test_count)
    {
        printf("Testing successful");
        return ALL_PASSED;
    }
    else
    {
        printf("Testing failed");
        return ERROR_WHILE_TESTING;
    }
}
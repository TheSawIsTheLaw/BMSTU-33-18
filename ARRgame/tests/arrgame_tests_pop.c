#include "../headers/arrgame_headers_sort.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST_PASSED 0
#define TEST_FAILED 1
#define ALL_PASSED 0
#define ERROR_WHILE_TESTING 1

int test(int *array, int *array2, int size2, int pop_number)
{
    pop(array2, pop_number);
    int count_pass = 0;
    int pop_number_check = 0;
    for (int i = 0; i < size2; i++)
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
    int i;
    int test_count = 0;
    int failed_test_count = 0;
    int completed_test_count = 0;
    test_count++;
    int array_1[5] = {1, 2, 0xDEADA52, 4, 5};
    int array_1_final[4] = {1, 2, 4, 5};
    if (test(array_1, array_1_final, 4, 2) == TEST_PASSED)
    {
        completed_test_count++;
    }
    else
    {
        failed_test_count++;
    }
    int array_2[7] = {0, 0, 0, 0, 0, 0, 0};
    test_count++;
    int array_2_final[6] = {0, 0, 0, 0, 0, 0};
    if (test(array_2, array_2_final, 6, 5) == TEST_PASSED)
    {
        completed_test_count++;
    }
    else
    {
        failed_test_count++;
    }
    int array_3[3] = {2147483647, -2147483647, 1};
    test_count++;
    int array_3_final[2] = {-2147483647, 1};
    if (test(array_3, array_3_final, 2, 0) == TEST_PASSED)
    {
        completed_test_count++;
    }
    else
    {
        failed_test_count++;
    }
    int array_4[5] = {-1, -512, -723546, -3241, -544};
    test_count++;
    int array_4_final[4] = {-1, -723546, -3241, -544};
    if (test(array_4, array_4_final, 4, 1) == TEST_PASSED)
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
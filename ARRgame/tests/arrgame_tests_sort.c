#include "../headers/arrgame_headers_sort.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef N
#define N 100 // ������ ������� (��� ������������)
#endif

#ifndef OFFSET
#define OFFSET 3  // ����������� ������ 1 ��������
#endif

#ifndef ARRAY_PART
#define ARRAY_PART 10  // ������ ����� �������, ������� ���� �������������
#endif

#ifndef PASSED
#define PASSED 0  // ���� �������
#endif

#ifndef FAILURE
#define FAILURE 1  // ���� ��������
#endif

#ifndef TESTING_DONE
#define TESTING_DONE 0  // ������������ ���������
#endif

#ifndef UP_SORT_KEY
#define UP_SORT_KEY 1  // ���� ���������� �� �����������
#endif

#ifndef DOWN_SORT_KEY
#define DOWN_SORT_KEY -1  // ���� ���������� �� ��������
#endif

void change(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void up_sort(int *head, int *tail)
{
    int len = tail - head;

    if (head >= tail)
    {
        return;
    }

    int mid = *(head + len / 2);
    int *start = head, *end = tail;

    while (start <= end)
    {
        while (*start < mid)
        {
            start++;
        }

        while (*end > mid)
        {
            end--;
        }

        if (start <= end)
        {
            change(start, end);
            start++;
            end--;
        }
    }

    up_sort(head, end);
    up_sort(start, tail);    
}

void down_sort(int *head, int *tail)
{
    int len = tail - head;

    if (head >= tail)
    {
        return;
    }

    int mid = *(head + len / 2);
    int *start = head, *end = tail;

    while (start <= end)
    {
        while (*start > mid)
        {
            start++;
        }

        while (*end < mid)
        {
            end--;
        }

        if (start <= end)
        {
            change(start, end);
            start++;
            end--;
        }
    }

    down_sort(head, end);
    down_sort(start, tail); 
}

void sort(int *head, int *tail, int key) // Принимает указатели на сортируемый интервал
{
    if (key == UP_SORT_KEY)
    {
        up_sort(head, tail);
    }
    else
    {
        down_sort(head, tail);
    }
}


int array_compare(int* a, int* b)
{
    for (int i = OFFSET; i < N + OFFSET; i++)
        if (a[i] != b[i])
            return FAILURE;
    return PASSED;
}


int ascending_order_testing()
{
    int* array = (int*)calloc(N + OFFSET, sizeof(int));
    int* control_array = (int*)calloc(N + OFFSET, sizeof(int));

    for (int i = OFFSET; i < N + OFFSET; i++)
        control_array[i] = i - OFFSET;

    // ������ shuffle
    for (int i = OFFSET; i < N + OFFSET; i++)
        if ((i - OFFSET) % 2 == 0)
            array[i] = i - OFFSET;
        else
            array[N + OFFSET - i + OFFSET] = i - OFFSET;

    sort(array + OFFSET, array + N + OFFSET - 1, UP_SORT_KEY);
    int result = array_compare(array, control_array);

    free(array);
    free(control_array);

    return result;
}


int descending_order_testing()
{
    int* array = (int*)calloc(N + OFFSET, sizeof(int));
    int* control_array = (int*)calloc(N + OFFSET, sizeof(int));

    for (int i = OFFSET; i < N + OFFSET; i++)
        control_array[i] = N + OFFSET - i - 1;

    // ������ shuffle
    for (int i = OFFSET; i < N + OFFSET; i++)
        if ((i - OFFSET) % 2 == 0)
            array[i] = i - OFFSET;
        else
            array[N + OFFSET - i + OFFSET] = i - OFFSET;

    sort(array + OFFSET, array + N + OFFSET - 1, DOWN_SORT_KEY);
    int result = array_compare(array, control_array);

    free(array);
    free(control_array);

    return result;
}


int part_ascend_testing()
{
    int* array = (int*)calloc(N + OFFSET, sizeof(int));
    int* control_array = (int*)calloc(N + OFFSET, sizeof(int));

    for (int i = OFFSET; i < N + OFFSET; i++)
        if ((i - OFFSET) % 2 == 0)
            control_array[i] = i - OFFSET;
        else
            control_array[N + OFFSET - i + OFFSET] = i - OFFSET;

    // not optimized
    int first_elem = 0;
    for (int i = OFFSET; i < OFFSET + ARRAY_PART / 2; i++)
    {
        control_array[i] = first_elem;
        first_elem += 2;
    }
    int last_elem = 91;
    for (int i = OFFSET + ARRAY_PART / 2; i < OFFSET + ARRAY_PART; i++)
    {
        control_array[i] = last_elem;
        last_elem += 2;
    }

    // ������ shuffle
    for (int i = OFFSET; i < N + OFFSET; i++)
        if ((i - OFFSET) % 2 == 0)
            array[i] = i - OFFSET;
        else
            array[N + OFFSET - i + OFFSET] = i - OFFSET;

    sort(array + OFFSET, array + OFFSET + ARRAY_PART - 1, UP_SORT_KEY);
    int result = array_compare(array, control_array);

    free(array);
    free(control_array);

    return result;
}


int part_descend_testing()
{
    int* array = (int*)calloc(N + OFFSET, sizeof(int));
    int* control_array = (int*)calloc(N + OFFSET, sizeof(int));

    // not optimized
    for (int i = OFFSET; i < N + OFFSET; i++)
        if ((i - OFFSET) % 2 == 0)
            control_array[i] = i - OFFSET;
        else
            control_array[N + OFFSET - i + OFFSET] = i - OFFSET;

    int last_elem = 99;
    for (int i = OFFSET; i < OFFSET + ARRAY_PART / 2; i++)
    {
        control_array[i] = last_elem;
        last_elem -= 2;
    }
    int first_elem = 8;
    for (int i = OFFSET + ARRAY_PART / 2; i < OFFSET + ARRAY_PART; i++)
    {
        control_array[i] = first_elem;
        first_elem -= 2;
    }

    // ������ shuffle
    for (int i = OFFSET; i < N + OFFSET; i++)
        if ((i - OFFSET) % 2 == 0)
            array[i] = i - OFFSET;
        else
            array[N + OFFSET - i + OFFSET] = i - OFFSET;

    sort(array + OFFSET, array + OFFSET + ARRAY_PART - 1, DOWN_SORT_KEY);
    int result = array_compare(array, control_array);

    free(array);
    free(control_array);

    return result;
}


int ascend_sorted_array_testing()
{
    int* array = (int*)calloc(N + OFFSET, sizeof(int));
    int* control_array = (int*)calloc(N + OFFSET, sizeof(int));

    for (int i = OFFSET; i < N + OFFSET; i++)
    {
        array[i] = i - OFFSET;
        control_array[i] = i - OFFSET;
    }

    sort(array + OFFSET, array + N + OFFSET - 1, UP_SORT_KEY);
    int result = array_compare(array, control_array);

    free(array);
    free(control_array);

    return result;
}
  

int descend_sorted_array_testing()
{
    int* array = (int*)calloc(N + OFFSET, sizeof(int));
    int* control_array = (int*)calloc(N + OFFSET, sizeof(int));

    for (int i = OFFSET; i < N + OFFSET; i++)
    {
        array[i] = N - OFFSET - i;
        control_array[i] = N - OFFSET - i;
    }

    sort(array + OFFSET, array + N + OFFSET - 1, DOWN_SORT_KEY);
    int result = array_compare(array, control_array);

    free(array);
    free(control_array);

    return result;
}


int main()
{
    int code;

    // ���������� �� �����������
    code = ascending_order_testing();
    printf("ASCENDING ORDER SORTING TESTING:\t");
    if (code == FAILURE)
        printf("FAILED!\n");
    else
        printf("PASSED!\n");

    // ���������� �� ��������
    code = descending_order_testing();
    printf("DESCENDING ORDER SORTING TESTING:\t");
    if (code == FAILURE)
        printf("FAILED!\n");
    else
        printf("PASSED!\n");
    
    // ���������� �� ����������� �����
    code = part_ascend_testing();
    printf("ASCENDING ORDER (PARTIAL) SORTING TESTING:\t");
    if (code == FAILURE)
        printf("FAILED!\n");
    else
        printf("PASSED!\n");
    
    // ���������� �� �������� �����
    code = part_descend_testing();
    printf("DESCENDING ORDER (PARTIAL) SORTING TESTING:\t");
    if (code == FAILURE)
        printf("FAILED!\n");
    else
        printf("PASSED!\n");

    // ���������� �������������� �� ����������� �������
    code = ascend_sorted_array_testing();
    printf("ASCENDING ORDER SORTED ARRAY TESTING:\t");
    if (code == FAILURE)
        printf("FAILED!\n");
    else
        printf("PASSED!\n");

    // ���������� �������������� �� �������� �������
    code = descend_sorted_array_testing();
    printf("ASCENDING ORDER SORTED ARRAY TESTING:\t");
    if (code == FAILURE)
        printf("FAILED!\n");
    else
        printf("PASSED!\n");

    return TESTING_DONE;
}
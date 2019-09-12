#include <stdio.h>
#include "../headers/arrgame_functions_sort.h"

void change(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}


void quick_sort(int *head, int *tail) // Принимает указатели на сортируемый интервал
{
    int len = tail - head;
    if (head >= tail)
        return;
    int mid = *(head + len / 2);
    //printf("%ld\n", tail - head);
    //printf("%ld\n", (((size_t) head + (size_t) tail) / 2));
    //printf("%d\n", mid);
    //arr_output(head, tail + 1);
    int *start = head, *end = tail;
    while (start <= end)
    {
        while (*start < mid)
            start++;
        while (*end > mid)
            end--;
        if (start <= end)
        {
            change(start, end);
            // printf("%d %d %d\n", mid, arr[start], arr[end]);
            start++;
            end--;
            // arr_print(arr, SIZE);
        }
    }
    quick_sort(head, end);
    quick_sort(start, tail);
}
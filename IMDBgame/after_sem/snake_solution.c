#include <stdio.h>

#define NO 0
#define YES 1
#define PAIR_LEN 2

int is_less(int *elem_1, int *elem_2)
{
    if (elem_1[0] < elem_2[0] || (elem_1[0] < elem_2[0] && elem_1[1] < elem_2[1]))
        return YES;
    return NO;
}


void swap_pair(int *elem_1, int *elem_2)
{
    int temp[2] = { elem_1[0], elem_1[1] };
    elem_1[0] = elem_2[0];
    elem_1[1] = elem_2[1];
    elem_2[0] = temp[0];
    elem_2[1] = temp[1];
}


void qsort(int main_matr[][PAIR_LEN], int begin, int end) // qsort(main_matr, 0, size - 1)
{
    if (begin >= end)
        return;

    int middle_pos = (end - begin) / 2;
    int middle[2] = { main_matr[middle_pos][0], main_matr[middle_pos][1] };
    int left = begin, right = end;

    while (left <= right)
    {
        while (is_less(main_matr[left], middle))
            left++;
        while (is_less(middle, main_matr[right]))
            right--;
        if (left <= right)
            swap_pair(main_matr[left++], main_matr[right--]);
    }
    qsort(main_matr, begin, right);
    qsort(main_matr, left, end);
}


int snake_solution();

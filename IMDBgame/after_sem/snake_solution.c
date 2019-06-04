#include <stdio.h>

#define NO 0
#define YES 1
#define PAIR_LEN 2

int is_less(int *elem_1, int *elem_2)
{
    if (elem_1[0] < elem_2[0] || (elem_1[0] == elem_2[0] && elem_1[1] < elem_2[1]))
        return YES;
    return NO;
}


void swap_pair(int *elem_1, int *elem_2)
{
    int temp;
    for (int i = 0; i < PAIR_LEN; i++)
    {
        temp = elem_1[i];
        elem_1[i] = elem_2[i];
        elem_2[i] = temp;
    }
}


int get_pos_by_id(int main_matr[][PAIR_LEN], int id, int len)
{
    int left = 0;
    int right = len - 1;
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (main_matr[middle][0] < id)
            left = middle + 1;
        else if (main_matr[middle][0] > id)
            right = middle - 1;
        else
            goto found;
    }
    return -1;

    found:
    while (main_matr[middle--][0] == id && middle >= 0);
    return (middle == -1) ? middle + 1 : middle + 2;
}


void my_sort(int main_matr[][PAIR_LEN], int begin, int end) // qsort(main_matr, 0, size - 1)
{
    if (begin >= end)
        return;

    int middle_pos = (end + begin) / 2;
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
    my_sort(main_matr, begin, right);
    my_sort(main_matr, left, end);
}

/*
// snake_solution(films_matr, actors_matr, len, from, to, 0, 20, route)
int snake_solution(int films_matr[][PAIR_LEN], int actors_matr[][PAIR_LEN],
    int len, int from, int to, int iter, int max_iter, int *route)
{
    if (iter >= max_iter)
        return -1;
    else if (from == to)
        return 0;

    int pos, min_pos;
    int min_dist = max_iter + 1, dist;

    if (!(iter % 2))
    {
        pos = get_pos_by_id(actors_matr, from, len);
        while (actors_matr[pos][0] == from)
            if ((dist = snake_solution(films_matr, actors_matr, len, actors_matr[pos++][1], to, iter + 1, max_iter, route + 1)) != -1)
            {
                min_dist = (min_dist > dist) ? dist : min_dist;
                min_pos = pos - 1;
            }
        if (min_dist < max_iter + 1)
        {
            *route = min_pos;
            return min_dist;
        }
        else
            return -1;
    }

    else
    {
        pos = get_pos_by_id(films_matr, from, len);
        while (films_matr[pos][0] == from)
            if ((dist = snake_solution(films_matr, actors_matr, len, films_matr[pos++][1], to, iter + 1, max_iter, route + 1)) != -1)
            {
                min_pos = (min_dist > dist) ? pos - 1 : min_pos;
                min_dist = (min_dist > dist) ? dist : min_dist;
            }
        if (min_dist < max_iter + 1)
        {
            *route = min_pos;
            return min_dist;
        }
        else
            return -1;
    }
}
*/

int main()
{
    setbuf(stdout, NULL);

    int test_arr[][PAIR_LEN] = { { 234, 234 }, { 3242, 324 }, { 3142, 724 }, { 123, 121 }, { 234, 657 },
    { 34, 3412 }, { 34, 34 }, { 34, 32 }, { 3142, 2 }, { 324, 100 } };

    my_sort(test_arr, 0, 9);
    for (int i = 0; i < 10; i++)
        printf("%d   %d\n", test_arr[i][0], test_arr[i][1]);

    printf("\n%d", get_pos_by_id(test_arr, 324, 10));
    printf("\n%d", get_pos_by_id(test_arr, 34, 10));
    printf("\n%d", get_pos_by_id(test_arr, 3142, 10));
    return 0;
}

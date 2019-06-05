#include <stdio.h>

#define NO 0
#define YES 1
#define PAIR_LEN 2

/*
typedef struct
{
    unsigned int vertex_id : 24;
    unsigned int bacon : 8;
} Tree;
*/


void add_conn(unsigned int *const conn_arr, const unsigned int new_conn_id)
{
    conn_arr[new_conn_id / (sizeof(unsigned int) * 8)] |= 1 << (new_conn_id % (sizeof(unsigned int) * 8));
}


unsigned int get_conn(unsigned int *const conn_arr, const unsigned int id)
{
    return conn_arr[id / (sizeof(unsigned int) * 8)] & (1 << (id % (sizeof(unsigned int) * 8)));
}


int is_less(const int *const elem_1, const int *const elem_2, const int index)
{
    if (elem_1[index] < elem_2[index] || (elem_1[index] == elem_2[index]
        && elem_1[(index + 1) % 2] < elem_2[(index + 1) % 2]))
        return YES;
    return NO;
}


int is_less_equal(const int *const elem_1, const int *const elem_2, const int index)
{
    if (elem_1[index] < elem_2[index] || (elem_1[index] == elem_2[index] &&
        elem_1[(index + 1) % 2] <= elem_2[(index + 1) % 2]))
        return YES;
    return NO;
}


void swap_pair(int *const elem_1, int *const elem_2)
{
    int temp;
    for (int i = 0; i < PAIR_LEN; i++)
    {
        temp = elem_1[i];
        elem_1[i] = elem_2[i];
        elem_2[i] = temp;
    }
}


int get_pos_by_id(const int main_matr[][PAIR_LEN], const int id, const int len, const int index)
{
    int left = 0;
    int right = len - 1;
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (main_matr[middle][index] < id)
            left = middle + 1;
        else if (main_matr[middle][index] > id)
            right = middle - 1;
        else
            goto found;
    }
    return -1;

    found:
        while (main_matr[middle--][index] == id && middle >= 0);
        return (middle == -1) ? middle + 1 : middle + 2;
}


void my_sort(int main_matr[][PAIR_LEN], const int begin, const int end, const int index) // qsort(main_matr, 0, size - 1)
{
    if (begin >= end)
        return;

    int middle_pos = (end + begin) / 2;
    int middle[2] = { main_matr[middle_pos][0], main_matr[middle_pos][1] };
    int left = begin, right = end;

    while (left <= right)
    {
        while (is_less(main_matr[left], middle, index))
            left++;
        while (is_less_equal(middle, main_matr[right], index))
            right--;
        if (left <= right)
            swap_pair(main_matr[left++], main_matr[right--]);
    }
    my_sort(main_matr, begin, right);
    my_sort(main_matr, left, end);
}


void make_tree(unsigned int *main_tree, actors_pairs[][PAIR_LEN],
    const int size_of_actors, const int from, const int to) // id of main vertex of tree (Bacon's)
{
    unsigned int queue[size_of_actors]; // очередь для вершин для поиска в ширину
    unsigned int visited[size_of_actors / 32 + 1] = { 0 }; // список посещенных вершин
    unsigned int cur_pos = 0, max_pos = 0; // начало, конец очереди
    unsigned int id = from;
    unsigned int cur_id;

    main_tree[id] = 0;
    add_conn(visited, id);
    queue[max_pos++] = id;

    while(cur_pos < max_pos) // пока очередь не пуста
    {
        id = queue[cur_pos++]; // берем следующего по очереди актера
        index = get_pos_by_id(actors_pairs, id, len, 0);
        while (actors_pairs[index][0] == id) // найдем все необработанные связи для этого актера...
        {
            cur_id = actors_pairs[index][1];
            if (!get_conn(visited, cur_id)) // если найдена связь и она еще не была обработана
            {
                add_conn(visited, cur_id); // добавить связь в обработанные
                queue[max_pos++] = cur_id; // добавить данного актера в очередь
                main_tree[cur_id] = id; // записать данные для данного актера
            }
    }
}


void get_route(const unsigned int *const main_tree, const int index, unsigned int *route)
{
    int i = 0;
    route[i++] = index;
    while(main_tree[index] != 0)
    {
        route[i++] = main_tree[index];
        index = main_tree[index];
    }
}


void set_test(int test_arr[][PAIR_LEN], const int num_1, const int *nums,
    const int len_nums, const int *pos)
{
    int i;
    for (i = 0; i < len_nums; i++)
    {
        test_arr[*pos + i][0] = num_1;
        test_arr[*pos + i][1] = num_2;
    }
    *pos += i;
}


int fill_test(int test_arr[][PAIR_LEN])
{
    int pos = 0;
    set_test(test_arr, 1, 2, &pos);
}


int main()
{
    setbuf(stdout, NULL);

    int test_arr[100][PAIR_LEN];
    int size = fill_test(test_arr);

    my_sort(test_arr, 0, 9);
    for (int i = 0; i < 10; i++)
        printf("%d   %d\n", test_arr[i][0], test_arr[i][1]);

    printf("\n%d", get_pos_by_id(test_arr, 324, 10));
    printf("\n%d", get_pos_by_id(test_arr, 34, 10));
    printf("\n%d", get_pos_by_id(test_arr, 3142, 10));
    return 0;
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

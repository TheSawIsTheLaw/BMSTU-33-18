#include <stdio.h>

#define NO 0
#define YES 1
#define PAIR_LEN 2
#define SIZE 21


void add_conn(int *const conn_arr, const int new_conn_id)
{
    conn_arr[new_conn_id / (sizeof(unsigned int) * 8)] |= 1 << (new_conn_id % (sizeof(unsigned int) * 8));
}


unsigned int get_conn(int *const conn_arr, const int id)
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


int get_pos_by_id(int main_matr[][PAIR_LEN], const int id, const int len, const int index)
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
        while (is_less(middle, main_matr[right], index))
            right--;
        if (left <= right)
            swap_pair(main_matr[left++], main_matr[right--]);
    }
    my_sort(main_matr, begin, right, index);
    my_sort(main_matr, left, end, index);
}


void make_tree(int *main_tree, int actors_pairs[][PAIR_LEN],
    const int size_of_actors, const int from, const int to) // id of main vertex of tree (Bacon's)
{
    int queue[SIZE]; // очередь для вершин для поиска в ширину
    int visited[SIZE / 32 + 1] = { 0 }; // список посещенных вершин
    int cur_pos = 0, max_pos = 0; // начало, конец очереди
    int id = from;
    int cur_id, index;
    // all variables higher were unsigned (but it can be the problem when we would link funcs???????)

    main_tree[id] = 0;
    add_conn(visited, id);
    queue[max_pos++] = id;

    while(cur_pos < max_pos) // пока очередь не пуста
    {
        // printf("\nqueue:  ");
        // for (int i = cur_pos; i < max_pos; i++)
        //     printf("%d   ", queue[i]);
        id = queue[cur_pos++]; // берем следующего по очереди актера
        index = get_pos_by_id(actors_pairs, id, size_of_actors, 0);
        while (actors_pairs[index][0] == id) // найдем все необработанные связи для этого актера...
        {
            cur_id = actors_pairs[index++][1];
            if (!get_conn(visited, cur_id)) // если найдена связь и она еще не была обработана
            {
                add_conn(visited, cur_id); // добавить связь в обработанные
                queue[max_pos++] = cur_id; // добавить данного актера в очередь
                main_tree[cur_id] = id; // записать данные для данного актера
            }
        }
    }
}


int get_route(const int *const main_tree, int index, int *const route)
{
    int i = 0;
    route[i++] = index;
    while(main_tree[index] != 0)
    {
        route[i++] = main_tree[index];
        index = main_tree[index];
    }
    return i;
}

/*
void set_test(int test_arr[][PAIR_LEN], const int num_1, const int *nums,
    const int len_nums, int *const pos)
{
    int i;
    for (i = 0; i < len_nums; i++)
    {
        test_arr[*pos + i][0] = num_1;
        test_arr[*pos + i][1] = nums[i];
    }
    *pos += i;
}


int fill_test(int test_arr[][PAIR_LEN])
{
    int pos = 0;

    int arr_1[] = { 2, 7 };
    int arr_2[] = { 1, 3, 7 };
    int arr_3[] = { 2, 5, 6 };
    int arr_4[] = { 1, 5, 14 };
    int arr_5[] = { 3, 4, 11, 20 };
    int arr_6[] = { 3, 17 };
    int arr_7[] = { 1, 2 };
    int arr_8[] = { 5, 9, 18 };
    int arr_9[] = { 8, 10 };
    int arr_10[] = { 9, 11, 14, 18 };
    int arr_11[] = { 5, 10, 13, 16 };
    int arr_12[] = { 13 };
    int arr_13[] = { 11, 12, 16 };
    int arr_14[] = { 4, 10, 15 };
    int arr_15[] = { 14, 19 };
    int arr_16[] = { 11, 13 };
    int arr_17[] = { 6 };
    int arr_18[] = { 8, 10, 18 };
    int arr_19[] = { 15, 18 };
    int arr_20[] = { 5 };

    set_test(test_arr, 1, arr_1, 2, &pos);
    set_test(test_arr, 2, arr_2, 3, &pos);
    set_test(test_arr, 3, arr_3, 3, &pos);
    set_test(test_arr, 4, arr_4, 3, &pos);
    set_test(test_arr, 5, arr_5, 4, &pos);
    set_test(test_arr, 6, arr_6, 2, &pos);
    set_test(test_arr, 7, arr_7, 2, &pos);
    set_test(test_arr, 8, arr_8, 3, &pos);
    set_test(test_arr, 9, arr_9, 2, &pos);
    set_test(test_arr, 10, arr_10, 4, &pos);
    set_test(test_arr, 11, arr_11, 4, &pos);
    set_test(test_arr, 12, arr_12, 1, &pos);
    set_test(test_arr, 13, arr_13, 3, &pos);
    set_test(test_arr, 14, arr_14, 3, &pos);
    set_test(test_arr, 15, arr_15, 2, &pos);
    set_test(test_arr, 16, arr_16, 2, &pos);
    set_test(test_arr, 17, arr_17, 1, &pos);
    set_test(test_arr, 18, arr_18, 3, &pos);
    set_test(test_arr, 19, arr_19, 2, &pos);
    set_test(test_arr, 20, arr_20, 1, &pos);

    return pos;
}
// int test_arr[100][PAIR_LEN];
// int size = fill_test(test_arr);
*/





int main()
{
    setbuf(stdout, NULL);

    int main_pairs_arr[ACTORS_PAIRS_SIZE][PAIR_LEN];
    int main_tree[ACTORS_PAIRS_SIZE];
    int route[MAX_ROUTE_LEN];
    int from, to;
    char actor[100];

    // my_sort(main_pairs_arr, 0, ACTORS_PAIRS_SIZE - 1, 0);
    read_actor:
    printf("Введите актера, для которого нужно вычислить расстояния: ");
    gets(actor);
    // Сережа, дай айди и запиши в переменную from, пожалуйста!!!
    if (!check)
        goto read_actor;
    make_tree(main_tree, test_arr, size, from, to);
    while (strcmp(actor, "exit"))
    {
        read_actor_to:
        printf("Введите актера, от которого нужно вычислить расстояние до первоначального: ");
        gets(actor);
        // Сережа, дай айди и запиши в переменную to, пожалуйста (также может поступить exit, нужно выйти в таком случае)!!!
        if (!check)
            goto read_actor_to;
        size = get_route(main_tree, to, route);
        printf("dist = %d\n", size - 1);
        printf("route:\n");
        // Сережа, в route хранится путь из айди, дай имена, пожалуйста!!!
        for (int i = 0; i < size; i++)
            printf("%d   ", route[i]);
    }

    return 0;
}

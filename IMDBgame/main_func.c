#include <stdio.h>
#include "functions/actorfile_interface.h"

#define NO 0
#define YES 1
#define PAIR_LEN 2
#define SIZE 21
#define CLEAN_FILE_SIZE 23901921
#define ACTORS_PAIRS_SIZE 11500000
#define MAX_ROUTE_LEN 100


void add_conn(int *const conn_arr, const int new_conn_id)
{
    conn_arr[new_conn_id / (sizeof(unsigned int) * 8)] |= 1 << (new_conn_id % (sizeof(unsigned int) * 8));
}


void make_array(int actor_to_actor_arr[][2], FILE* f, int size)
{
	fread(&actor_to_actor_arr[0][0], sizeof(int) * 2, size, f);
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


static int queue[ACTORS_PAIRS_SIZE] = { 0 }; // очередь для вершин для поиска в ширину
static int visited[ACTORS_PAIRS_SIZE / 32 + 1] = { 0 }; // список посещенных вершин


void make_tree(int *main_tree, int actors_pairs[][PAIR_LEN],
    const int size_of_actors, const int from) // id of main vertex of tree (Bacon's)
{
    int cur_pos = 0, max_pos = 0; // начало, конец очереди
    int id = from;
    int cur_id, index, k = 0;
    // all variables higher were unsigned (but it can be the problem when we would link funcs???????)

    main_tree[id] = -1;
    add_conn(visited, id);
    queue[max_pos++] = id;

    while(cur_pos < max_pos) // пока очередь не пуста
    {
        if (k % 1000000 == 0)
            printf("%d\n", k / 1000000);
        // printf("\nqueue:  ");
        // for (int i = cur_pos; i < max_pos; i++)
        //     printf("%d   ", queue[i]);
        id = queue[cur_pos++]; // берем следующего по очереди актера
        index = get_pos_by_id(actors_pairs, id, size_of_actors, 0);
        if (index == -1)
            continue;
        while (actors_pairs[index][0] == id) // найдем все необработанные связи для этого актера...
        {
            cur_id = actors_pairs[index++][1];
            if (!get_conn(visited, cur_id)) // если найдена связь и она еще не была обработана
            {
                k++;
                add_conn(visited, cur_id); // добавить связь в обработанные
                queue[max_pos++] = cur_id; // добавить данного актера в очередь
                // printf("in%d", cur_id);
                main_tree[cur_id] = id; // записать данные для данного актера
                // printf("out");
            }
        }
    }
}


int get_route(const int *const main_tree, int index, int *const route)
{
    int i = 0;
    route[i++] = index;
    if (main_tree[index] == 0)
        return -1;
    while(main_tree[index] != -1)
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

    static int main_pairs_arr[CLEAN_FILE_SIZE][PAIR_LEN];
    static int main_tree[ACTORS_PAIRS_SIZE];
    int route[MAX_ROUTE_LEN];
    int from, to, size;
    FILE *f, *f_in;
    char actor[100];


    f = fopen("functions/clean_actors_file.bin", "rb");
    make_array(main_pairs_arr, f, CLEAN_FILE_SIZE);
    // int index = get_pos_by_id(main_pairs_arr, 262632, CLEAN_FILE_SIZE, 0);
    // printf("%d", index);
    // for (int i = index; main_pairs_arr[i][0] == 262632; i++)
    //     printf("%d\n", main_pairs_arr[i][1]);
    // my_sort(main_pairs_arr, 0, CLEAN_FILE_SIZE - 1, 0);
    // printf("sorted %d  %d\n", main_pairs_arr[1][0], main_pairs_arr[1][1]);

    f_in = fopen("data/ID_NAME_NODUPS.bin", "rb");

    read_actor:
    printf("Введите актера, для которого нужно вычислить расстояния: ");
    gets(actor);
    from = get_id_by_name(f_in, actor);

    if (from == NO_MATCHES)
    {
        printf("Данный актёр в базе не найден.\n");
        goto read_actor;
    }
    /*
    qwerty:
    printf("Введите актера, для которого нужно вычислить расстояния: ");
    scanf("%d", &from);
    if (get_pos_by_id(main_pairs_arr, from, CLEAN_FILE_SIZE, 0) == -1)
        goto qwerty;
    */
    // for (int i = 0; i < 1200; i++)
    //     printf("%d   %d\n", main_pairs_arr[i][0], main_pairs_arr[i][1]);
    make_tree(main_tree, main_pairs_arr, CLEAN_FILE_SIZE, from);
/*
    int k = 0;
    for (int i = 1; i < ACTORS_PAIRS_SIZE; i++)
    {
        size = get_route(main_tree, i, route);
        if (size - 1 >= 8)
        {
            printf("%d  ", size - 1);
            k += size - 1;
        }
    }
    printf("\n\nsumm: %d\n", k);
*/
    // while (strcmp(actor, "exit"))


    while (1)
    {

        read_actor_to:
        printf("Введите актера, от которого нужно вычислить расстояние до первоначального: ");
        gets(actor);
        // scanf("%d", &to);
        to = get_id_by_name(f_in, actor);
        if (to == NO_MATCHES)
        {
            printf("Данный актёр в базе не найден.\n");
            goto read_actor_to;
        }

        size = get_route(main_tree, to, route);
        if (size > -1)
        {
            printf("\nРАССТОЯНИЕ = %d\n", size - 1);

            printf("ПУТЬ:    ");
            for (int i = 0; i < size; i++)
            {
                get_name_by_id(f_in, route[i], actor);
                printf("%d %s -> ", route[i], actor);
            }

            printf("\n");
        }
        else
            printf("No connection\n");
    }
    return 0;
}

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


void make_array(int actor_to_actor_arr[][PAIR_LEN], FILE *const f, const int size)
{
    fread(&actor_to_actor_arr[0][0], sizeof(int) * PAIR_LEN, size, f);
}


unsigned int get_conn(int *const conn_arr, const int id)
{
    return conn_arr[id / (sizeof(unsigned int) * 8)] & (1 << (id % (sizeof(unsigned int) * 8)));
}


int is_less(const int *const elem_1, const int *const elem_2, const int index)
{
    if (elem_1[index] < elem_2[index] || (elem_1[index] == elem_2[index] &&
        elem_1[(index + 1) % 2] < elem_2[(index + 1) % 2]))
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

void my_sort(int main_matr[][PAIR_LEN], const int begin, const int end, const int index)
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

    main_tree[id] = -1;
    add_conn(visited, id);
    queue[max_pos++] = id;

    while(cur_pos < max_pos) // пока очередь не пуста
    {   
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
                main_tree[cur_id] = id; // записать данные для данного актера
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
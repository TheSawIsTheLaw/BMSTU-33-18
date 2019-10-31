#define SIZE 3694389
#define NO 0
#define YES 1
#define PAIR_LEN 2


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

void create_mas(int arr[][2], int *size, char *filename)
{
    FILE *f = fopen(filename, "rb");
    *size = 0;
    int id;
    while (*size != SIZE)
    {
        fread(&id, sizeof(int), 1, f);
        if (id == -1)
            continue;
        arr[*size][0] = id;
        fread(&arr[*size][1], sizeof(int), 1, f);
        (*size)++;
    }
    fclose(f);
}

void copy_mas(int source[][2], int destination[][2])
{
    for (int i = 0;i < SIZE; i++)
    {
        destination[i][0] = source[i][0];
        destination[i][1] = source[i][1];
    }
}

// Сортировка по фильмам
void sort_by_films(int arr[][2])
{
    my_sort(arr, 0, SIZE - 1, 0);
}

// Сортировка по актерам
void sort_by_actors(int arr[][2])
{
    my_sort(arr, 0, SIZE - 1, 1);
}

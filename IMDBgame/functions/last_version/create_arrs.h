#define SIZE 3694389

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
    //my_sort(arr, 0, SIZE - 1, 0);
}

// Сортировка по актерам
void sort_by_actors(int arr[][2])
{
    //my_sort(arr, 0, SIZE - 1, 1);
}

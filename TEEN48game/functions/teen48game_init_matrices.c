#include "../f_headers/teen48game_init_matrices.h"
#include<stdlib.h>


#define ERROR_ARR_SIZE 1000
#define SUCCESS 0
#define PLAYERS_COUNT 5

void nulled(matrix_t *const matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            matrix->matrix[i][j] = 0;
        }
    }
}

int init_matrices(matrix_t *const matrix_array, const int arr_size, const double procent)
{
    if (arr_size <= 0)
    {
        return ERROR_ARR_SIZE;
    }

    for (int i = 0; i < arr_size; i++)
    {
        nulled(&matrix_array[i]);
    }

    int count_el = procent * matrix_array[0].rows * matrix_array[0].columns / 100;
    int not_null_count = 0;
    int temp_row;
    int temp_column;
    int temp_item;

    while (not_null_count != count_el)
    {
        temp_row = rand() % matrix_array[0].rows;
        temp_column = rand() % matrix_array[0].columns;

        if (matrix_array[0].matrix[temp_row][temp_column] == 0)
        {
            temp_item = rand() % 10;
            if (temp_item <= 8)
                temp_item = 2;
            else
                temp_item = 4;
            for (int i = 0; i < arr_size; i++)
            {
                matrix_array[i].matrix[temp_row][temp_column] = temp_item;
            }
            not_null_count++;
        }
    }
    return SUCCESS;
}


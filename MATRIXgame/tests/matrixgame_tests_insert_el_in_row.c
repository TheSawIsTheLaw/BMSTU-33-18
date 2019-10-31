#include "../headers/matrixgame_headers_insert_el_in_row.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#include<stdlib.h>

#define NO_ERR 0
#define PASSED 0
#define FAILED 1

int matrix_compare(matrix_t tmp_matrix, matrix_t res_matrix)
{
    if (tmp_matrix.rows == res_matrix.rows && tmp_matrix.columns == res_matrix.columns)
    {
        for (int i = 0; i < res_matrix.rows; i++)
            for (int j = 0; j < res_matrix.columns; j++)
                if (tmp_matrix.matrix[i][j] != res_matrix.matrix[i][j])
                    return 0;
        
        return 1; 
    }
    
    return 0;
}

int matrixgame_insert_el_in_row_test_1()
{
    matrix_t tmp_matrix;
    
    tmp_matrix.rows = 3;
    tmp_matrix.columns = 3;
    
    tmp_matrix.matrix = (int **) malloc(tmp_matrix.rows * sizeof(int *));
    for (int i = 0; i < tmp_matrix.rows; i++)
    {
        (tmp_matrix.matrix)[i] = (int *) malloc(tmp_matrix.columns * sizeof(int));
        for (int j = 0; j < tmp_matrix.columns; j++)
            tmp_matrix.matrix[i][j] = 1;
    }

    matrix_t res_matrix;

    res_matrix.rows = 3;
    res_matrix.columns = 4;
    int res_arr[] = { 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 0 };
    
    res_matrix.matrix = (int **) malloc(res_matrix.rows * sizeof(int *));
    
    int arr_ind = 0;
    for (int i = 0; i < res_matrix.rows; i++)
    {
        (res_matrix.matrix)[i] = (int *) malloc(res_matrix.columns * sizeof(int));
        for (int j = 0; j < res_matrix.columns; j++)
        {
            res_matrix.matrix[i][j] = res_arr[arr_ind];
            arr_ind++;
        }
    }

    int index_row = 1;
    int index_column = 2;
    int el = 3;
  
    if (insert_el_in_row(&tmp_matrix, index_row, index_column, el) == NO_ERR)
    {
        if (matrix_compare(tmp_matrix, res_matrix))
        {
            for (int i = 0; i < tmp_matrix.rows; i++)
                free(tmp_matrix.matrix[i]);

            free(tmp_matrix.matrix);
        
            return PASSED;
        }
    }

    for (int i = 0; i < tmp_matrix.rows; i++)
        free(tmp_matrix.matrix[i]);

    free(tmp_matrix.matrix);
    
    return FAILED;
}

int matrixgame_insert_el_in_row_test_2()
{
    matrix_t tmp_matrix;

    tmp_matrix.rows = 3;
    tmp_matrix.columns = 3;

    tmp_matrix.matrix = (int **) malloc(tmp_matrix.rows * sizeof(int *));
    for (int i = 0; i < tmp_matrix.rows; i++)
    {
        (tmp_matrix.matrix)[i] = (int *) malloc(tmp_matrix.columns * sizeof(int));
        for (int j = 0; j < tmp_matrix.columns; j++)
            tmp_matrix.matrix[i][j] = 1;
    }

    matrix_t res_matrix;

    res_matrix.rows = 3;
    res_matrix.columns = 4;
    int res_arr[] = { 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 0 };

    res_matrix.matrix = (int **) malloc(res_matrix.rows * sizeof(int *));

    int arr_ind = 0;
    for (int i = 0; i < res_matrix.rows; i++)
    {
        (res_matrix.matrix)[i] = (int *) malloc(res_matrix.columns * sizeof(int));
        for (int j = 0; j < res_matrix.columns; j++)
        {
            res_matrix.matrix[i][j] = res_arr[arr_ind];
            arr_ind++;
        }
    }

    int index_row = 10;
    int index_column = 20;
    int el = 3;

    if (insert_el_in_row(&tmp_matrix, index_row, index_column, el) != NO_ERR)
    {
        for (int i = 0; i < tmp_matrix.rows; i++)
            free(tmp_matrix.matrix[i]);

        free(tmp_matrix.matrix);

        return PASSED;
    }

    for (int i = 0; i < tmp_matrix.rows; i++)
        free(tmp_matrix.matrix[i]);

    free(tmp_matrix.matrix);

    return FAILED;
}

int main()
{
    if (matrixgame_insert_el_in_row_test_1() != PASSED)
    {
        return FAILED;
    }

    if (matrixgame_insert_el_in_row_test_2() != PASSED)
    {
        return FAILED;
    }

    return PASSED;
}


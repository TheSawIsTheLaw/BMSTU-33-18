#include<stdlib.h>
//#include<stdio.h>

#include "../headers/matrixgame_headers_insert_el_in_row.h"
#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_errno.h"

#define MEM_ERR -808  // Memory error: array of pointers or values was not allocated right.
#define EL_IND_ERR -809  // Element index error: element's index is not coorect. 

/*int **matrix_allocate(int **matrix, const int row_num, const int col_num)
{
    matrix = (int **) malloc(row_num * sizeof(int *));
    for (int i = 0; i < row_num; i++)
        matrix[i] = (int *) malloc(col_num * sizeof(int));
    
    return matrix;
}

void matrix_filling(int **matrix, const int row_num, const int col_num)
{
    for (int i = 0; i < row_num; i++)
        for (int j = 0; j < col_num; j++)
                matrix[i][j] = 1;

}

void matrix_output(int **matrix, const int row_num, const int col_num)
{
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}*/

/*
  Выделяет дополнительную память для каждой строки матрицы.
  Присваивает значение 0 всем элементам последнего столбца матрицы.
*/

int one_pos_shifting(matrix_t *const matrix)
{
    matrix->columns = matrix->columns + 1;

    for (int i = 0; i < matrix->rows; i++)
    {
        *((matrix->matrix) + i) = (int *) realloc((matrix->matrix)[i],  matrix->columns * sizeof(int *));
        if (!*((matrix->matrix) + i))
            return MEM_ERR;

        *(*((matrix->matrix) + i) + (matrix->columns - 1)) = 0;
    }

    return 0;
}

/*
  Смещает элементы строки, в которую нужно добавить элемент
  на одну позицию с индекса нового элемента.
  Записывает новый элемент на освободишвуюся позицию.
*/

int insert_el_in_row(matrix_t *const matrix, int index_row, int index_column, int el)
{
    if (one_pos_shifting(matrix) != MEM_ERR)
    {
        if (index_row < matrix->rows && index_column < matrix->columns)
        {
            for (int i = (matrix->columns) - 1; i > index_column; i--)
                *(*((matrix->matrix) + index_row) + i) = *(*((matrix->matrix) + index_row) + (i - 1));

            *(*((matrix->matrix) + index_row) + index_column) = el;
    
            return 0;
        }

        return EL_IND_ERR;
    }

    return MEM_ERR;
}

/* Test:
 
int main()
{
    matrix_t M;
    M.rows = 3;
    M.columns = 4;

    M.matrix = matrix_allocate(M.matrix, M.rows, M.columns);
    matrix_filling(M.matrix, M.rows, M.columns);
    matrix_output(M.matrix, M.rows, M.columns);

    insert_el_in_row(&M, 2, 2, 8);
    matrix_output(M.matrix, M.rows, M.columns);
}*/   

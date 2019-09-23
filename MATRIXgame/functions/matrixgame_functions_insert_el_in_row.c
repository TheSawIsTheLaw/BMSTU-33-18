#include<stdlib.h>

#include "../headers/matrixgame_headers_insert_el_in_row.h"
#include "../headers/matrixgame_errno.h"

#define MEM_ERR -808

/*
  Выделяет дополнительную память для каждой строки матрицы.
  Присваивает значение 0 всем элементам последнего столбца матрицы.
*/

int one_pos_shifting(matrix_t *const matrix)
{
    matrix->columns = matrix->columns + 1;

    for (int i = 0; i < matrix->rows; i++)
    {
        (matrix->matrix)[i] = (int *) realloc((matrix->matrix)[i],  matrix->columns * sizeof(int *));
        if (!(matrix->matrix)[i])
            return MEM_ERR;
        (matrix->matrix)[i][(matrix->columns) - 1] = 0;
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
    if (one_pos_shifting(matrix))
    {
        for (int i = (matrix->columns) - 1; i > index_column; i--)
            (matrix->matrix)[index_row][i] = (matrix->matrix)[index_row][i - 1];

        (matrix->matrix)[index_row][index_column] = el;
    
        return 0;
    }

    return MEM_ERR;
}

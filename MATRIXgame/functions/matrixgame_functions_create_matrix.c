#include <stdlib.h>

#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../../ARRgame/headers/arrgame_headers_create.h"
#include "../../ARRgame/functions/arrgame_functions_create.c"

typedef int mtype;

/*
  Освобождает выделнную за диапазаном указателей память.
  @start - указатель на начало диапазона указателей.
  @end - указатель на конец диапазона указателей.
 */
static void clean_up_row_pointers(mtype *const * start, mtype *const *const end)
{
    for (; start < end; start++)
        free(*start);
}

#define MEM_ALLOC_FAILURE -101  /* Ошибка выделения памяти */

/*
  Выделяет память для матрицы, описанной в переданной
  через указатель структуре matrix_t.
  @matrix - указатель на структуру, описывающую матрицу.
  @columns - число столбцов
  @rows - число строчек
  @return Возвращает MEM_ALLOC_FAILURE, если не хватает памяти или 0, если успех.
 */
int create_matrix(matrix_t *const matrix, const int rows, const int columns)
{
    void *temp = malloc(sizeof(mtype*) * rows);
    if (!temp)
        return MEM_ALLOC_FAILURE;

    matrix->matrix = (mtype**)temp;

    mtype *const *const end = matrix->matrix + rows;
    for (mtype** cur = matrix->matrix; cur < end; cur++)
    {
        temp = create(columns);
        if (!temp)
        {
            clean_up_row_pointers(matrix->matrix, cur);
            free(matrix->matrix);
            return MEM_ALLOC_FAILURE;
        }
        
        *cur = (mtype*)temp;
    }

    matrix->columns = columns;
    matrix->rows = rows;

    return 0;
}


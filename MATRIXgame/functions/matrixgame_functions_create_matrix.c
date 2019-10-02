#include <stdlib.h>

#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../../ARRgame/functions/arrgame_functions_create.c"

typedef int mtype;

#define MEM_ALLOC_FAILURE -101  /* Ошибка выделения памяти */
#define SERVICE_DATA_OFFSET -3  /* длинна метаданых в arrgame */
#define SUCCESS 0               /* успех */

/**
 * \brief Освобождает выделнную за диапазаном указателей память.
 * \param[in] start - Указатель на начало диапазона указателей
 * \param[in] end - Указатель на конец диапазона указателей.
 */
static void clean_up_row_pointers(mtype *const * start, mtype *const *const end)
{
    for (; start < end; start++)
        free((*start) + SERVICE_DATA_OFFSET);
}

/**
 * \brief Создаёт матрицу
 * \details Выделяет память для матрицы, описанной в переданной
 *             через указатель структуре matrix_t
 *
 * \param[out] matrix - Указатель на структуру, описывающую матрицу
 * \param[in] rows - Число столбцов
 * \param[in] columns - Число строчек
 * \return Код ошибки
 * \retval SUCCESS Успех, без ошибки
 * \retval MEM_ALLOC_FAILURE Ошибка при выделении памяти
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

    return SUCCESS;
}


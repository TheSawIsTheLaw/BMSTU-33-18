/**
 * \file matrixgame_functions_create_matrix.c
 * \brief Функция, создающая матрицу
 */

#include <stdlib.h>

#include "../../ARRgame/functions/arrgame_functions_create.c"
#include "../headers/matrixgame.h"

typedef int mtype;

/**
 * \def MEM_ALLOC_FAILURE
 * \brief Код ошибки: выделить память не удалось
 */
#define MEM_ALLOC_FAILURE -101
/**
 * \def SERVICE_DATA_OFFSET
 * \brief Сервисная переменная метаданых из ARRgame
 */
#define SERVICE_DATA_OFFSET -3
/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0

/**
 * \fn static void clean_up_row_pointers(mtype *const * start, mtype *const *const end)
 *
 * \param mtype *const * start - Указатель на начало диапозона указателей
 * \param mtype *const *const end - Указатель на конец диапазона указателей
 *
 * \brief Освобождает выделенную за диапазаном указателей память
 */
static void clean_up_row_pointers(mtype *const * start, mtype *const *const end)
{
    for (; start < end; start++)
        free((*start) + SERVICE_DATA_OFFSET);
}

/**
 * \fn int create_matrix(matrix_t *const matrix, const int rows, const int columns)
 *
 * \param matrix_t *const matrix - Указатель для создания матрицы
 * \param const int rows - Количество строк матрицы
 * \param const int columns - Количество столбцов матрицы
 *
 * \brief Создаёт матрицу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_create_matrix(matrix_t *const matrix, const int rows, const int columns)
{
    void *temp = malloc(sizeof(mtype*) * rows);
    if (!temp)
        return MEM_ALLOC_FAILURE;

    matrix->matrix = (mtype**)temp;

    mtype *const *const end = matrix->matrix + rows;
    for (mtype** cur = matrix->matrix; cur < end; cur++)
    {
        temp = arrgame_create(columns);
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

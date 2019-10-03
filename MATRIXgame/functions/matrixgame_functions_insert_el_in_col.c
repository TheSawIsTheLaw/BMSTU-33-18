/**
 * \file matrixgame_functions_insert_el_in_col.c
 * \brief Функция, добавляющая элемент в столбец матрицы с её расширением по
 * количеству строк
 */

#include <stdlib.h>

#include "../headers/matrixgame_headers_insert_el_in_col.h"
#include "../headers/matrixgame_headers_matrix_t.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def APPEND_ROW_ERROR
 * \brief Код ошибки: выделить память под новую строку не удалось
 */
#define APPEND_ROW_ERROR 100
/**
 * \def EXTEND_MATRIX_ERROR
 * \brief Код ошибки: выделить память под новую матрицу не дулаось
 */
#define EXTEND_MATRIX_ERROR 110
/**
 * \def ELEM_INDEX_ERROR
 * \brief Код ошибки: индекс недоступен
 */
#define ELEM_INDEX_ERROR 200

/**
 * \def INVALID_INDICES
 * \brief Недоступные индексы вставки
 */
#define INVALID_INDICES 0
/**
 * \def VALID_INDICES
 * \brief Доступные индексы вставки
 */
#define VALID_INDICES 1


/**
 * \fn int append_row(matrix_t *const matrix)
 *
 * \param matrix_t *const matrix Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Добавляет строку к матрице снизу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
int append_row(matrix_t *const matrix)
{
    matrix->matrix = (int **)realloc(matrix->matrix,  (matrix->rows + 1) * sizeof(int *));
    if (!matrix->matrix)
        return EXTEND_MATRIX_ERROR;

    *((matrix->matrix) + matrix->rows) = (int *)calloc(matrix->columns, sizeof(int));
    if (!*((matrix->matrix) + matrix->rows))
        return APPEND_ROW_ERROR;

    (matrix->rows)++;

    return SUCCESS;
}

/**
 * \fn int check_indices(const matrix_t *const matrix, const int i, const int j)
 *
 * \param const matrix_t *const matrix Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int i Индекс строки
 * \param const int j Индекс столбца
 *
 * \brief Проверка индекса
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
int check_indices(const matrix_t *const matrix, const int i, const int j)
{
    if ((i < 0) || (j < 0))
        return INVALID_INDICES;

    if ((matrix->rows < i) || (matrix->columns <= j))
        return INVALID_INDICES;

    return VALID_INDICES;
}

/**
 * \fn int insert_el_in_col(matrix_t *const matrix, const int index_row, const int index_column, const int el)
 *
 * \param matrix_t *const matrix Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int index_row Индекс строки вставки
 * \param const int index_column Индекс столбца вставки
 * \param const int el Элемент вставки
 *
 * \brief Функция, добавляющая элемент в столбец матрицы с её расширением по
 * количеству строк
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
int insert_el_in_col(matrix_t *const matrix, const int index_row, const int index_column, const int el)
{
    if (append_row(matrix) == SUCCESS)
    {
        if (check_indices(matrix, index_row, index_column) == VALID_INDICES)
        {
            for (int i = (matrix->rows) - 1; i > index_row; i--)
                *(*((matrix->matrix) + i) + index_column) = *(*((matrix->matrix) + (i - 1)) + index_column);

            *(*((matrix->matrix) + index_row) + index_column) = el;
            return SUCCESS;
        }

        return ELEM_INDEX_ERROR;
    }

    return APPEND_ROW_ERROR;
}

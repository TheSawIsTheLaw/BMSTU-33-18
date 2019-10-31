/**
 * \file matrixgame_functions_add_row.c
 * \brief Функция, добавляющая элемент строчку матрице
 */
#include <stdlib.h>

#include "../headers/matrixgame.h"
#include "../headers/matrixgame.h"

/**
 * \def OK
 * \brief Код удачного завершения подпрограммы
 */
#define OK                      0
/**
 * \def ALLOC_ERROR
 * \brief Код ошибки: выделить память под новую строку не удалось
 */
#define ALLOC_ERROR            -1
/**
 * \def INDEX_OUT_OF_THE_RANGE
 * \brief Код ошибки: индекс строки выходит за пределы матрицы
 */
#define INDEX_OUT_OF_THE_RANGE -2
/**
 * \def EMPTY_POINTER
 * \brief Код ошибки: в функцию был передан пустой указатель
 */
#define EMPTY_POINTER          -3

/**
 * \fn int my_realloc(matrix_t *matrix)
 *
 * \param matrix_t *matrix - Указатель на особо заданную матрицу (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Выделяет память под новую строку
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
static int my_realloc(matrix_t *matrix)
{
    matrix->rows += 1;
    matrix->matrix = (int**)realloc(matrix->matrix,matrix->rows * sizeof(int*));

    if (matrix->matrix == NULL)
    {
        for (int i = 0; i < matrix->rows; i++)
            free(*((matrix->matrix)+ i));

        return ALLOC_ERROR;
    }

    return OK;
}
/**
 * \fn int add_row(matrix_t *matrix, const int index)
 *
 * \param matrix_t *matrix - Указатель на особо заданную матрицу (см. matrixgame_
 * functions_create_matrix)
 * \param const int index - Индекс вставки новой строки
 *
 * \brief Вставляет новую строку в матрицу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_add_row(matrix_t *matrix, const int index)
{
    int rc = OK;

    if (matrix->rows + 1 < index || index < 0)
    {
        rc = INDEX_OUT_OF_THE_RANGE;

        return rc;
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        if ((matrix->matrix + i) == NULL)
        {
            rc = EMPTY_POINTER;

            return rc;
        }
    }

    rc = my_realloc(matrix);

    if (rc != OK)
        return rc;

    // Сдвигаем строки
    for (int i = matrix->rows; i > index; i--)
        *(matrix->matrix + i) = *(matrix->matrix + i - 1);

    // Обнуляем новую строку
    for (int j = 0; j < matrix->columns; ++j)
        *(*((matrix->matrix) + index) + j) = 0;

    return rc;
}

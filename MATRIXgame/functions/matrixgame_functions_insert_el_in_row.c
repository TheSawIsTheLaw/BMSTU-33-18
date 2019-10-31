/**
 * \file matrixgame_functions_insert_el_in_row.c
 * \brief Функция, добавляющая элемент в строку матрицы с её расширением по
 * количеству столбцов
 */
#include <stdlib.h>

#include "../headers/matrixgame.h"

/**
 * \def R_I
 * \brief Код, символизирующий верно переданные данные в функцию
 */
#define R_I 1  // Right input.

/**
 * \def NO_ERR
 * \brief Код удачного завершения подпрограммы
 */
#define NO_ERR 0  // No errors.
/**
 * \def EXTEND_MATRIX_ERROR
 * \brief Код ошибки: выделить память под новую матрицу не дулаось
 */
#define MEM_ERR -808  // Memory error: array of pointers or values was not allocated right.
/**
 * \def EXTEND_MATRIX_ERROR
 * \brief Код ошибки: в функцию были переданы некорректные индексы
 */
#define EL_IND_ERR -809  // Element index error: element's index is not coorect.

/*
  Проверка позиции, на которую будет вставлен элемент
  (ind >= 0 и ind <= rows/columns).
*/
/**
 * \fn int is_index_correct(const int rows, const int columns, const int index_row, const int index_column)
 *
 * \param const int rows - Количество доступных строк в переданной матрице
 * \param const int columns - Количество доступных столбцов в переданной матрице
 * \param const int index_row - Переданный в функцию индекс строки вставки
 * \param const int index_column - Переданный в функцию индекс столбца вставки
 *
 * \brief Проверка корректности переданных в функцию данных
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
static int is_index_correct(const int rows, const int columns, const int index_row, const int index_column)
{
    if (index_row >= 0 && index_column >= 0 && index_row <= rows && index_column <= columns)
        return R_I;

    return EL_IND_ERR;
}

/*
  Выделяет дополнительную память для каждой строки матрицы.
  Присваивает значение 0 всем элементам последнего столбца матрицы.
*/
/**
 * \fn int append_row(matrix_t *const matrix)
 *
 * \param matrix_t *const matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Добавляет строки матрице
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
static int one_pos_shifting(matrix_t *const matrix)
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
/**
 * \fn int insert_el_in_row(matrix_t *const matrix, int index_row, int index_column, int el)
 *
 * \param matrix_t *const matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int index_row - Индекс строки вставки
 * \param const int index_column - Индекс столбца вставки
 * \param const int el - Элемент вставки
 *
 * \brief Функция, добавляющая элемент в строку матрицы с её расширением по
 * количеству столбцов
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_insert_el_in_row(matrix_t *const matrix, int index_row, int index_column, int el)
{
    if (one_pos_shifting(matrix) != MEM_ERR)
    {
        if (is_index_correct(matrix->rows, matrix->columns, index_row, index_column) != EL_IND_ERR)
        {
            for (int i = (matrix->columns) - 1; i > index_column; i--)
                *(*((matrix->matrix) + index_row) + i) = *(*((matrix->matrix) + index_row) + (i - 1));

            *(*((matrix->matrix) + index_row) + index_column) = el;

            return NO_ERR;
        }

        return EL_IND_ERR;
    }

    return MEM_ERR;
}

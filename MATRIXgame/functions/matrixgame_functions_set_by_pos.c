/**
 * \file matrixgame_functions_set_by_pos.c
 * \brief Функция, устанавливающее значение в определённой ячейке матрицы
 */

#include "../headers/matrixgame.h"

/**
 * \def RANGE_ERROR
 * \brief Код ошибки: в функцию были переданы некорректные значения индексов
 */
#define RANGE_ERROR 11
/**
 * \def EXTEND_MATRIX_ERROR
 * \brief Код ошибки: в функцию был передан пустой указатель
 */
#define POINTER_ERROR 12
/**
 * \def PASSED
 * \brief Код удачного завершения подпрограммы или программы
 */
#define PASSED 0

// To refer to the begining of something
#define INITIAL 0

/**
 * \fn int set_by_pos(const matrix_t *const init_matrix, const int index_row, const int index_column, const int el)
 *
 * \param const matrix_t *const init_matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int index_row - Индекс строки передачи значения
 * \param const int index_column - Индекс столбца передачи значения
 * \param const int el - Передаваемое в ячейку значение
 *
 * \brief Устанавливает значение элемента матрицы
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_set_by_pos(const matrix_t *const init_matrix, const int index_row, const int index_column, const int el)
{
    if (index_row < INITIAL || index_column < INITIAL || index_row >= init_matrix->rows || index_column >= init_matrix->columns)
        return RANGE_ERROR;

    for (int row = INITIAL; row < init_matrix->rows; ++row)
    {
        for (int column = INITIAL; column < init_matrix->columns; ++column)
        {
            if (!(init_matrix->matrix + row))
            {
                return POINTER_ERROR;
            }
        }
    }

    *(*(init_matrix->matrix + index_row) + index_column) = el;

    return PASSED;
}

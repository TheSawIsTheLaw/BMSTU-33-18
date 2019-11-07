/**
 * \file teen48game_read_sizes.c
 * \brief Функция, считывающая размеры матрицы
 */

#include "../f_headers/teen48game_read_sizes.h"

/**
 * \def READ_OK
 * \brief Код удачного считывания размера
 */
#define READ_OK 1
/**
 * \def MATRIX_MAX_SIZE
 * \brief Максимальный размер матрицы
 */
#define MATRIX_MAX_SIZE 100
/**
 * \def ERROR_PRINT
 * \brief Текст ошибки
 */
#define ERROR_PRINT "Количество %s матрицы должно быть больше 0, но не более 100"

/**
 * \def INVALID_INPUT
 * \brief Некорректный ввод
 */
#define INVALID_INPUT 1
/**
 * \def INVALID_ROWS
 * \brief Некорректное количество строк матрицы
 */
#define INVALID_ROWS 2
/**
 * \def INVALID_COLUMNS
 * \brief Некорректное количество столбцов матрицы
 */
#define INVALID_COLUMNS 3
/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0

/**
 * \fn int read_sizes(int *const rows, int *const columns, FILE *stream)
 *
 * \param int *const rows - Количество строк матрицы
 * \param int *const columns - Количество стобцов матрицы
 * \param FILE *stream - файловый дискриптор потока вывода
 *
 * \brief Считывает размеры матрицы
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
int read_sizes(int *const rows, int *const columns, FILE *stream)
{
    puts("Введите количество строк матрицы: ");
    if (fscanf(stream, "%d", rows) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (*rows < 0 || *rows > MATRIX_MAX_SIZE)
    {
        fprintf(stderr, ERROR_PRINT, "строк");
        return INVALID_ROWS;
    }

    puts("Введите количество столбцов матрицы: ");
    if (fscanf(stream, "%d", columns) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (*columns < 0 || *columns > MATRIX_MAX_SIZE)
    {
        fprintf(stderr, ERROR_PRINT, "столбцов");
        return INVALID_ROWS;
    }

    return OK;
}


/**
 * \file matrixgame_functions_shift_matrix.c
 * \brief Функция, смещающая ненулевые элементы матрицы к одному краю
 */
#include "../headers/matrixgame.h"

/**
 * \def DIRECTION_ERROR
 * \brief Код ошибки: в функцию был передан символ, не обозначающий направление
 */
#define DIRECTION_ERROR 11
/**
 * \def POINTER_ERROR
 * \brief Код ошибки: в функцию был передан пустой указатель
 */
#define POINTER_ERROR 12
/**
 * \def SIZE_ERROR
 * \brief Код ошибки: в функцию была передана матрица неверного размера
 */
#define SIZE_ERROR 13
/**
 * \def PASSED
 * \brief Код удачного завершения подпрограммы или программы
 */
#define PASSED 0

// To refer to the begining of something
#define INITIAL 0
// Zero element in matrix
#define EMPTY 0
// The matrix size
#define SIZE 4
// The minimal step in moving through matrix
#define STEP 1
/**
 * \fn int matrixgame_shift_matrix(matrix_t *init_matrix, const char dir)
 *
 * \param matrix_t *init_matrix Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const char dir Символ, отвечающий за направление смещения
 *
 * \brief Смещает ненулевые элементы матрицы в заданном направлении
 *
 * \return Код ошибки (отличное от нуля число) или
 * код успешного завершения
 */

int matrixgame_shift_matrix(matrix_t *init_matrix, const char dir)
{
   // Error: given symbol can't tell the direction
   if (dir != 'l' && dir != 'r' && dir != 'u' && dir != 'd')
   {
    return DIRECTION_ERROR;
   }

   // Error: matrix is not of a right size
   if (init_matrix->rows != SIZE || init_matrix->columns != SIZE)
   {
       return SIZE_ERROR;
   }

   // Error: false pointer 
   for (int i = INITIAL; i < SIZE; ++i)
   {
        for (int j = INITIAL; j < SIZE; ++j)
        {
            if (!(init_matrix->matrix + i))
            {
                return POINTER_ERROR;
            }
        }
   }

   // Direction: up (always going opposite direction in this algorithm though)
   if (dir == 'u')
   {
    // Going for three times (for matrix 4x4) - element can't move more than that
    for (int times = INITIAL; times < SIZE - 1; times ++)
    {
      // Changing places with upper element if the move have to be done
        for (int i = 1; i < SIZE; i ++)
        {
            for (int j = INITIAL; j < SIZE; j ++)
            {
                if ((*(*(init_matrix->matrix + i - STEP) + j) == EMPTY) && (*(*(init_matrix->matrix + i) + j) != EMPTY))
                {
                    *(*(init_matrix->matrix + i - STEP) + j) = *(*(init_matrix->matrix + i) + j);
                    *(*(init_matrix->matrix + i) + j) = INITIAL;
                }
            }
        }
    }
   }

   // Direction: down
   if (dir == 'd')
   {
    for (int times = INITIAL; times < SIZE - 1; times ++)
    {
        for (int i = SIZE - 2; i > -1; i --)
        {
            for (int j = INITIAL; j < SIZE; j ++)
            {
                if ((*(*(init_matrix->matrix + i + STEP) + j) == EMPTY) && (*(*(init_matrix->matrix + i) + j) != EMPTY))
                {
                    *(*(init_matrix->matrix + i + STEP) + j) = *(*(init_matrix->matrix + i) + j);
                    *(*(init_matrix->matrix + i) + j) = INITIAL;
                }
            }
        }
    }
   }
  
   // Direction: right
   if (dir == 'r')
   {
    for (int times = INITIAL; times < SIZE - 1; times ++)
    {
        for (int i = SIZE - 2; i > -1; i --)
        {
            for (int j = INITIAL; j < SIZE; j ++)
            {
                if ((*(*(init_matrix->matrix + j) + i + STEP) == EMPTY) && (*(*(init_matrix->matrix + j) + i) != EMPTY))
                {
                    *(*(init_matrix->matrix + j) + i + STEP) = *(*(init_matrix->matrix + j) + i);
                    *(*(init_matrix->matrix + j) + i) = INITIAL;
                }
            }
        }
    }
   }

   // Direction: left
   if (dir == 'l')
   {
    for (int times = INITIAL; times < SIZE - 1; times ++)
    {
        for (int i = 1; i < SIZE; i ++)
        {
            for (int j = INITIAL; j < SIZE; j ++)
            {
                if ((*(*(init_matrix->matrix + j) + i - STEP) == EMPTY) && (*(*(init_matrix->matrix + j) + i) != EMPTY))
                {
                    *(*(init_matrix->matrix + j) + i - STEP) = *(*(init_matrix->matrix + j) + i);
                    *(*(init_matrix->matrix + j) + i) = INITIAL;
                }
            }
        }
    }
   }
  
   return PASSED;
}
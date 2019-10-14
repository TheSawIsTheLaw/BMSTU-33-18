#include "../f_headers/teen48game_to_step.h"
#include "../../MATRIXgame/headers/matrixgame_headers_matrix_t.h"
#include "../../MATRIXgame/headers/matrixgame_headers_transpose.h"

// Ключи
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'

// Коды возврата
#define OK 0
#define WRONG_DIMS 500
#define WRONG_KEY_ERROR 501

void change(int *const row, const int index_1, const int index_2)
{
    int temp = *(row + index_1);
    *(row + index_1) = *(row + index_2);
    *(row + index_2) = temp;
}

void reverse_rows(matrix_t *const field)
{
    for (int i = 0; i < field -> rows; i++)
    {
        for (int j = 0; j <= field -> columns / 2; j++)
        {
            change(*(field -> matrix + i), j, field -> columns - j - 1);
        }
    }
}

void move_left(int *const row, const int index, const int size)
{
    for (int i = index; i < size - 1; i++)
    {
        *(row + i) = *(row + i + 1); 
    }

    if (!*(row + size - 1))
    {
        *(row + size - 1) = 0;
    }
}

void move_right(int *const row, const int index, const int size)
{
    for (int i = index; i > 0; i--)
    {
        *(row + i) = *(row + i - 1);
    }

    if (!*(row))
    {
        *(row) = 0;
    }
}

void sum_left_row(int *const row, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (*(row + i) == *(row + i + 1))
        {
            *(row + i) *= 2;
            move_left(row, i, size);
        }   
    }
}

void sum_right_row(int *const row, const int size)
{
    for (int i = size - 1; i > 0; i++)
    {
        if (*(row + i) == *(row + i - 1))
        {
            *(row + i) *= 2;
            move_right(row, i, size);
        }   
    }
}

void sum_horizontal(matrix_t *const field, void (*move_side)(int *const, const int))
{
    for (int i = 0; i < field -> rows; i++)
    {
        for (int j = 0; j <= field -> columns / 2; j++)
        {
            (*move_side)(*(field -> matrix + i), field -> columns);
        }
    }
}

int sum_vertical(matrix_t *const field, void (*move_side)(int *const, const int))
{
    int error_code = OK;

    // Поворот на 90 градусов влево
    reverse_rows(field);
    if ((error_code = transpose(field)))
    {
        return error_code;
    }

    sum_horizonatal(field, move_side);

    // Обратный поворот
    if ((error_code = transpose(field)))
    {
        return error_code;
    }

    reverse_rows(field);

    return error_code;
}

int to_step(matrix_t *const field, const char key)
{
    int error_code = OK;

    if (field -> rows <= 0 || field -> columns <= 0)
    {
        return WRONG_DIMS;
    }

    switch (key)
    {
        case LEFT:
            sum_horizontal(field, sum_left_row);
            break;
        case RIGHT:
            sum_horizonatal(field, sum_right_row);
            break;
        case UP:
            if ((error_code = sum_vertical(field, sum_left_row)))
            {
                return error_code;
            }

            break;
        case DOWN:
            if ((error_code = sum_vertical(field, sum_right_row)))
            {
                return error_code;
            }

            break;
        default:
            return WRONG_KEY_ERROR;
    }

    return OK;
}
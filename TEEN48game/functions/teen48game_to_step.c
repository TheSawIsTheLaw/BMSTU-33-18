#include "../f_headers/teen48game_to_step.h"

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

    if (*(row + size - 1))
    { 
        *(row + size - 1) = 0;
    }
}

void move_right(int *const row, const int index)
{
    for (int i = index; i > 0; i--)
    {
        *(row + i) = *(row + i - 1);
    }

    if (*(row))
    {
        *(row) = 0;
    }
}

void sum_left_row(int *const row, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (*(row + i) == *(row + i + 1))
        {
            *(row + i) *= 2;
            move_left(row, i + 1, size);
        }   
    }
}

void sum_right_row(int *const row, const int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        if (*(row + i) == *(row + i - 1))
        {
            *(row + i) *= 2;
            move_right(row, i - 1);
        }   
    }
}

void sum_horizontal(matrix_t *const field, void (*move_side)(int *const, const int))
{
    for (int i = 0; i < field -> rows; i++)
    {
        (*move_side)(*(field -> matrix + i), field -> columns);
    }
}

int sum_vertical(matrix_t *const field, void (*move_side)(int *const, const int))
{
    int error_code = OK;

    // Поворот на 90 градусов влево
    reverse_rows(field);
    if ((error_code = matrixgame_transpose(field)))
    {
        return error_code;
    }

    sum_horizontal(field, move_side);

    // Обратный поворот
    if ((error_code = matrixgame_transpose(field)))
    {
        return error_code;
    }

    reverse_rows(field);

    return error_code;
}

int to_step(matrix_t *const matrix, const char key)
{
    int error_code = OK;

    if (matrix == NULL)
    {
        return WRONG_ARGUMENT;
    }

    if (matrix -> rows <= 0 || matrix -> columns <= 0)
    {
        return WRONG_DIMS;
    }

    switch (key)
    {
        case LEFT:

            if (matrixgame_shift_matrix(matrix, LEFT) != OK)
            {
                return MOVE_ERROR;
            }

            sum_horizontal(matrix, sum_left_row);
            break;

        case RIGHT:

            if (matrixgame_shift_matrix(matrix, RIGHT) != OK)
            {
                return MOVE_ERROR;
            }

            sum_horizontal(matrix, sum_right_row);
            break;

        case UP:

            if (matrixgame_shift_matrix(matrix, UP) != OK)
            {
                return MOVE_ERROR;
            }

            if ((error_code = sum_vertical(matrix, sum_left_row)))
            {
                return error_code;
            }

            break;

        case DOWN:

            if (matrixgame_shift_matrix(matrix, DOWN) != OK)
            {
                return MOVE_ERROR;
            }

            if ((error_code = sum_vertical(matrix, sum_right_row)))
            {
                return error_code;
            }

            break;

        default:
        
            return WRONG_KEY_ERROR;
    }

    return OK;
}
#include "../p_headers/teen48game_player_prohorova.h"
char teen48game_player_prohorova(matrix_t *const matrix_buffer, int (*to_step)(matrix_t *const, const char))
{
    int have_null_after_item_d = 0;
    int temp_item = 0;

    for(int j = 0; j < matrix_buffer->columns; j++)
    {
        temp_item = 0;
        for (int i = 0; i < matrix_buffer->rows; i++)
        {
            if (matrix_buffer->matrix[i][j] != 0 && temp_item == 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
            if (temp_item != 0 && matrix_buffer->matrix[i][j] == 0)
            {
                have_null_after_item_d = 1;
                continue;
            }
            if (temp_item == matrix_buffer->matrix[i][j] && matrix_buffer->matrix[i][j] != 0)
            {
                return 'd';
            }
            if (temp_item != matrix_buffer->matrix[i][j] && temp_item != 0 && matrix_buffer->matrix[i][j] != 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
        }
    }

    int have_null_after_item_u = 0;
    for(int j = 0; j < matrix_buffer->columns; j++)
    {
        temp_item = 0;
        for (int i = matrix_buffer->rows - 1; i >= 0; i--)
        {
            if (matrix_buffer->matrix[i][j] != 0 && temp_item == 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
            if (temp_item != 0 && matrix_buffer->matrix[i][j] == 0)
            {
                have_null_after_item_u = 1;
                continue;
            }
            if (temp_item == matrix_buffer->matrix[i][j] && matrix_buffer->matrix[i][j] != 0)
            {
                return 'u';
            }
            if (temp_item != matrix_buffer->matrix[i][j] && temp_item != 0 && matrix_buffer->matrix[i][j] != 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
        }
    }

    int have_null_after_item_r = 0;
    for (int i = 0; i < matrix_buffer->rows; i++)
    {
        temp_item = 0;
        for (int j = 0; j < matrix_buffer->columns; j++)
        {
            if (matrix_buffer->matrix[i][j] != 0 && temp_item == 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
            if (temp_item != 0 && matrix_buffer->matrix[i][j] == 0)
            {
                have_null_after_item_r = 1;
                continue;
            }
            if (temp_item == matrix_buffer->matrix[i][j] && matrix_buffer->matrix[i][j] != 0)
            {
                return 'r';
            }
            if (temp_item != matrix_buffer->matrix[i][j] && temp_item != 0 && matrix_buffer->matrix[i][j] != 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
        }
    }

    int have_null_after_item_l = 0;
    for (int i = 0; i < matrix_buffer->rows; i++)
    {
        temp_item = 0;
        for (int j = matrix_buffer->columns; j >= 0; j--)
        {
            if (matrix_buffer->matrix[i][j] != 0 && temp_item == 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
            if (temp_item != 0 && matrix_buffer->matrix[i][j] == 0)
            {
                have_null_after_item_l = 1;
                continue;
            }
            if (temp_item == matrix_buffer->matrix[i][j] && matrix_buffer->matrix[i][j] != 0)
            {
                return 'l';
            }
            if (temp_item != matrix_buffer->matrix[i][j] && temp_item != 0 && matrix_buffer->matrix[i][j] != 0)
            {
                temp_item = matrix_buffer->matrix[i][j];
                continue;
            }
        }
    }

    if (have_null_after_item_d == 1)
        return 'd';
    if (have_null_after_item_u == 1)
        return 'u';
    if (have_null_after_item_r == 1)
        return 'r';
    if (have_null_after_item_l == 1)
        return 'l';
    return 'd';
}
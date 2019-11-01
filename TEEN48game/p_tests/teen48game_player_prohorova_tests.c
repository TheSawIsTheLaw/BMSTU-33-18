#include<stdio.h>
#include "../p_headers/teen48game_player_prohorova.h"
#include "../f_headers/teen48game_to_step.h"
#include <matrixgame.h>

#define SUCCESS 0

void nulled_matrix(matrix_t *matrix_buffer)
{
    for (int i = 0; i < matrix_buffer->rows; i++)
    {
        for (int j = 0; j < matrix_buffer->columns; j++)
            matrix_buffer->matrix[i][j] = 0;    
    }
}

void test()
{
    printf("Test strategy by Prohorova\n");
    matrix_t matrix_buffer;
    char result;
    
    {
        printf("Have to move right: ");
        matrixgame_create_matrix(&matrix_buffer, 5, 7);
        nulled_matrix(&matrix_buffer);
        matrix_buffer.matrix[1][0] = 2;
        matrix_buffer.matrix[1][3] = 2;
        result = teen48game_player_prohorova(&matrix_buffer, to_step);
        if (result == 'r')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
        }
        matrixgame_free_matrix(&matrix_buffer);
    }

    {
        printf("Matrix is full: ");
        matrixgame_create_matrix(&matrix_buffer, 5, 7);
        for (int i = 0; i < matrix_buffer.rows; i++)
            for (int j = 0; j < matrix_buffer.columns; j++)
                matrix_buffer.matrix[i][j] = 2;
        result = teen48game_player_prohorova(&matrix_buffer, to_step);
        if (result == 'd')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
        }
        matrixgame_free_matrix(&matrix_buffer);
    }

    {
        printf("Matrix is full and one row is the same: ");
        matrixgame_create_matrix(&matrix_buffer, 5, 7);
        for (int i = 1; i < matrix_buffer.rows; i++)
            for (int j = 0; j < matrix_buffer.columns; j++)
                matrix_buffer.matrix[i][j] = i + j + 2;

        for (int i = 1; i < matrix_buffer.rows; i++)
            for (int j = 0; j < matrix_buffer.columns; j++)
                matrix_buffer.matrix[i][j] = 2;

        result = teen48game_player_prohorova(&matrix_buffer, to_step);
        if (result == 'r')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
        }
        matrixgame_free_matrix(&matrix_buffer);
    }

    {
        printf("Have to move right: ");
        matrixgame_create_matrix(&matrix_buffer, 5, 7);
        nulled_matrix(&matrix_buffer);
        matrix_buffer.matrix[1][0] = 2;
        result = teen48game_player_prohorova(&matrix_buffer, to_step);
        if (result == 'd')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
        }
        matrixgame_free_matrix(&matrix_buffer);
    }

    {
        printf("Have to move up: ");
        matrixgame_create_matrix(&matrix_buffer, 5, 7);
        nulled_matrix(&matrix_buffer);

        for (int i = 1; i < matrix_buffer.rows; i++)
        {
            for (int j = 0; j < matrix_buffer.columns; j++)
            {
                matrix_buffer.matrix[i][j] = i + j + 1;
            }
        }
        result = teen48game_player_prohorova(&matrix_buffer, to_step);
        if (result == 'u')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
        }
        matrixgame_free_matrix(&matrix_buffer);
    }
}

int main()
{
    test();
    return 0;
}
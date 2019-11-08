#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include "../p_headers/teen48game_player_prohorova.h"
#include "../f_headers/teen48game_to_step.h"
#include <matrixgame.h>

#define SUCCESS 0

void fill_by_nules(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
            matrix->matrix[i][j] = 0;
    }
}
void test()
{

 printf("Sabur_Tests\n");
    matrix_t matrix;
    char result;

    {
        printf("sum_up_checker: ");
        matrixgame_create_matrix(&matrix, 4, 4);
        fill_by_nules(&matrix);
        matrix.matrix[0][0] = 2;
        matrix.matrix[1][0] = 2;
        matrix.matrix[0][2] = 2;
        matrix.matrix[1][2] = 4;
        result = teen48game_player_saburov(&matrix, to_step);
        if (result == 'u')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
            printf("%c\n", result);
        }
        matrixgame_free_matrix(&matrix);
    }

    {
        printf("sum_right_left_checker: ");
        matrixgame_create_matrix(&matrix, 4, 4);
        fill_by_nules(&matrix);
        matrix.matrix[0][1] = 2;
        matrix.matrix[0][2] = 2;
        matrix.matrix[2][0] = 2;
        matrix.matrix[2][3] = 4;
        result = teen48game_player_saburov(&matrix, to_step);
        if (result == 'r' || result == 'l')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
            printf("%c\n", result);
        }
        matrixgame_free_matrix(&matrix);
    }

    {
        printf("Up_checker: ");
        matrixgame_create_matrix(&matrix, 4, 4);
        fill_by_nules(&matrix);
        matrix.matrix[0][0] = 4;
        matrix.matrix[0][1] = 8;
        matrix.matrix[0][2] = 32;
        matrix.matrix[0][3] = 2;
        matrix.matrix[1][0] = 2;
        matrix.matrix[1][1] = 16;
        matrix.matrix[1][2] = 64;
        matrix.matrix[1][3] = 4;
        matrix.matrix[2][0] = 16;
        matrix.matrix[2][2] = 2;
        matrix.matrix[2][3] = 8;
        matrix.matrix[3][1] = 2;
        matrix.matrix[3][2] = 4;
        matrix.matrix[3][3] = 16;
        result = teen48game_player_saburov(&matrix, to_step);
        if (result == 'u')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
            printf("%c\n", result);
        }
        matrixgame_free_matrix(&matrix);
    }
    {
        printf("down_checker: ");
        matrixgame_create_matrix(&matrix, 4, 4);
        fill_by_nules(&matrix);
        matrix.matrix[0][0] = 4;
        matrix.matrix[0][1] = 8;
        matrix.matrix[0][2] = 32;
        matrix.matrix[0][3] = 2;
        matrix.matrix[1][0] = 2;
        matrix.matrix[1][1] = 16;
        matrix.matrix[1][2] = 64;
        matrix.matrix[1][3] = 4;
        result = teen48game_player_saburov(&matrix, to_step);
        if (result == 'd')
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
            printf("%c\n", result);
        }
        matrixgame_free_matrix(&matrix);
    }
}
int main()
{
    test();
    return 0;
}





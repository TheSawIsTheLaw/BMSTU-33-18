#include "../p_headers/teen48game_player_saburov.h"
#include <stdlib.h>
int check_summ_up(matrix_t *matrix)
{
    /*
    for (int i = 0; i < matrix -> rows; i ++)
    {
        if (matrix -> matrix[0][i] == matrix -> matrix[1][i] && matrix -> matrix[0][i] != 0 && matrix -> matrix[1][i] != 0|| matrix -> matrix[1][i] == matrix -> matrix[2][i]\
        && matrix -> matrix[1][i] != 0 && matrix -> matrix[2][i] != 0|| matrix -> matrix[2][i] == matrix -> matrix[3][i] && matrix -> matrix[2][i] != 0 && matrix -> matrix[3][i] != 0||\
        (matrix -> matrix[0][i] == matrix -> matrix[2][i]\
        && matrix -> matrix[1][i] == 0) && matrix -> matrix[0][i] != 0 && matrix -> matrix[2][i] != 0|| (matrix -> matrix[0][i] == matrix -> matrix[3][i]\
        && matrix -> matrix[1][i] == 0 && matrix -> matrix[2][i] == 0)&& matrix -> matrix[0][i] != 0 && matrix -> matrix[3][i] != 0 || \
        (matrix -> matrix[1][i] == matrix -> matrix[3][i] && matrix -> matrix[2][i] == 0 && matrix -> matrix[1][i] != 0 && matrix -> matrix[3][i] != 0))
            return 1;
    }
    */
    return 0;
}
int check_summ_left_right(matrix_t *matrix)
{
    /*
    for (int i = 0; i < matrix -> rows; i ++)
    {
        if (matrix -> matrix[i][0] == matrix -> matrix[i][1] && matrix -> matrix[i][0] != 0 && matrix -> matrix[i][1] != 0|| matrix -> matrix[i][1] == matrix -> matrix[i][2]\
        && matrix -> matrix[i][1] != 0 && matrix -> matrix[i][2] != 0|| matrix -> matrix[i][2] == matrix -> matrix[i][3] && matrix -> matrix[i][2] != 0 && matrix -> matrix[i][3] != 0||\
        (matrix -> matrix[i][0] == matrix -> matrix[i][2]\
        && matrix -> matrix[i][1] == 0) && matrix -> matrix[i][0] != 0 && matrix -> matrix[i][2] != 0|| (matrix -> matrix[i][0] == matrix -> matrix[i][3]\
        && matrix -> matrix[i][1] == 0 && matrix -> matrix[i][2] == 0)&& matrix -> matrix[i][0] != 0 && matrix -> matrix[i][3] != 0 || \
        (matrix -> matrix[i][1] == matrix -> matrix[i][3] && matrix -> matrix[i][2] == 0 && matrix -> matrix[i][1] != 0 && matrix -> matrix[i][3] != 0))
            return 1;
    }*/
    return 0;
}
int find_below_elements(matrix_t *matrix, int row, int col)
{
    if (row < matrix -> rows - 1)
    {
        for (int i = row; i < matrix -> rows; i ++)
        {
            if (matrix -> matrix[i][col] != 0)
                return 1;
        }
    }
    return 0;
}
int find_side_elements(matrix_t *matrix, int row)
{
    if (row < matrix -> rows - 1)
    {
            for (int j = 0; j < matrix -> columns; j ++)
                if (matrix -> matrix[row][j] != 0)
                    return 1;
    }
    return 0;
}
int check_step_up(matrix_t *matrix)
{
    for (int i = 0; i < matrix -> rows; i ++)
    {
        for (int j = 0; j < matrix -> columns; j ++)
        {
            if (matrix -> matrix[i][j] == 0)
                if (find_below_elements(matrix, i,j))
                    return 1;
        }
    }
    return 0;
}
int check_step_left_right(matrix_t *matrix)
{
    for (int i = 0; i < matrix -> rows; i ++)
    {
        for (int j = 0; j < matrix -> columns; j ++)
        {
            if (matrix -> matrix[i][j] == 0)
                if (find_side_elements(matrix, i))
                    return 1;
        }
    }
    return 0;
}
char teen48game_player_saburov(matrix_t *const matrix, int (*func)(matrix_t *const, const char))
{
    int move;
    if (check_summ_up(matrix))
        return 'u';
    else if (check_summ_left_right(matrix))
    {
        move = rand() % 2;
        if (move == 1)
            return 'l';
        else
            return 'r';
    }
    else if (check_step_up(matrix))
        return 'u';
    else if (check_step_left_right(matrix))
    {
        move = rand() % 2;
        if (move == 1)
            return 'l';
        else
            return 'r';
    }
    else
        return 'd';
    /*int move = rand() % 10;
    switch (move)
    {
	case 9:
		return 'u';
	case 8:
		return 'r';
	case 7:
		return 'u';
	case 6:
		return 'r';
	case 5:
		return 'u';
	case 4:
		return 'l';
	case 3:
		return 'u';
	case 2:
		return 'l';
	case 1:
		return 'u';
	case 0:
		return 'd';

    }*/
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "../../MATRIXgame/headers/matrixgame.h"

#include "../f_headers/teen48game_statistics.h"

#define OK 0
#define READ 1
#define ERROR -1
#define ERROR_READ -2
#define MALLOC_ERROR -3

#define FILENAME "test.txt"

int get_matrix_from_file(matrix_t *const matrix, FILE *const f)
{
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->columns; j++)
            if (fscanf(f, "%d", &matrix->matrix[i][j]) != READ)
                return ERROR_READ;
    return OK;
}

int create_matrix(matrix_t *const matrix, const int rows, const int columns)
{
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix->matrix == NULL)
        return MALLOC_ERROR;
    for (int i = 0; i < rows; i++)
    {
        matrix->matrix[i] = (int *)malloc(columns * sizeof(int));
        if (matrix->matrix[i] == NULL)
        {
            while (i > 0)
                free(matrix->matrix[--i]);
            free(matrix->matrix);
            return MALLOC_ERROR;
        }
    }
    return OK;
}

void delete_matrix(matrix_t *const matrix)
{
    for (int i = 0; i < matrix->rows; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
}

int main(void)
{
    setbuf(stdout, NULL);
    matrix_t matrix[5];
    score_t leaderboard[5];
    uint64_t clock[5] = {222222, 333333, 444444, 555555, 333333};
    uint64_t limit_time = 1000000;
    char player_names[NOP][NOP] = {"alis", "pasha", "nastya", "lexa", "lyuba"};

    int size = 5;
    int rows = 3, columns = 4;

    for (int i = 0; i < size; i++)
        create_matrix(matrix + i, rows, columns);

    FILE *stream = fopen(FILENAME, "r");
    for (int i = 0; i < size; i++)
        get_matrix_from_file(matrix + i, stream);
    fclose(stream);

    calc_statistic(matrix, size, leaderboard);
    live_print(leaderboard, player_names, size, clock, limit_time);
    print_result(matrix, size, leaderboard, player_names);

    for (int i = 0; i < size; i++)
        delete_matrix(matrix + i);

    puts("");
    return OK;
}
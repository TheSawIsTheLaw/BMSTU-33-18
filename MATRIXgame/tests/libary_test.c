#include <matrixgame.h>
#include <stdio.h>

int main(void)
{
    setbuf(stdout, NULL);

    matrix_t test_matrix;
    int err = matrixgame_create_matrix(&test_matrix, 9, 9);

    printf("%d error code\n\n", err);

    for (int i = 0; i < test_matrix.rows; i++)
    {
        for (int j = 0; j < test_matrix.columns; j++)
        {
            test_matrix.matrix[i][j] = i * i + j;
            printf("%d ", test_matrix.matrix[i][j]);
        }
        puts("");
    }

    err = matrixgame_transpose(&test_matrix); 
    printf("%d error code\n\n", err);

    for (int i = 0; i < test_matrix.rows; i++)
    {
        for (int j = 0; j < test_matrix.columns; j++)
        {
            printf("%d ", test_matrix.matrix[i][j]);
        }
        puts("");
    }
}

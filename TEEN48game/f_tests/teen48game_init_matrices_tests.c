#include "../f_headers/teen48game_init_matrices_tests.h" 
#define SUCCESS 0

void test()
{
    {
        printf("\nTest function init_matrices\n");
        printf("Not correct size in paramenres: \n");
        matrix_t matrix_array[5];
        int rc = init_matrices(matrix_array, -2, 13);
        if (rc == 1000)
            printf("OK\n");
        else
            printf("FAIL\n"); 
    }

    {
        printf("Correct: ");
        matrix_t matrix_array[5];

        for (int i = 0; i < 5; i++)
        {
            if ((matrixgame_create_matrix(&matrix_array[i], 5, 3)) != SUCCESS)
            {
                for (int j = 0; j < i; j++)
                {
                    matrixgame_free_matrix(&matrix_array[j]);
                }
                return;
            }
        }
        init_matrices(matrix_array, 5, 10);
        for (int i = 0; i < matrix_array[0].rows; i++)
        {
            for (int j = 0; j < matrix_array[0].columns; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (matrix_array[k].matrix[i][j] != matrix_array[k + 1].matrix[i][j])
                    {
                        printf("FAIL\n");
                        for (int t = 0; t < 5; t++)
                            matrixgame_free_matrix(&matrix_array[t]);
                        return;
                    }

                }
            }
        }
        printf("OK\n");
        for (int t = 0; t < 5; t++)
            matrixgame_free_matrix(&matrix_array[t]);

    }
}

int main()
{
    test();
    return SUCCESS;

}
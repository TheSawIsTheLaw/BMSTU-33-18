#include "../f_headers/teen48game_to_step_tests.h" 

void fill_file(const char *const filename, const char *const message)
{
    FILE *file = fopen(filename, "w");
    if (file)
    {
        fprintf(file, "%s", message);
        fclose(file);
    }
}

void fill_from_file(const char *const filename, matrix_t *const data)
{
    FILE *file = NULL;

    if ((file = fopen(filename, "r")))
    {
        for (int i = 0; i < data -> rows; i++)
        {
            for (int j = 0; j < data -> columns; j++)
            {
                fscanf(file, "%d", *(data -> matrix + i) + j);
            }
        }

        fclose(file);
    }
}

int matrices_are_equal(const matrix_t first, const matrix_t second)
{
    if (first.rows != second.rows)
    {   
        return ERRORS_DETECTED;
    }

    if (first.columns != second.columns)
    {
        return ERRORS_DETECTED;
    }    

    for (int i = 0; i < first.rows; i++)
    {
        for (int j = 0; j < first.columns; j++)
        {
            if (*(*(first.matrix + i) + j) != *(*(second.matrix + i) + j))
            {
                return ERRORS_DETECTED;
            }
        }
    }

    return OK;
}

int test_case(const int first_rows,\
              const int first_cols,\
              const int second_rows,\
              const int second_cols,\
              const char *const input_string, const char *const result_string, const char key)
{
    matrix_t matrix, result_matrix; 
    int function_result = 0;

    if ((function_result = matrixgame_create_matrix(&matrix, first_rows, first_cols)) != OK)
    {
        return function_result;
    }

    if ((function_result = matrixgame_create_matrix(&result_matrix, second_rows, second_cols)) != OK)
    {
        matrixgame_free_matrix(&matrix);
        return function_result;
    }

    fill_file(INPUT_FILE, input_string);
    fill_file(RESULT_FILE, result_string);
    fill_from_file(INPUT_FILE, &matrix);
    fill_from_file(RESULT_FILE, &result_matrix);

    if (to_step(&matrix, key) != OK)
    {
        matrixgame_free_matrix(&matrix);
        matrixgame_free_matrix(&result_matrix);
        return ERRORS_DETECTED;
    }

    if (matrices_are_equal(matrix, result_matrix) != OK)
    {
        matrixgame_free_matrix(&matrix);
        matrixgame_free_matrix(&result_matrix);
        return ERRORS_DETECTED;
    }

    matrixgame_free_matrix(&matrix);
    matrixgame_free_matrix(&result_matrix);

    return OK;
}

int main()
{
    
    int errors_counter = 0;
    printf("UNIT TESTING\n");
    // Тест 1

    if (test_case(4, 4, 4, 4, INPUT_1, RESULT_1, 'l') != OK)
    {
        errors_counter++;
        printf("TEST1.....FAILED\n");
    }
    else
    {
        printf("TEST1.....PASSED\n");
    }

    // Тест 2

    if (test_case(4, 4, 4, 4, INPUT_2, RESULT_2, 'l') != OK)
    {
        errors_counter++;
        printf("TEST2.....FAILED\n");
    }
    else
    {
        printf("TEST2.....PASSED\n");
    }

    // Тест 3

    if (test_case(4, 4, 4, 4, INPUT_3, RESULT_3, 'l') != OK)
    {
        errors_counter++;
        printf("TEST3.....FAILED\n");
    }
    else
    {
        printf("TEST3.....PASSED\n");
    }

    // Тест 4

    if (test_case(4, 4, 4, 4, INPUT_4, RESULT_4, 'l') != OK)
    {
        errors_counter++;
        printf("TEST4.....FAILED\n");
    }
    else
    {
        printf("TEST4.....PASSED\n");
    }

    // Тест 5

    if (test_case(1, 16, 1, 16, INPUT_5, RESULT_5, 'l') != OK)
    {
        errors_counter++;
        printf("TEST5.....FAILED\n");
    }
    else
    {
        printf("TEST5.....PASSED\n");
    }

    // Тест 6

    if (test_case(4, 4, 4, 4, INPUT_6, RESULT_6, 'r') != OK)
    {
        errors_counter++;
        printf("TEST6.....FAILED\n");
    }
    else
    {
        printf("TEST6.....PASSED\n");
    }

    // Тест 7

    if (test_case(4, 4, 4, 4, INPUT_7, RESULT_7, 'r') != OK)
    {
        errors_counter++;
        printf("TEST7.....FAILED\n");
    }
    else
    {
        printf("TEST7.....PASSED\n");
    }

    // Тест 8

    if (test_case(4, 4, 4, 4, INPUT_8, RESULT_8, 'r') != OK)
    {
        errors_counter++;
        printf("TEST7.....FAILED\n");
    }
    else
    {
        printf("TEST7.....PASSED\n");
    }

    // Тест 9

    if (test_case(4, 4, 4, 4, INPUT_9, RESULT_9, 'r') != OK)
    {
        errors_counter++;
        printf("TEST9.....FAILED\n");
    }
    else
    {
        printf("TEST9.....PASSED\n");
    }

    // Тест 10

    if (test_case(1, 15, 1, 15, INPUT_10, RESULT_10, 'r') != OK)
    {
        errors_counter++;
        printf("TEST10.....FAILED\n");
    }
    else
    {
        printf("TEST10.....PASSED\n");
    }

    // Тест 11

    if (test_case(4, 4, 4, 4, INPUT_11, RESULT_11, 'u') != OK)
    {
        errors_counter++;
        printf("TEST11.....FAILED\n");
    }
    else
    {
        printf("TEST11.....PASSED\n");
    }

    // Тест 12

    if (test_case(4, 4, 4, 4, INPUT_12, RESULT_12, 'u') != OK)
    {
        errors_counter++;
        printf("TEST12.....FAILED\n");
    }
    else
    {
        printf("TEST12.....PASSED\n");
    }

    // Тест 13

    if (test_case(4, 4, 4, 4, INPUT_13, RESULT_13, 'u') != OK)
    {
        errors_counter++;
        printf("TEST13.....FAILED\n");
    }
    else
    {
        printf("TEST13.....PASSED\n");
    }

    // Тест 14

    if (test_case(4, 4, 4, 4, INPUT_14, RESULT_14, 'u') != OK)
    {
        errors_counter++;
        printf("TEST14.....FAILED\n");
    }
    else
    {
        printf("TEST14.....PASSED\n");
    }

    // Тест 15

    if (test_case(10, 1, 10, 1, INPUT_15, RESULT_15, 'u') != OK)
    {
        errors_counter++;
        printf("TEST15.....FAILED\n");
    }
    else
    {
        printf("TEST15.....PASSED\n");
    }

    // Тест 16

    if (test_case(4, 4, 4, 4, INPUT_16, RESULT_16, 'd') != OK)
    {
        errors_counter++;
        printf("TEST16.....FAILED\n");
    }
    else
    {
        printf("TEST16.....PASSED\n");
    }

    // Тест 17

    if (test_case(4, 4, 4, 4, INPUT_17, RESULT_17, 'd') != OK)
    {
        errors_counter++;
        printf("TEST17.....FAILED\n");
    }
    else
    {
        printf("TEST17.....PASSED\n");
    }    

    // Тест 18

    if (test_case(4, 4, 4, 4, INPUT_18, RESULT_18, 'd') != OK)
    {
        errors_counter++;
        printf("TEST18.....FAILED\n");
    }
    else
    {
        printf("TEST18.....PASSED\n");
    }

    // Тест 19

    if (test_case(4, 4, 4, 4, INPUT_19, RESULT_19, 'd') != OK)
    {
        errors_counter++;
        printf("TEST19.....FAILED\n");
    }
    else
    {
        printf("TEST19.....PASSED\n");
    }

    // Тест 20

    if (test_case(10, 1, 10, 1, INPUT_20, RESULT_20, 'd') != OK)
    {
        errors_counter++;
        printf("TEST20.....FAILED\n");
    }
    else
    {
        printf("TEST20.....PASSED\n");
    }

    // Тест 21

    if (test_case(3, 3, 3, 3, INPUT_21, RESULT_21, 'l') == OK)
    {
        errors_counter++;
        printf("TEST21.....FAILED\n");
    }
    else
    {
        printf("TEST21.....PASSED\n");
    }

    // Тест 22

    if (test_case(3, 3, 4, 3 , INPUT_22, RESULT_22, 'l') == OK)
    {
        errors_counter++;
        printf("TEST22.....FAILED\n");
    }
    else
    {
        printf("TEST22.....PASSED\n");
    }

    // Тест 23

    if (test_case(3, 4, 3, 3 , INPUT_23, RESULT_23, 'l') == OK)
    {
        errors_counter++;
        printf("TEST23.....FAILED\n");
    }
    else
    {
        printf("TEST23.....PASSED\n");
    }    

    // Тест 24

    if (test_case(100000000, 1000000000, 3, 3 , INPUT_24, RESULT_24, 'l') == OK)
    {
        errors_counter++;
        printf("TEST24.....FAILED\n");
    }
    else
    {
        printf("TEST24.....PASSED\n");
    }       

    // Тест 25

    if (test_case(3, 3, 1000000000, 1000000000 , INPUT_24, RESULT_24, 'l') == OK)
    {
        errors_counter++;
        printf("TEST25.....FAILED\n");
    }
    else
    {
        printf("TEST25.....PASSED\n");
    }    

    if (test_case(3, 3, 3, 3, INPUT_24, RESULT_24, 'p') == OK)
    {
        errors_counter++;
        printf("TEST26.....FAILED\n");
    }
    else
    {
        printf("TEST26.....PASSED\n");
    }

    return errors_counter;
}
#include "../p_headers/teen48game_player_kovalev.h"

int count_zero (matrix_t *matrix_buffer)
{
    int res = 0;
    for (int row_ind = 0; row_ind < matrix_buffer->rows; row_ind++)
        for (int col_ind = 0; col_ind < matrix_buffer->columns; col_ind++)
            res += (matrix_buffer->matrix[row_ind][col_ind] == 0);
    return res;
}

int copys_field(const matrix_t *const old_matrix, matrix_t *const new_matrix)
{
    new_matrix->rows = old_matrix->rows;
    new_matrix->columns = old_matrix->columns;

    for (int row_ind = 0; row_ind < old_matrix->rows; row_ind++)
        for (int col_ind = 0; col_ind < old_matrix->columns; col_ind++)
            *(*((new_matrix->matrix) + row_ind) + col_ind) = *(*((old_matrix->matrix) + row_ind) + col_ind);

    return 0;
}

char teen48game_player_kovalev(matrix_t *const matrix_buffer, int (*to_step)(matrix_t *const, const char))
{
    // здесь мы имеем некоторую работу над буферной матрицей (или не имеем),
    // и записываем некоторые признаки. Пример:
    // to_step(buffer, 'r') - изменит матрицу buffer как при ходе вправо (функция возвращает код ошибки
    // 0 - все завершилось успешно)

    matrix_t *result = NULL;
    int rc = matrixgame_create_matrix(result, matrix_buffer->rows, matrix_buffer->columns);
    if (rc)
        return rc;

    copys_field(matrix_buffer, result);
    to_step(result, 'r');
    int r_res = count_zero(result);

    copys_field(matrix_buffer, result);
    to_step(result, 'l');
    int l_res = count_zero(result);

    copys_field(matrix_buffer, result);
    to_step(result, 'd');
    int d_res = count_zero(result);

    copys_field(matrix_buffer, result);
    to_step(result, 'u');
    int u_res = count_zero(result);

    matrixgame_free_matrix(result);

    int choice = 0;
    if (r_res >= l_res && r_res >= d_res && r_res >= u_res)
        choice = 0;
    else if (l_res >= r_res && l_res >= d_res && l_res >= u_res)
        choice = 1;
    else if (d_res >= l_res && d_res >= r_res && d_res >= u_res)
        choice = 2;
    else
        choice = 3;

    switch (choice)
    {
        case 0:
            return 'r';
        case 1:
            return 'l';
        case 2:
            return 'd';
        case 3:
            return 'u';
    }
    // возвращаем одно из 4 направлений: 'r', 'l', 'd', 'u'
    return 0; // до сюда не дойдет
}

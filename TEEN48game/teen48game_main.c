#include "f_headers/teen48game_create_matrices.h"
#include "f_headers/teen48game_read_sizes.h"
#include "f_headers/teen48game_free_matrices.h"
#include "f_headers/teen48game_call_players_funcs.h"
#include "p_headers/teen48game_players_array.h"
#include "f_headers/teen48game_statistics.h"
#include "f_headers/teen48game_init_matrices.h"

#define OK 0
#define PERCENTAGE 15
#define BUFFER_COUNT 2

int main(void)
{
    matrix_t players_matrices[PLAYERS_COUNT];
    matrix_t matrix_buffer[BUFFER_COUNT];
    int rows, columns;
    int code_error;

    if ((code_error = read_sizes(&rows, &columns, stdin)))
    {
        return code_error;
    }

    if ((code_error = create_matrices(players_matrices, matrix_buffer, rows, columns, PLAYERS_COUNT)))
    {
        return code_error;
    }

    if ((code_error = init_matrices(players_matrices, PLAYERS_COUNT, PERCENTAGE)))
    {
        return code_error;
    }

    call_players_funcs(players_matrices, matrix_buffer, players_funcs, players_time, players_names);

    print_result(players_matrices, players_names);

    if ((code_error = free_matrices(players_matrices, matrix_buffer, PLAYERS_COUNT)))
    {
        return code_error;
    }
    
    return OK;
}

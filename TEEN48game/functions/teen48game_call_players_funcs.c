/**
 * \file teen48game_call_players_funcs.c
 * \brief Функция, вызывающая ходы игроков
 */

#include "../f_headers/teen48game_call_players_funcs.h"
#include "../f_headers/teen48game_copy_matrix.h"
#include "../f_headers/teen48game_to_step.h"
#include "../f_headers/teen48game_statistics.h"
#include "../f_headers/timer.h"
#include "../f_headers/teen48game_check_equal_matrices.h"
#include "../f_headers/teen48game_gorandom.h"
/**
 * \def MAX_TICKS
 * \brief Максимальная длителность хода в тактах процессора
 */
#define MAX_TICKS 600000000
/**
 * \def N
 * \brief Мне откуда знать, что это за бред сумасшедшего?..
 */
#define N 100
/**
 * \def PRINT_STEP
 * \brief Константа вывода шага участника
 */
#define PRINT_STEP 10000000
/**
 * \def PLAYERS_COUNT
 * \brief Количество участников игры
 */
#define PLAYERS_COUNT 14
#define NO 0
#define YES 1

#define MOD(numb) numb % PRINT_STEP
#define CURRENT_PTR(ptr) (ptr + i)

/**
 * \fn int append_row(matrix_t *const matrix)
 *
 * \param void call_players_funcs(matrix_t *players_matrices, matrix_t *matrix_buffer,
 * char (**players_funcs_ptr)(matrix_t *const, int (*)(matrix_t *const, const char)),
 * uint64_t *players_time, char players_names[][N]) - Указатель на функцию вызова
 *
 * \brief Вызывает ход игрока
 */
void call_players_funcs(matrix_t *players_matrices, matrix_t *matrix_buffer,
                        char (**players_funcs_ptr)(matrix_t *const, int (*)(matrix_t *const, const char)),
                        uint64_t *players_time, char players_names[][N])
{
    int players_remaining = PLAYERS_COUNT;
    int current_iteration = 0;

    while (players_remaining)
    {
        for (int i = 0; i < PLAYERS_COUNT; i++)
        {
            if (*CURRENT_PTR(players_funcs_ptr) != NULL)
            {
                copy_matrix(CURRENT_PTR(players_matrices), matrix_buffer);
                copy_matrix(CURRENT_PTR(players_matrices), matrix_buffer + 1);
                uint64_t start_time = tick();
                char move = (*CURRENT_PTR(players_funcs_ptr))(matrix_buffer, to_step);
                *CURRENT_PTR(players_time) += tick() - start_time;
                // printf("%2d     %ld\n", i, players_time[i]);
                to_step(CURRENT_PTR(players_matrices), move);

                if (*CURRENT_PTR(players_time) > MAX_TICKS)
                {
                    *CURRENT_PTR(players_funcs_ptr) = NULL;
                    players_remaining--;
                }

                if (teen48game_check_equal_matrices(matrix_buffer + 1, CURRENT_PTR(players_matrices)) == NO)
                {
                    gorandom(CURRENT_PTR(players_matrices));
                }
            }

            if (!(MOD(++current_iteration)))
            {
                current_iteration = 0;
                // for (int j = 0; j < PLAYERS_COUNT; j++)
                //     printf("%2d   %ld\n", j, players_time[j]);
                live_print(players_matrices, players_names, players_time, MAX_TICKS);
                }
        }
    }
}

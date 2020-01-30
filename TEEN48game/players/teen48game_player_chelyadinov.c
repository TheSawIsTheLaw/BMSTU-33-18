#include "../p_headers/teen48game_player_chelyadinov.h"
#include <stdlib.h>
#define ERR 0
char teen48game_player_chelyadinov(matrix_t *const matrix_buffer, int (*to_step)(matrix_t *const, const char))
{
    int choice = rand() % 4;

    switch (choice)
    {
      case 0:
        return 'u';
      case 1:
        return 'd';
      case 2:
        return 'r';
      case 3:
        return 'l';
    }
    return ERR;
}

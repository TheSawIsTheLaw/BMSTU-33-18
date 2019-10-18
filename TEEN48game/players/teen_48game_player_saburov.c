#include "../p_headers/teen48game_player_saburov.h"
#include <stdlib.h>
char teen48game_player_saburov(matrix_t *matrix, const char (*func)(matrix_t, const char))
{
    int move = rand() % 10;
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

    }
    return 0;
}

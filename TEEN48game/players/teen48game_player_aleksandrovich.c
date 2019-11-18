#include "../p_headers/teen48game_player_aleksandrovich.h"
#include <stdlib.h>

#define ERROR 0 

char teen48game_player_aleksandrovich(matrix_t *const matrix_buffer, int (*to_step)(matrix_t *const, const char))
{
	int choice = rand() % 4;
	switch(choice)
	{
	case 0:
	    return 'u';
	case 1:
	    return 'r';
	case 2:
	    return 'l';
	case 3:
	    return 'd';
	}

	return ERROR;
}



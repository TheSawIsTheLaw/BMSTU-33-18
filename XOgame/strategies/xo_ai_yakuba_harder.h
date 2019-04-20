/* Функция makeshot от Якуба */
/* Более сложный простейший бот с проверкой на наличие в ячейке значения */

#include <stdlib.h>
#include <time.h>

int make_shot_yakuba_harder(char type, char field[][3])
{
    int i, j;
    srand(time(NULL));
    i = (rand() % 3);
    j = (rand() % 3);
	while (field[i][j] != ' ')
	{
		srand(time(NULL));
		i = (rand() % 3);
		j = (rand() % 3);
    }
	field[i][j] = type;
	return 0;
}
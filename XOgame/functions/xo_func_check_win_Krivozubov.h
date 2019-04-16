int check_win(char bf[][3])
{
	int limit = 3;

	// Если на главной диагонали пустые ячейки, то никто не выйграл
	int ok = 1;
	for (int i = 0; i < limit; i++)
		if (bf[i][i] != ' ')
		{
			ok = 0;
			break;
		}	

	// Проверяем, есть ли достаточное количество X или O для завершения игры
	int number_x, number_o = 0;
	for (int i = 0; i < limit; i++)
		for (int j = 0; j < limit; j++)
			if (bf[i][j] == 'X')
				number_x++;
			else if (bf[i][j] == 'O')
				number_o++;

	if ((number_x < limit && number_o < limit) || ok)
		return 0;
	
	// Проверка в строках
	for (int i = 0; i < limit; i++)
	{
		if (bf[i][0] != ' ')
		{
			int total = 1;
			char start = bf[i][0];
			for (int j = 1; j < limit; j++)
				if (bf[i][j] != start)
					break;
				else
					total++;
			if (total == limit)
				return 1;
		}
		else
			continue;
	}

	// Проверка в столбцах
	for (int j = 0; j < limit; j++)
	{
		if (bf[0][j] != ' ')
		{
			int total = 1;
			char start = bf[0][j];
			for (int i = 1; i < limit; i++)
			{
				if (bf[i][j] != start)
					break;
				else
					total++;
			}
			if (total == limit)
				return 1;
		}
		else
			continue;
	}

	// Главная диагональ
	if (bf[0][0] != ' ')
	{
		int total = 1;
		char start = bf[0][0];
		for (int i = 1; i < limit; i++)
		{
			if (bf[i][i] != start)
				break;
			else
				total++;
		}
		if (total == limit)
			return 1;
	}

	// Побочная диагональ
	if (bf[0][limit - 1] != ' ')
	{
		int total = 1;
		char start = bf[0][limit - 1];
		for (int i = 1; i < limit; i++)
		{
			if (bf[i][limit - i - 1] != start)
				break;
			else
				total++;
		}
		if (total == limit)
			return 1;
	}

	return 0;		
}


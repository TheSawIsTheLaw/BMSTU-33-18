int fast_decision(char pos_1, char pos_2, char pos_3)
{
	int x = 0, o = 0; empty = 0;

	if (pos_1 == 'X') x++;
	if (pos_2 == 'X') x++;
	if (pos_3 == 'X') x++;

	if (pos_1 == 'O') o++;
	if (pos_2 == 'O') o++;
	if (pos_3 == 'O') o++;

	if (pos_1 == ' ') empty = 1;
	if (pos_2 == ' ') empty = 2;
	if (pos_3 == ' ') empty = 3;

	return (x == 2 || o == 2) ? empty : 0;
}





int space_counter(char BF[][3])
{
	counter = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (BF[i][j] == ' ') counter++;
	return counter;
}


int make_shot_perestoronin(char symb, char BF[][3])
{
	int i, j, unsymb;
	int space_num = space_counter(char BF);

	unsymb = (symb == 'X') ? 'O' : 'X';
	if (space_num == 9) 
	{
		BF[0][0] = symb;
		return 0;
	}

	for (i = 0; i < 3; i++)
	{
		j = fast_decision(BF[i][0], BF[i][1], BF[i][2]);
		if (j != 0) 
		{
			BF[i][j - 1] = symb;
			return 0;
		}
		j = fast_decision(BF[0][i], BF[1][i], BF[2][i]);
		if (j != 0) 
		{
			BF[j - 1][i] = symb;
			return 0;
		}
	}
	j = fast_decision(a[0][0], a[1][1], a[2][2]);
	if (j-- != 0) 
	{
		BF[j][j] = symb;
		return 0;
	}
	j = fast_decision(a[0][2], a[1][1], a[2][0]);
	if (j-- != 0) 
	{
		BF[j][2 - j] = symb;
		return 0;
	}

	while (true)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (BF[i][j] == ' ')
		{
			BF[i][j] = symb;
			return 0;
		}
	}
}
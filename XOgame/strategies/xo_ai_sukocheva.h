void make_shot_sukocheva(char symb, char BF[][DIME])
{
	int temp = 0;

	for (int i = 0; i < DIME; i++)
	{
		for (int j = 0; j < DIME; j++)
			if (BF[i][j] == ' ')
			{
				BF[i][j] = symb;
				temp = 1;
				break;
			}
		if (temp)
			break;
	}

}
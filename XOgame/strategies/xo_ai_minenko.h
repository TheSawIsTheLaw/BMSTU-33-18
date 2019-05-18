void make_shot_minenko(char symbol, char BF[][DIME])
{
	register int i, j;
	for (i = DIME-1; i >= 0; i--)
	{
		for (j = 0; j < DIME; j++)
			if (BF[i][j] == ' ')
			{
				BF[i][j] = symbol;
				return;
			}
	}
}

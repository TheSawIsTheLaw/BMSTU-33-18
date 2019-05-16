#define FALSE 0
#define TRUE 1

void make_shot_sukocheva(const char symb, char BF[][DIME])
{
	int temp = FALSE;

	for (int i = 0; i < DIME; i++)
	{
		for (int j = 0; j < DIME; j++)
			if (BF[i][j] == ' ')
			{
				BF[i][j] = symb;
				temp = TRUE;
				break;
			}
		if (temp)
			break;
	}

}
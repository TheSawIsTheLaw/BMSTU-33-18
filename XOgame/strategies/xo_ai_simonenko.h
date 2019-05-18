void make_shot_simonenko(char symb, char BF[][DIME])
{
	int your_turn = 0;
	int i = 0;   
	while (i < DIME)
	{	
		int j = 0;
		while (j < DIME) 
		{
			if (BF[i][j] = ' ')
			{
				BF[i][j] = symb;
				your_turn = 1;
				break;
			}
			j++;
		}
		i++;
		if (your_turn)
			break;
	}
}

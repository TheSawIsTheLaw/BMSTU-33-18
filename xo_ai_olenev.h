int make_shot_01(char type, char field[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", field[i][j]);
        }

        printf("\n");
    }
}

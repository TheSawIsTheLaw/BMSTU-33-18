void print_battlefield(char bf[][3])
{
    printf("┏━━━┳━━━┳━━━┓\n");
    for (int i=0; i<2 ; i++)
    {
        for(int j=0; j<3; j++)
            printf("┃ %c%s",bf[i][j],(j+1) % 3 ? " ":" ┃\n" );
        printf("┣━━━╋━━━╋━━━┫\n");
    }
    for(int j=0; j<3; j++)
        printf("┃ %c%s",bf[2][j],(j+1) % 3 ? " ":" ┃\n" );
    printf("┗━━━┻━━━┻━━━┛\n");
}


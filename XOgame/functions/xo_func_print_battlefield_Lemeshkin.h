void print_battlefield(char bf[][DIME])
{
    printf("┏");
    for(int i=0;i<DIME-1;i++)
        printf("━━━┳");

    printf("━━━┓\n");
    for (int i=0; i<DIME-1 ; i++)
    {
        for(int j=0; j<DIME; j++)
            printf("┃ %c%s",bf[i][j],(j+1) % DIME ? " ":" ┃\n" );
        printf("┣");
        for(int i=0;i<DIME-1;i++)
            printf("━━━╋");

        printf("━━━┫\n");
    }
    for(int j=0; j<DIME; j++)
        printf("┃ %c%s",bf[DIME-1][j],(j+1) % DIME ? " ":" ┃\n" );
    printf("┗");
    for(int i=0;i<DIME-1;i++)
        printf("━━━┻");

    printf("━━━┛\n");
}


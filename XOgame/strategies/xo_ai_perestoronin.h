#define FIELD_SIZE DIME * DIME
#define SIDE_SIZE DIME
#define MADE_SHOT 0
#define NOT_FAST 0
#define NO_WAY 0
#define GOOD_WAY 1

int fast_decision(const char* const pos)
{
    int x = 0, o = 0, empty = 0;
    for (int i = 0; i < SIDE_SIZE; i++)
    {
        if (pos[i] == 'X')
            x++;
        if (pos[i] == 'O') 
            o++;
        if (pos[i] == ' ')
            empty = i + 1;
    }

    return (x == SIDE_SIZE - 1 || o == SIDE_SIZE - 1) ? empty : NOT_FAST;
}


int space_counter(char BF[][SIDE_SIZE], int *array)
{
    int counter = 0, k = 0;
    for (int i = 0; i < SIDE_SIZE; i++)
        for (int j = 0; j < SIDE_SIZE; j++)
            if (BF[i][j] == ' ')
            {
                counter++;
                array[k++] = i * SIDE_SIZE + j;
            } 
    return counter;
}


void column_array_maker(char BF[][SIDE_SIZE], char *col_arr, const int column)
{
    for (int i = 0; i < SIDE_SIZE; i++)
        col_arr[i] = BF[i][column];
}


void diag_array_maker(char BF[][SIDE_SIZE], char *col_arr)
{
    for (int i = 0; i < SIDE_SIZE; i++)
        col_arr[i] = BF[i][i];
}


void rev_diag_array_maker(char BF[][SIDE_SIZE], char *col_arr)
{
    for (int i = 0; i < SIDE_SIZE; i++)
        col_arr[i] = BF[i][SIDE_SIZE - 1 - i];
}


int check_row(char BF[][SIDE_SIZE], const int row, const char unsymb)
{
    for (int i = 0; i < SIDE_SIZE; i++)
    {
        if (BF[row][i] == unsymb)
            return NO_WAY;
    }
    return GOOD_WAY;
}


int check_column(char BF[][SIDE_SIZE], const int column, const char unsymb)
{
    for (int i = 0; i < SIDE_SIZE; i++)
    {
        if (BF[i][column] == unsymb)
            return NO_WAY;
    }
    return GOOD_WAY;
}


int check_diag(char BF[][SIDE_SIZE], const char unsymb)
{
    for (int i = 0; i < SIDE_SIZE; i++)
    {
        if (BF[i][i] == unsymb)
            return NO_WAY;
    }
    return GOOD_WAY;
}


int check_rev_diag(char BF[][SIDE_SIZE], const char unsymb)
{
    for (int i = 0; i < SIDE_SIZE; i++)
    {
        if (BF[i][SIDE_SIZE - 1 - i] == unsymb)
            return NO_WAY;
    }
    return GOOD_WAY;
}


int make_shot_perestoronin(const char symb, char BF[][SIDE_SIZE])
{
    int i, j, unsymb;
    int free_slots[FIELD_SIZE];
    int space_num = space_counter(BF, free_slots);
    char work_arr[SIDE_SIZE];
    unsymb = (symb == 'X') ? 'O' : 'X';

    if (BF[SIDE_SIZE / 2][SIDE_SIZE / 2] == ' ') 
    {
        BF[SIDE_SIZE / 2][SIDE_SIZE / 2] = symb;
        return MADE_SHOT;
    }

    for (i = 0; i < SIDE_SIZE; i++)
    {
        j = fast_decision(BF[i]);
        if (j != 0) 
        {
            BF[i][j - 1] = symb;
            return MADE_SHOT;
        }
        column_array_maker(BF, work_arr, i);
        j = fast_decision(work_arr);
        if (j != 0) 
        {
            BF[j - 1][i] = symb;
            return MADE_SHOT;
        }
    }

    diag_array_maker(BF, work_arr);
    j = fast_decision(work_arr);
    if (j-- != 0)
    {
        BF[j][j] = symb;
        return MADE_SHOT;
    }

    rev_diag_array_maker(BF, work_arr);
    j = fast_decision(work_arr);
    if (j-- != 0) 
    {
        BF[j][SIDE_SIZE - j - 1] = symb;
        return MADE_SHOT;
    }

    for (int i = 0; i < FIELD_SIZE; i++)
    {
        if (BF[i / SIDE_SIZE][i % SIDE_SIZE] == ' ')
            if (check_column(BF, i % SIDE_SIZE, unsymb) ||
                check_row(BF, i / SIDE_SIZE, unsymb) ||
                (i / SIDE_SIZE == i % SIDE_SIZE && check_diag(BF, unsymb)) ||
                (i / SIDE_SIZE == SIDE_SIZE - 1 - (i / SIDE_SIZE) && check_rev_diag(BF, unsymb)))
                {
                    BF[i / SIDE_SIZE][i % SIDE_SIZE] = symb;
                    return MADE_SHOT;
                }
    }

    i = rand() % space_num;
    j = free_slots[i];
    BF[j / SIDE_SIZE][j % SIDE_SIZE] = symb;
    return MADE_SHOT;
}

/* Распределение ролей по написанию модулей.

Прохорова Любовь, Кривозубов Владислав - функция check_win.
Илья Челядинов - функция copy_battlefield.
Лемешкин Богдан - функция print_battlefield.
Саркисов Артём, Топорков Павел - функция anti_cheat.

*/

#include <stdio.h>
#include <stdlib.h>

#include "strategies/xo_ai_olenev.h"
#include "strategies/xo_ai_nitenko.h"
#include "strategies/xo_ai_perestoronin.h"
#include "strategies/xo_ai_romanov.h"
#include "strategies/xo_ai_yakuba_harder.h"
#include "strategies/xo_ai_prokhorova.h"

#define DIME = 3

// 1 - cheat
// 0 - no cheat
int anti_cheat(int n, char before[][n], char after[][n])
{
    int x_cord[n * n];
    int y_cord[n * n];
    int n_x_y = 0;
    int cur = 0;
    int N = n;
    
    // Находим заполненные клетки до последнего хода.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (before[i][j] == 'X' || before[i][j] == 'O')
            {
                x_cord[n_x_y] = i;
                y_cord[n_x_y] = j;
                n_x_y++;
            }
    }
    
    // Находим кол-во заполненных клеток после последнего хода, а также проверяем, что новый ход корректен.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (after[i][j] == 'X' || after[i][j] == 'O')
                cur++;
            if (after[i][j] != 'X' && after[i][j] != 'O' && after[i][j] != ' ')
                return 1;
        }
    }
    
    // Проверям, что был сделан только один ход.
    if (cur - n_x_y != 1)
        return 1;
    
    // Проверяем, что ранне введенные данные не были изменены.
    for (int i = 0; i < n_x_y; i++)
        if (before[x_cord[i]][y_cord[i]] != after[x_cord[i]][y_cord[i]])
            return 1;
    return 0;
}

// 1 - win
// 0 - no win
int check_win_by_KV(char bf[][3])
{
    int limit = 3;

    // Если на главной диагонали пустые ячейки, то никто не выйграл.
    int ok = 1;
    for (int i = 0; i < limit; i++)
        if (bf[i][i] != ' ')
        {
            ok = 0;
            break;
        }	

    // Проверяем, есть ли достаточное количество X или O для завершения игры.
    int number_x, number_o = 0;
    for (int i = 0; i < limit; i++)
        for (int j = 0; j < limit; j++)
            if (bf[i][j] == 'X')
                number_x++;
            else if (bf[i][j] == 'O')
                number_o++;

    if ((number_x < limit && number_o < limit) || ok)
        return 0;
	
    // Проверка в строках.
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

    // Проверка в столбцах.
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

    // Главная диагональ.
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

    // Побочная диагональ.
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

int check_win_by_PL(char bf[][3])
{
    char start_el;
    int size = 3;
    int counter = 0;

	//Проверка строк.
    for (int i = 0; i < size; i++)
    {
        if (bf[i][0] != ' ')
        {
            start_el = bf[i][0];
            counter = 1;

            for (int j = 1; j < size; i++)
            {
                if (bf[i][j] == start_el)
                {
                    counter += 1;
                }
            }
        }
        if (counter == size)
        {
            return 1;
        }
    }

    //Проверка столбцов.
    for (int j = 0; j < size; j++)
    {
        if (bf[0][j] != ' ')
        {
            start_el = bf[0][j];
            counter = 1;

            for (int i = 1; i < size; i++)
            {
                if (bf[i][j] == start_el)
                {
                    counter += 1;
                }
            }
        }
        if (counter == size)
        {
            return 1;
        }
    }

    //Проверка главной диагонали.
    if (bf[0][0] != ' ')
    {
        start_el = bf[0][0];
        counter = 1;

        for (int i = 1; i < size; i++)
        {
            if (bf[i][i] == start_el)
            {
                counter += 1;
            }
        }

        if (counter == size)
        {
            return 1;
        }
    }

    //Проверка побочной диагонали.
    if(bf[0][size - 1] != ' ')
    {
        start_el = bf[0][size - 1];
        counter = 1;

        for (int i = 1; i < size; i++)
        {
            if (bf[i][size - 1 - i] == start_el)
            {
                counter += 1;
            }
        }

        if (counter == size)
        {
            return 1;
        }
    }

    return 0;
}

int copy_battlefield(char from[][3], char to[][3])
{
    int a = 0, b = 0;
    for (a; a < 3; a++)
        for (b; b < 3; b++)
            to[a][b] = from[a][b];
}

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

void bf_formation(int n, char mtx[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mtx[i][j] = ' ';
}

int main(void)
{
	printf("XO v0.1 (C) IU7");
	
	int win_home = 0, win_guest = 0;
    
    char BF[DIME][DIME];
    
    bf_formation(DIME, BF);

    char BF_COPY[DIME][DIME];

	for(int i = 0; i < 5; i++)
	{
		/* PLACE YOUR STRATEGIES HERE */
		/* DON'T FORGET TO INCLUDE YOUR HEADERS */
		
        make_shot_01('X', BF_COPY);

        if(anti_cheat(DIME, BF, BF_COPY))
		{
            win_guest++;
            continue;
        }

        copy_battlefield(BF_COPY, BF);

        if(check_win_by_KV(BF) && check_win_by_PL(BF))
		{
            win_home++;
            continue;
        }

        make_shot_02('O', BF_COPY);

        if(anti_cheat(DIME, BF, BF_COPY))
		{
            win_home++;
            continue;
        }

        copy_battlefield(BF_COPY, BF);

        if(check_win_by_KV(BF) && check_win_by_PL(BF))
		{
            win_guest++;
            continue;
        }
    }

    printf("SCORE: %d : %d", win_home, win_guest);

    return 0;
}

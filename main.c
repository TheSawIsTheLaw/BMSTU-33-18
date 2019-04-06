/* Распределение ролей по написанию модулей 

Прохорова Любовь, Кривозубов Владислав - функция check_win
Илья Челядинов - функция copy_battlefield
Лемешкин Богдан - функция print_battlefield
Саркисов Артём, Топорков Павел - функция anti_cheat

*/

#include <stdio.h>

#include <xo_ai_01.h>
#include <xo_ai_02.h>

// #include <xo_ai_02.h>
// #include <xo_ai_02.h>
// #include <xo_ai_02.h>
// #include <xo_ai_02.h>
// #include <xo_ai_02.h>
// #include <xo_ai_02.h>
// #include <xo_ai_02.h>


// 1 - cheat
// 0 - no cheat
int anti_cheat(char before[][3], char after[][3])
{
    return 1;
}

// 1 - win
// 0 - no win
int check_win(char bf[][3])
{
    return 0;
}

int copy_battlefield(char from[][3], char to[][3])
{
}

void print_battlefield(char bf[][3])
{

}


int main(void){
    printf("XO v0.1 (C) IU7");

    char BF[3][3] = {
        {' ', ' ', ' ' },
        {' ', ' ', ' ' },
        {' ', ' ', ' ' }
    };

    char BF_COPY[3][3];

   for(int i = 0; i < 5; i++){

        make_shot_01('X', BF_COPY);

        if(anti_cheat(BF, BF_COPY)){
            win_guest++;
            continue;
        }

        copy_battlefield(BF_COPY, BF);

        if(check_win(BF)){
            win_home++;
            continue;
        }

        make_shot_02('O', BF_COPY);

        if(anti_cheat(BF, BF_COPY)){
            win_home++;
            continue;
        }

        copy_battlefield(BF_COPY, BF);

        if(check_win(BF)){
            win_guest++;
            continue;
        }
    }

    printf("SCORE: %d : %d", win_home, win_guest);

    return 0;


    return 0;
}

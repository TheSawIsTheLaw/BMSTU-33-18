#include <stdio.h>
#include <stdlib.h>

#define DIME 3
#define GAME_OVER 0

/* Strategies include */
// #include "strategies/xo_ai_krivozubov.h"
// #include "strategies/xo_ai_prokhorova.h"
#include "strategies/xo_ai_perestoronin.h"
// #include "strategies/xo_ai_romanov.h"
// #include "strategies/xo_ai_yakuba.h"
#include "strategies/xo_ai_chernenko.h"

/* Functions include */
#include "functions/xo_func_anti_cheat_Toporkov_Sarkisov.h"
#include "functions/xo_func_bf_formation.h"
#include "functions/xo_func_check_win_Krivozubov.h"
#include "functions/xo_func_check_win_Prokhorova.h"
#include "functions/xo_func_copy_battlefield.h"
#include "functions/xo_func_print_battlefield_Lemeshkin.h"

int main(void)
{
    int winner = -1;
    char BF[DIME][DIME];
    char BF_COPY[DIME][DIME];

    printf("XO v0.1 (C) IU7\n");

    bf_formation(DIME, BF);

    printf("LET THE GAME BEGIN\n");

	for (int i = 0; i < DIME * DIME / 2 + 1; ++i)
    {
        copy_battlefield(BF, BF_COPY);

        make_shot_chernenko('X', BF_COPY);

        if (anti_cheat(DIME, BF, BF_COPY))
        {
            print_battlefield(BF_COPY);

            if (check_win_by_KV(BF_COPY) && check_win_by_PL(BF_COPY))
            {
                printf("The winner is player 1");

                break;
            }
            else
            {
                copy_battlefield(BF_COPY, BF);

                make_shot_chernenko('O', BF);

                if (anti_cheat(DIME, BF_COPY, BF))
                {
                    print_battlefield(BF);

                    if (check_win_by_KV(BF) && check_win_by_PL(BF))
                    {
                        printf("The winner is player 2");

                        break;
                    }
                }
                else
                {
                    printf("Oh, player 2 is cheating. The winner is player 1");

                    break;
                }
            }
        }
        else
        {
            printf("Oh, player 1 is cheating. The winner is player 2");

            break;
        }
    }

    return GAME_OVER;
}

#include <stdio.h>
#include <stdlib.h>

#define DIME 3

#define GAME_OVER 0
#define WIN_PLAYER_ONE -1
#define WIN_PLAYER_TWO -2

/* Strategies include */
// #include "strategies/xo_ai_krivozubov.h"
// #include "strategies/xo_ai_prokhorova.h"
// #include "strategies/xo_ai_perestoronin.h"
// #include "strategies/xo_ai_romanov.h"
// #include "strategies/xo_ai_yakuba.h"
// #include "strategies/xo_ai_chernenko.h"
// #include "strategies/xo_ai_sukocheva.h"
// #include "strategies/xo_ai_kononenko.h"
#include "strategies/xo_ai_kovalev.h"

/* Functions include */
#include "functions/xo_func_anti_cheat_Toporkov_Sarkisov.h"
#include "functions/xo_func_bf_formation.h"
#include "functions/xo_func_check_win_Krivozubov.h"
#include "functions/xo_func_check_win_Prokhorova.h"
#include "functions/xo_func_copy_battlefield.h"
#include "functions/xo_func_print_battlefield_Lemeshkin.h"

typedef void (*xo_strategy)(char, char[][DIME]);

int xogame_round(xo_strategy first_player_strategy, xo_strategy second_player_strategy)
{
    int shot_count = 0;
    char BF[DIME][DIME];
    char BF_COPY[DIME][DIME];

    printf("\nXO v0.1 (C) IU7\n");

    bf_formation(DIME, BF);

    printf("LET THE GAME BEGIN\n");

    for (int i = 0; i < DIME * DIME / 2 + 1; ++i)
    {
        copy_battlefield(BF, BF_COPY);

        first_player_strategy('X', BF_COPY);
        shot_count++;

        if (anti_cheat(DIME, BF, BF_COPY))
        {
            printf("Player's 1 shot:\n");
            print_battlefield(BF_COPY);
            printf("\n");

            if (check_win_by_KV(BF_COPY))
            {
                printf("The winner is player 1\n");

                return WIN_PLAYER_ONE;
            }
            else
            {
                if (shot_count == DIME * DIME)
                {
                    printf("Game tied!\n");

                    return GAME_OVER;
                }
                else
                {
                    copy_battlefield(BF_COPY, BF);

                    second_player_strategy('O', BF);
                    shot_count++;

                    if (anti_cheat(DIME, BF_COPY, BF))
                    {
                        printf("Player's 2 shot:\n");
                        print_battlefield(BF);
                        printf("\n");

                        if (check_win_by_KV(BF))
                        {
                            printf("The winner is player 2\n");

                            return WIN_PLAYER_TWO;
                        }
                        else
                        {
                            if (shot_count == DIME * DIME)
                            {
                                printf("Game tied!\n");

                                return GAME_OVER;
                            }
                        }
                    }
                    else
                    {
                        printf("Oh, player 2 is cheating. The winner is player 1\n");

                        return WIN_PLAYER_ONE;
                    }
                }
            }
        }
        else
        {
            printf("Oh, player 1 is cheating. The winner is player 2\n");

            return WIN_PLAYER_TWO;
        }
    }
}

int main()
{
    xogame_round(&make_shot_kovalev, &make_shot_kovalev);

    return 0;
}

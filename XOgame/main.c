#include <stdio.h>
#include <stdlib.h>

#define DIME 3
#define ever ;;

/* Strategies include */
#include "strategies/xo_ai_krivozubov.h"
#include "strategies/xo_ai_olenev.h"
#include "strategies/xo_ai_nitenko.h"
#include "strategies/xo_ai_perestoronin.h"
#include "strategies/xo_ai_romanov.h"
#include "strategies/xo_ai_yakuba_harder.h"
#include "strategies/xo_ai_prokhorova.h"

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
    copy_battlefield(BF, BF_COPY);

	for(ever)
    {
        // PLAYER'S 1 SHOT

        // ANTI-CHEAT CHECK FOR PLAYER'S 1 SHOT

        // CHECK FOR PLAYER'S 1 WIN

        // PLAYER'S 2 SHOT

        // ANTI-CHEAT CHECK FOR PLAYER'S 2 SHOT

        // CHECK FOR PLAYER'S 2 WIN
    }

    printf("SCORE: %d : %d", win_home, win_guest);

    return 0;
}

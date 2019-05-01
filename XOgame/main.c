#include <stdio.h>
#include <stdlib.h>

#define DIME 3

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
    int win_home = 0, win_guest = 0;
    char BF[DIME][DIME];
    char BF_COPY[DIME][DIME];

    printf("XO v0.1 (C) IU7\n");

    bf_formation(DIME, BF);
    copy_battlefield(BF, BF_COPY);

	for(int i = 0; i < 5; i++)
    {
        //  INSERT YOUR SHOT HERE!

        if(anti_cheat(DIME, BF, BF_COPY))
		{
            win_guest++;
            continue;
        }

        print_battlefield(BF_COPY);
        
        copy_battlefield(BF_COPY, BF);

        if(check_win_by_KV(BF) && check_win_by_PL(BF))
		{
            win_home++;
            continue;
        }

        //  INSERT YOUR SHOT HERE!

        if(anti_cheat(DIME, BF, BF_COPY))
		{
            win_home++;
            continue;
        }
        
        print_battlefield(BF_COPY);

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

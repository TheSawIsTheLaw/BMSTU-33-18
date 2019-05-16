#include <stdio.h>
#include <stdlib.h>

#define DIME 3
#define STUDENTS 4

#define GAME_OVER 0
#define WIN_PLAYER_ONE -1
#define WIN_PLAYER_TWO -2

#include "includes/xo_ai_strategies.h"
#include "includes/xo_ai_functions.h"

typedef void (*xo_strategy)(char, char[][DIME]);

int xogame_round(const char *first_player_name, const char *second_player_name,
                 xo_strategy first_player_strategy, xo_strategy second_player_strategy)
{
    int shot_count = 0;
    char BF[DIME][DIME];
    char BF_COPY[DIME][DIME];

    printf("----------------------------------------\n");
    printf("XO v0.1 (C) IU7\n");
    printf("----------------------------------------\n");

    bf_formation(DIME, BF);

    printf("LET THE GAME BEGIN\n\n");

    for (int i = 0; i < DIME * DIME / 2 + 1; ++i)
    {
        copy_battlefield(BF, BF_COPY);

        first_player_strategy('X', BF_COPY);
        shot_count++;

        if (anti_cheat(DIME, BF, BF_COPY))
        {
            printf("%s's shot:\n", first_player_name);
            print_battlefield(BF_COPY);
            printf("\n");

            if (check_win_by_KV(BF_COPY))
            {
                printf("The winner is %s\n", first_player_name);

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
                        printf("%s's shot:\n", second_player_name);
                        print_battlefield(BF);
                        printf("\n");

                        if (check_win_by_KV(BF))
                        {
                            printf("The winner is %s\n", second_player_name);

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
                        printf("Oh, %s is cheating. The winner is %s\n", second_player_name, first_player_name);

                        return WIN_PLAYER_ONE;
                    }
                }
            }
        }
        else
        {
            printf("Oh, %s is cheating. The winner is %s\n", first_player_name, second_player_name);

            return WIN_PLAYER_TWO;
        }
    }
}

int main()
{
    FILE *points_file;

    int points[STUDENTS] = { 0 };

    const char *students[] = {
            "Dmitriy Kovalev",
            "Krivozubov Vladislav",
            "Romanov Alexey",
            "Prokhorova Lyubov"
    };

    xo_strategy xo_strategies[] = {
            make_shot_kovalev,
            make_shot_krivozubov,
            make_shot_romanov,
            make_shot_prokhorova
    };

    for (int i = 0; i < STUDENTS - 1; ++i)
    {
        for (int j = i + 1; j < STUDENTS; ++j)
        {
            int res_first = xogame_round(students[i], students[j], xo_strategies[i], xo_strategies[j]);

            if (res_first == WIN_PLAYER_ONE)
                points[i] += 3;
            else
            {
                if (res_first == WIN_PLAYER_TWO)
                    points[j] += 3;
                else
                {
                    points[i] += 1;
                    points[j] += 1;
                }
            }

            int res_second = xogame_round(students[j], students[i], xo_strategies[j], xo_strategies[i]);

            if (res_second == WIN_PLAYER_ONE)
                points[j] += 3;
            else
            {
                if (res_second == WIN_PLAYER_TWO)
                    points[i] += 3;
                else
                {
                    points[i] += 1;
                    points[j] += 1;
                }
            }
        }
    }

    points_file = fopen("3x3division.txt", "w");

    fprintf(points_file, "!3x3 division ranking!\n\n");
    for (int i = 0; i < STUDENTS; ++i)
    {
        fprintf(points_file, "%s's points: %d\n", students[i], points[i]);
    }

    return 0;
}

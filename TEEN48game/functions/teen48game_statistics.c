// typedef struct
// {
//     int rows;
//     int columns;
//     int **matrix;
// } matrix_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <matrixgame.h>
// #include <unistd.h>

#include "../f_headers/teen48game_statistics.h"
#include "../f_headers/colors.h"

#define MAX_LEN 100

static score_t leaderboard[NOP];

// Сортировка вставками.
static void insertion_sort(score_t *array, int n)
{
    int new_element, location;

    for (int i = 1; i < n; i++)
    {
        new_element = array[i].score;
        location = i - 1;
        while (location >= 0 && array[location].score < new_element)
        {
            array[location + 1].score = array[location].score;
            array[location + 1].index = array[location].index;
            location = location - 1;
        }
        array[location + 1].score = new_element;
        array[location + 1].index = i;
    }
}

// matrix_array - массив игровых полей
// NOP - кол-во игроков и соответственно кол-во полей и элементов в массиве leaderboard
// leaderboard - вспомгательный массив для сортировки игроков по счету
// На выходе:
// Отсортирванный массив счетов игроков и их индексов
static void calc_statistic(const matrix_t *const matrix_array)
{
    int max;

    for (int k = 0; k < NOP; k++)
    {
        max = 0;

        for (int i = 0; i < matrix_array[k].rows; i++)
            for (int j = 0; j < matrix_array[k].columns; j++)
                if (matrix_array[k].matrix[i][j] > max)
                    max = matrix_array[k].matrix[i][j];

        leaderboard[k].index = k;
        leaderboard[k].score = max;
    }

    insertion_sort(leaderboard, NOP);
}

// █ ☁  ~
// 1. Вывод фамилии
// 2. Вывод ползунка со счетом (если максимальная длина = MAX_LEN клеточек,
// то для каждого игрока, cчет которого не равен максимальному
// длина ползунка = MAX_LEN * (текущий_счет / максимальный счет))
// 3. Вывод ползунка с временем (расчет остатка времени идет по формуле (для k-ого студента):
// MAX_LEN * (timer_limit - timer_array[k]) / timer_limit)
void live_print(matrix_t *const matrix_array, char surname_array[NOP][MAX_LEN_SURNAME], uint64_t *timer_array, uint64_t timer_limit)
{
    int iter_count = 0;
    int err_code = system("clear");
    if (err_code != 0) // проблемы с компиляцией с флагом -Werror, он требует принять значение от system
        return;

    calc_statistic(matrix_array);

    for (int k = 0; k < NOP; k++)
    {
        blue();
        printf("\n\tPlayer: ~%s \n\nScore: \t", surname_array[leaderboard[k].index]);

        iter_count = MAX_LEN * (leaderboard[k].score / (float)leaderboard[0].score);
        for (int i = 0; i <= iter_count; i++)
        {
            if (i >= 75)
                green();
            else if (i >= 25)
                yellow();
            else
                red();
            printf("█");
            err_code = system("sleep 0.00007s");
        }

        blue();
        printf("\n(Score is %d)\n", leaderboard[k].score);
        printf("Time: \t");

        iter_count = (timer_limit > timer_array[k]) ? MAX_LEN * (timer_limit - timer_array[k]) / (float)timer_limit : 0;            
            
        for (int i = 0; i < iter_count; i++)
        {
            if (i >= 75)
                green();
            else if (i >= 25)
                yellow();
            else
                red();
            printf("█");
            err_code = system("sleep 0.00007s");
        }
        printf("\n\n");
    }

    white();
    return;
}

// 1. Вывод списка лидеров (конечного)
// 2. Вывод матриц каждого игрока, если их размеры меньше чем 10?
// 3. Поздравления! (скрытытыттые!!!!)
void print_result(const matrix_t *matrix_array, char surname_array[NOP][MAX_LEN_SURNAME])
{
    int err_code = system("clear");
    if (err_code != 0)
        return;

    for (int k = 0; k < NOP; k++)
    {
        blue();
        printf("	________________________\n");

        if (!k)
        {
            green();
            // printf("\n\t\t  🥳\n\n");
            // char secret_code[] = {67, 111, 110, 103, 114, 97, 116, 117, 108, 97, 116, 105, 111, 110,
            //                       115, 44, 32, 121, 111, 117, 32, 97, 114, 101, 32, 116, 104, 101, 32,
            //                       119, 105, 110, 110, 101, 114, 44, 32, 109, 121, 32, 102, 114, 105, 101, 110, 100};
            // for (int i = 0; i < strlen(secret_code); i++)
            //     printf("%c", (char) secret_code[i]);
        }
        else if (k == NOP - 1)
            red();
        else
            yellow();
        printf("\n\n\tPlayer: %10s\n\n\tScore: %10d\n\n", surname_array[leaderboard[k].index], leaderboard[k].score);
        err_code = system("sleep 0.5s");
    }

    if (matrix_array[0].columns > 10 || matrix_array[0].rows > 10)
    {
        white();
        return;
    }

    printf("\n\n\n");
    for (int k = 0; k < NOP; k++)
    {
        blue();
        printf("\t");
        for (int i = 0; i < matrix_array[0].columns; i++)
        {
            printf("______");
            if (i == matrix_array[0].columns / 3)
                printf("%s", surname_array[leaderboard[k].index]);
        }
        printf("\n\n");

        for (int i = 0; i < matrix_array[leaderboard[k].index].rows; i++)
        {
            printf("\t");
            for (int j = 0; j < matrix_array[leaderboard[k].index].columns; j++)
            {
                if (matrix_array[leaderboard[k].index].matrix[i][j] == leaderboard[k].score)
                    green();
                else
                    yellow();
                printf("%5d ", matrix_array[leaderboard[k].index].matrix[i][j]);
            }
            printf("\n\n");
        }
        printf("\n\n\n");
        err_code = system("sleep 0.5s");
    }
    // blinks();
    //     printf("████████████████████████████████████████████████\n
    // █───█───█───█─██─█─████────█────█────█─███─█───█\n
    // ██─██─███─███──█─█─██─█─██─█─████─██─█──█──█─███\n
    // ██─██───█───█─█──█────█────█─█──█────█─█─█─█───█\n
    // ██─██─███─███─██─████─█─██─█─██─█─██─█─███─█─███\n
    // ██─██───█───█─██─████─█────█────█─██─█─███─█───█\n
    // ████████████████████████████████████████████████\n");

    //     printf("######~#####~~#####~~##~~##~##~~~~~~####~~~####~~~####~~##~~~#~#####\n
    // ~~##~~~##~~~~~##~~~~~###~##~##~~##~##~~##~##~~~~~##~~##~###~##~##\n
    // ~~##~~~####~~~####~~~##~###~######~~####~~##~###~######~##~#~#~####\n
    // ~~##~~~##~~~~~##~~~~~##~~##~~~~~##~##~~##~##~~##~##~~##~##~~~#~##\n
    // ~~##~~~#####~~#####~~##~~##~~~~~##~~####~~~####~~##~~##~##~~~#~#####\n");
    white();
}

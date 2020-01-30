#include <stdlib.h>
#include <time.h>
#include "../p_headers/teen48game_player_burtelov.h"

#define ERROR 0
#define STEP 15


short time_rand_offset(long long offset, short k)
{
    if (offset % 10 <= 5)
        return k;
    else
        return ++k;
}

short time_rand(time_t *time_now)
{
    long long offset, param;
    short k = 0;
    //произвольное значение(15)
    param = rand() % STEP;
    param++;
    //текущее время
    *time_now = time(NULL);

    if (param <= 5)
    {
        offset = *time_now / param;
        return time_rand_offset(offset, k);
    }
    else if (param > 5  && param <= 10)
    {
        k = 1;
        offset = *time_now / (param * 2);
        return time_rand_offset(offset, k);
    }
    else
    {
        k = 2;
        offset = *time_now / (param * 3);
        return time_rand_offset(offset, k);
    }
}


char teen48game_player_burtelov(matrix_t *const matrix_buffer, int (*to_step)(matrix_t *const, const char))
{
    time_t time_now = 0;

    srand(time(NULL));

    switch (time_rand(&time_now))
    {
        case 0:
            return 'r';
        case 1:
            return 'l';
        case 2:
            return 'd';
        case 3:
            return 'u';
    }

    // возвращаем одно из 4 направлений: 'r', 'l', 'd', 'u'
    return ERROR; // до сюда не дойдет
}

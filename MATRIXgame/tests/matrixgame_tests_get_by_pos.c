#include "../headers/matrixgame_headers_get_by_pos.h"

#define PASSED 0
#define FAILED 1

int matrixgame_get_by_pos_test()
{
    return PASSED;
}

int main()
{
    if (matrixgame_get_by_pos_test() != PASSED)
    {
        return FAILED;
    }

    return PASSED;
}

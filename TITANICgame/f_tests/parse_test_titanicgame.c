#include "../f_headers/parse_titanicgame.h"

#define TESTSET 418
#define TRAINSET 891

#define OK 0

int main()
{
    passenger test_p[TESTSET], train_p[TRAINSET];
    parse(test_p, train_p);

    return OK;
}
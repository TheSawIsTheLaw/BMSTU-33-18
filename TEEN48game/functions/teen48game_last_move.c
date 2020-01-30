#include "../f_headers/teen48game_last_move.h"

#define IN_BOUNDS 1
#define OUT_OF_BOUNDS 0

static int inbounds(matrix_t *m, const int j, const int i)
{
    if (j >= m->rows || j < 0)
        return OUT_OF_BOUNDS;
    
    if (i >= m->columns || i < 0)
        return OUT_OF_BOUNDS;

    return IN_BOUNDS;
}

int last_move(matrix_t *m)
{
    int neigh_eq = 0;

    for (int j = 0; j < m->rows; j++)
        for (int i = 0; i < m->columns; i++)
        {
            if (inbounds(m, j + 1, i))
                if (m->matrix[j][i] == m->matrix[j + 1][i])
                    neigh_eq += 1;

            if (inbounds(m, j, i + 1))
                if (m->matrix[j][i] == m->matrix[j][i + 1])
                    neigh_eq += 1;
        }

    if (neigh_eq > 0)
        return IS_NOT_LAST_MOVE;

    return IS_LAST_MOVE;
}

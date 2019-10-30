#include "../f_headers/delete_titanicgame.h"
#include <stdlib.h>

#define VERTEX_ERROR 17
#define OK 0

void delete_vertex(node *vertex)
{
    if (!vertex)
        return;
    delete_vertex(vertex->yes);
    delete_vertex(vertex->no);
    free(vertex);
    vertex = NULL;
}
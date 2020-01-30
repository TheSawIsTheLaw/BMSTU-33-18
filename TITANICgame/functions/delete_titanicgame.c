/**
 * \file delete_titanicgame.c
 * \brief Функция удаляет вершину. (Function deletes vertex)
 */

#include "../f_headers/delete_titanicgame.h"
#include <stdlib.h>

/**
 * \def VERTEX_ERROR
 * \brief Бесполезный код, зачем он тут вообще? (Useless define. Thx, Pepperonin)
 */
#define VERTEX_ERROR 17
/**
 * \def OK
 * \brief Бесполезный код, зачем он тут вообще? (Useless define. Thx, Pepperonin)
 */
#define OK 0

/**
 * \fn void delete_vertex(node *vertex)
 *
 * \param node *vertex - указатель на удаляемую вершину (pointer to vertex)
 *
 * \brief Удаляет вершину (deletes a node)
 */
void delete_vertex(node *vertex)
{
    if (!vertex)
        return;
    delete_vertex(vertex->yes);
    delete_vertex(vertex->no);
    free(vertex);
    vertex = NULL;
}
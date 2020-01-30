/**
 * \file add_titanicgame.c
 * \brief Функция соединяет узлы между собой. (Function connects nodes)
 */

#include "../f_headers/add_titanicgame.h"

/**
 * \fn int add(node *parent, bool choice, node *new_node)
 *
 * \param node *parent - родительский узел
 * \param bool choice - направление присоединения
 * \param node *new_node - дочерний узел
 *
 * \brief Cоединяет узлы между собой (connects nodes)
 */
int add(node *parent, bool choice, node *new_node)
{
    if (!parent)
    {
        return PARENT_IS_EMPTY;
    }

    if (!new_node)
    {
        return NODE_IS_EMPTY;
    }

    if (choice)
    {
        parent -> yes = new_node;
    }
    else
    {
        parent -> no = new_node;
    }

    return OK;
}
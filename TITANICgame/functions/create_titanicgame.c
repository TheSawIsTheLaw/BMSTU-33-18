/**
 * \file create_titanicgame.c
 * \brief Функция создаёт узел. (Function creates a node)
 */

#include "../f_headers/create_titanicgame.h"

/**
 * \fn node* create(bool (*decision)(passenger info))
 *
 * \param bool (*decision)(passenger info) - указатель на функцию определения выбора (pointer to function of choice)
 *
 * \brief Создаёт узел (makes a node)
 */
node* create(bool (*decision)(passenger info))
{
    node *new = NULL;
    
    if ((new = malloc(sizeof(node))) == NULL)
    {
        return NULL;
    }

    new -> no = NULL;
    new -> yes = NULL;
    new -> decision = decision;

    return new;
}

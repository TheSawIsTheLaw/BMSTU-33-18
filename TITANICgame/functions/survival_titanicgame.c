/**
 * \file survival_titanicgame.c
 * \brief Выживание титаникгейм. Я код ревьюер? Надеюсь, что нет. Потому что я уже ничего тут не понимаю. (unction does smth)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TITANICgame/f_headers/survival_titanicgame.h"
#include "TITANICgame/headers/struct.h"
#include "TITANICgame/f_headers/add_titanicgame.h"
#include "TITANICgame/f_headers/create_titanicgame.h"
#include "TITANICgame/f_headers/delete_titanicgame.h"
#include "TITANICgame/d_trees_headers/member_name_header.h"

/**
 * \fn int check_survival(const passenger a, node* root)
 *
 * \param const passenger a - особая структура данных, описывающая пассажира судьбу ("unique" passenger's sruct)
 * \param node* root - узел (node(who))
 *
 * \brief ПрОвЕрИтЬ ВыЖиЛ (check survival (who))
 */
int check_survival(const passenger a, node* root)
{
    node* pt = root;
    bool result = FALSE;
    
    while (pt != NULL)
    {
        result = pt -> decision(a);
        
        if ((pt -> no == NULL) && (pt -> yes == NULL))
            return result;
        if (result == FALSE)
        {
            if( pt -> no == NULL)
                return result;
            else
                pt = pt -> no;
        }
        else
        {
            if (pt -> yes == NULL)
                return result;
            else
                pt = pt -> yes;
        }
    }
    return result;
}

/**
 * \fn int check_arr(passenger *data, const int size, const int flag, node* root)
 *
 * \param passenger *data - информация о пассажире (passenger's info)
 * \param const int size - РаЗмЕр (чего?) (size of smth...)
 * \param const int flag - флаг вам в руки, господа и дамы, с такими комментариями (шучу, их не было!)))0)) ) (flag)
 * \param node* root - узел (node)
 *
 * \brief Проверяет массив, наверное (array check) 
 */
int check_arr(passenger *data, const int size, const int flag, node* root)
{
    FILE *f;
    f = fopen("TITANICgame/submission/submission.csv", "w");
    if (f == NULL)
    {
        return FOPEN_ERROR;
    }
    fprintf(f, "PassengerId,Survived\n");
    int sum = 0;
    int result;
    for (int i = 0; i < size; i++)
    {
        result = check_survival(data[i], root);
        if ((flag == 0) && result == data[i].survived)
            sum++;
        if (flag == 1)
            fprintf(f, "%d,%d\n", data[i].passenger_id, result);
    }
    fclose(f);
    int percent = ((sum * 1.0) / size) * PERCENT;
    
    return percent;
}

/**
 * \fn int check_void(node* (*decision_tree)(), passenger *people)
 *
 * \param node* (*decision_tree)() - указатель на функцию принятия решений (ointer to function of choices)
 * \param passenger *people - пассажиры люди (who) (?array? of passengers)
 *
 * \brief Проверить ПуСтОтУ... (void, we need your sphere now!)
 */
int check_void(node* (*decision_tree)(), passenger *people)
{
    node* root = decision_tree();
    int percent = check_arr(people, 3, 0, root);
    int fc = check_arr(people, 3, 1, root);
    if (fc == FOPEN_ERROR)
    {
        delete_vertex(root);
        return fc;
    }
    delete_vertex(root);
    return percent;
}

/**
 * \fn int main(void)
 *
 * \brief Точка входа в программу (entry)
 */
int main()
{
    passenger people[ARR_SIZE];  //structs array

    int result = check_void(function_name, people);
    printf("%d", result);
}

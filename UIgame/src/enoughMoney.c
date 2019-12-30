#include "../include/enoughMoney.h"

/*!
 * @brief enough_money(char *str1, char* str2) - ф-ия проверки баланса при переводе
 * @param char *str1 - указатель на строку_1, баланс
 * @param char *str2 - указатель на строку_2, сумма перевода
 * @return EXIT_FAILURE - баланс мал для перевода
 * @return EXIT_SUCCESS - баланс достаточен для перевода
 */
int enoughMoney(char *str1, char* str2)
{
    int i = 0;

    if (atof(str1) < 0 || atof(str2) < 0)
        return EXIT_FAILURE;
/*!
* @brief Проверка символов str1
*/
    while (str1[i])
    {
        if ((str1[i] < 48 || str1[i] > 57) && str1[i] != '.')
            return EXIT_FAILURE;

        i++;
    }

    i = 0;
/*!
* @brief Проверка символов str2
*/
    while (str2[i])
    {
        if ((str2[i] < 48 || str2[i] > 57) && str2[i] != '.')
            return EXIT_FAILURE;

        i++;
    }

    if (atof(str1) < atof(str2))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

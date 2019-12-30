#include "enough_money.h"

/*!
 * @brief enough_money(char *str1, char* str2) - ф-ия проверки баланса при переводе
 * @param char *str1 - указатель на строку_1, баланс
 * @param char *str2 - указатель на строку_2, сумма перевода
 * @return EXIT_FAILURE - баланс мал для перевода
 * @return EXIT_SUCCESS - баланс достаточен для перевода
 */
int enough_money(char *str1, char* str2)
{
    if (check(str1) == EXIT_FAILURE || check(str2) == EXIT_FAILURE)
        return EXIT_FAILURE;

    if (atof(str1) < atof(str2))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

/*!
 * @brief check(char *str) - ф-ия проверки ввода
 * @param char *str - указатель на строку
 * @return EXIT_FAILURE - ввод ERROR
 * @return EXIT_SUCCESS - ввод корректный
 */
int check(char *str)
{
    int i = 0;

    if (atof(str) < 0)
        return EXIT_FAILURE;

    while (str[i])
    {
        if ((str[i] < 48 || str[i] > 57) && str[i] != '.')
            return EXIT_FAILURE;

        i++;
    }

    return EXIT_SUCCESS;
}
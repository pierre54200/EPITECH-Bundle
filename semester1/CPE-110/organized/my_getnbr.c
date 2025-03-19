/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** task05
*/
#include "include/proto.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != 0) {
        len = len + 1;
    }
    return (len);
}

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    int i = 0;

    for (; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    }
    result = s1[i] - s2[i];
    return result;
}

int my_tablen(char **tab)
{
    int len = 0;

    while (tab[len] != 0) {
        len = len + 1;
    }
    return (len);
}

int my_getnbr(char const *str)
{
    int sign = 1;
    double nb = 0;
    int nb2 = 0;

    for (int i = 0; str[i] != 0 && ((str[i] >= '0' && str[i] <= '9')
    || (str[i] == '-' || str[i] == '+')); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nb = 10 * nb + str[i] - '0';
        if (str[i] == '-')
            sign = - sign;
    }
    nb = nb * sign;
    if (nb > 2147483647 || nb < -2147483648)
            return 0;
    nb2 = nb;
    return nb2;
}

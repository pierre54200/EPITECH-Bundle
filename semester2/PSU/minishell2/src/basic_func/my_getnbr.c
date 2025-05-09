/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** task05
*/
#include "proto.h"

int is_a_nbr(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
    }
    return 1;
}

int my_getnbr(char *str)
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

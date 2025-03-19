/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** task05
*/
#include "include/proto.h"

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

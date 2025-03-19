/*
** EPITECH PROJECT, 2024
** my_unsigned_decimal
** File description:
** convert into unsigned decimal
*/
#include "proto.h"

int my_unsigned_decimal(va_list list, int nbvir, char *flag)
{
    int nb = va_arg(list, int);

    if (nb < 0)
        return 0;
    return (my_put_nbr(nb));
}

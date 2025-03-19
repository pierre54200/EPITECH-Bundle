/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** display a float
*/
#include <stdio.h>
#include <stdarg.h>
#include "proto.h"

int my_put_double_f(va_list list, int nbvir, char *flag)
{
    int size = 0;
    int i = 0;
    double nb2 = 0;
    double nb = va_arg(list, double);

    if (flag[0] != '\0')
        size = size + flag_handler_double(flag, nb, 1);
    if (nb < 0) {
        nb = (-1) * nb;
        my_putchar('-');
        size++;
    }
    nb = nb + 5 / puissancedouble_10(nbvir + 1);
    for (double counter = nb; counter >= 1; i++)
        counter = counter / 10;
    size = size + my_put_double(nb, i);
    nb2 = my_recup_decimal(nb, i);
    nb = (nb - nb2) * puissancedouble_10(nbvir);
    my_putchar('.');
    return size + my_put_double(nb, nbvir) + 1;
}

/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** display a float
*/
#include <stdio.h>
#include "dproto.h"

int my_dput_double_f(double nb, int nbvir, char *flag, int fd)
{
    int size = 0;
    int i = 0;
    double nb2 = 0;

    if (flag[0] != '\0')
        size = size + dflag_handler_double(flag, nb, 1, fd);
    if (nb < 0) {
        nb = (-1) * nb;
        my_dputchar('-', fd);
        size++;
    }
    nb = nb + 5 / dpuissancedouble_10(nbvir + 1);
    for (double counter = nb; counter >= 1; i++)
        counter = counter / 10;
    size = size + my_dput_double(nb, i, fd);
    nb2 = my_drecup_decimal(nb, i, fd);
    nb = (nb - nb2) * dpuissancedouble_10(nbvir);
    my_dputchar('.', fd);
    size = size + my_dput_double(nb, nbvir, fd);
    return size + 1;
}

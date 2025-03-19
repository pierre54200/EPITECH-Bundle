/*
** EPITECH PROJECT, 2024
** my_put_double_e.c
** File description:
** flag e and E
*/
#include <stdio.h>
#include "dproto.h"

static int my_dput_power(int i, int test, int test2, int fd)
{
    if (test == 0)
        my_dputchar('e', fd);
    if (test == 1)
        my_dputchar('E', fd);
    if (test2 == 1)
        my_dputchar('-', fd);
    if (test2 == 0)
        my_dputchar('+', fd);
    if (i >= 10)
        my_dput_nbr(i, fd);
    if (i < 10) {
        my_dputchar('0', fd);
        my_dput_nbr(i, fd);
    }
    return 4;
}

static int my_dput_double_zero(int nbvir, int test, int fd)
{
    my_dputchar('0', fd);
    my_dputchar('.', fd);
    for (int i = 0; nbvir != i; i++)
        my_dputchar('0', fd);
    return nbvir + 2 + my_dput_power(0, test, 0, fd);
}

static int my_dput_double_plus(double nb, int nbvir, int test, int fd)
{
    int size = 0;
    int i = 0;
    double nb2 = 0;
    int stock_decimal = 0;

    nb = nb + 5 / dpuissancedouble_10(nbvir + 1);
    for (double counter = nb; counter >= 1; i++)
        counter = counter / 10;
    size = size + my_dput_double(nb / dpuissancedouble_10(i - 1), 1, fd);
    stock_decimal = my_drecup_decimal(nb / dpuissancedouble_10(i - 1), 1, fd);
    nb = (nb / dpuissance_10(i - 1) - stock_decimal);
    nb = nb * dpuissancedouble_10(nbvir);
    my_dputchar('.', fd);
    size = size + my_dput_double(nb, nbvir, fd)
        + my_dput_power(i - 1, test, 0, fd);
    return size + 1;
}

static int my_dput_double_neg(double nb, int nbvir, int test, int fd)
{
    int size = 0;
    int i = 0;
    double nb2 = 0;
    int stock_decimal = 0;

    for (double counter = nb; counter < 1; i++)
        counter = counter * 10;
    nb = nb * dpuissancedouble_10(2 * i);
    nb = nb + 5 / dpuissancedouble_10(nbvir);
    size = size + my_dput_double(nb / dpuissancedouble_10(i), 1, fd);
    stock_decimal = my_drecup_decimal(nb / dpuissancedouble_10(i), 1, fd);
    nb = (nb / dpuissance_10(i) - stock_decimal) * dpuissancedouble_10(nbvir);
    my_dputchar('.', fd);
    size = size + my_dput_double(nb, nbvir, fd)
        + my_dput_power(i, test, 1, fd);
    return size + 1;
}

int my_dput_double_e_maj(double nb, int nbvir, char *flag, int fd)
{
    int size = 0;

    if (flag[0] != '\0')
        size = size + dflag_handler_double(flag, nb, 1, fd);
    if (nb < 0) {
        nb = (-1) * nb;
        my_dputchar('-', fd);
        size++;
    }
    if (nb == 0)
        return size + my_dput_double_zero(nbvir, 1, fd);
    if (nb >= 1)
        return size + my_dput_double_plus(nb, nbvir, 1, fd);
    if (nb < 1)
        return size + my_dput_double_neg(nb, nbvir, 1, fd);
}

int my_dput_double_e(double nb, int nbvir, char *flag, int fd)
{
    int size = 0;

    if (flag[0] != '\0')
        size = size + dflag_handler_double(flag, nb, 1, fd);
    if (nb < 0) {
        nb = (-1) * nb;
        my_dputchar('-', fd);
        size++;
    }
    if (nb == 0)
        return size + my_dput_double_zero(nbvir, 0, fd);
    if (nb >= 1)
        return size + my_dput_double_plus(nb, nbvir, 0, fd);
    if (nb < 1)
        return size + my_dput_double_neg(nb, nbvir, 0, fd);
}

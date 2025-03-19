/*
** EPITECH PROJECT, 2024
** my_put_double_e.c
** File description:
** flag e and E
*/
#include <stdio.h>
#include "proto.h"
#include <stdarg.h>

static int my_put_power(int i, int test, int test2)
{
    if (test == 0)
        my_putchar('e');
    if (test == 1)
        my_putchar('E');
    if (test2 == 1)
        my_putchar('-');
    if (test2 == 0)
        my_putchar('+');
    if (i >= 10)
        my_put_nbr(i);
    if (i < 10) {
        my_putchar('0');
        my_put_nbr(i);
    }
    return 4;
}

static int my_put_double_zero(int nbvir, int test)
{
    my_putchar('0');
    my_putchar('.');
    for (int i = 0; nbvir != i; i++)
        my_putchar('0');
    return nbvir + 2 + my_put_power(0, test, 0);
}

static int my_put_double_plus(double nb, int nbvir, int test)
{
    int size = 0;
    int i = 0;
    double nb2 = 0;
    int stock_decimal = 0;

    nb = nb + 5 / puissancedouble_10(nbvir + 1);
    for (double counter = nb; counter >= 1; i++)
        counter = counter / 10;
    size = size + my_put_double(nb / puissancedouble_10(i - 1), 1);
    stock_decimal = my_recup_decimal(nb / puissancedouble_10(i - 1), 1);
    nb = (nb / puissance_10(i - 1) - stock_decimal);
    nb = nb * puissancedouble_10(nbvir);
    my_putchar('.');
    size = size + my_put_double(nb, nbvir) + my_put_power(i - 1, test, 0);
    return size + 1;
}

static int my_put_double_neg(double nb, int nbvir, int test)
{
    int size = 0;
    int i = 0;
    double nb2 = 0;
    int stock_decimal = 0;

    for (double counter = nb; counter < 1; i++)
        counter = counter * 10;
    nb = nb * puissancedouble_10(2 * i);
    nb = nb + 5 / puissancedouble_10(nbvir);
    size = size + my_put_double(nb / puissancedouble_10(i), 1);
    stock_decimal = my_recup_decimal(nb / puissancedouble_10(i), 1);
    nb = (nb / puissance_10(i) - stock_decimal) * puissancedouble_10(nbvir);
    my_putchar('.');
    size = size + my_put_double(nb, nbvir) + my_put_power(i, test, 1);
    return size + 1;
}

int my_put_double_e_maj(va_list list, int nbvir, char *flag)
{
    int size = 0;
    double nb = va_arg(list, double);

    if (flag[0] != '\0')
        size = size + flag_handler_double(flag, nb, 1);
    if (nb < 0) {
        nb = (-1) * nb;
        my_putchar('-');
        size++;
    }
    if (nb == 0)
        return size + my_put_double_zero(nbvir, 1);
    if (nb >= 1)
        return size + my_put_double_plus(nb, nbvir, 1);
    if (nb < 1)
        return size + my_put_double_neg(nb, nbvir, 1);
}

int my_put_double_e(va_list list, int nbvir, char *flag)
{
    int size = 0;
    double nb = va_arg(list, double);

    if (flag[0] != '\0')
        size = size + flag_handler_double(flag, nb, 1);
    if (nb < 0) {
        nb = (-1) * nb;
        my_putchar('-');
        size++;
    }
    if (nb == 0)
        return size + my_put_double_zero(nbvir, 0);
    if (nb >= 1)
        return size + my_put_double_plus(nb, nbvir, 0);
    if (nb < 1)
        return size + my_put_double_neg(nb, nbvir, 0);
}

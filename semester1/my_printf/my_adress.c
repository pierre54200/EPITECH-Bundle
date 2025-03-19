/*
** EPITECH PROJECT, 2024
** my_adress.c
** File description:
** flag p
*/
#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include <stdarg.h>

int my_hexalong(long long nb)
{
    char *stock;
    long long nb2 = 0;
    int size = 0;

    stock = malloc(sizeof(char *) * 30);
    for (int i = 0; nb > 0; i++) {
        nb2 = nb % 16;
        if (nb2 + '0' > '9')
            nb2 = nb2 + 7 + 32;
        stock[i] = nb2 + '0';
        nb = nb / 16;
        size++;
    }
    my_revstr(stock);
    my_putstr(stock);
    return size;
}

int my_adress(va_list list, int nbvir, char *flag)
{
    long long nb = va_arg(list, long long);

    if (nb == 0)
        return my_putstr("(nil)");
    return my_putstr("0x") + my_hexalong(nb);
}

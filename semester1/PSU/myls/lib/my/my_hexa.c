/*
** EPITECH PROJECT, 2024
** hexax.c
** File description:
** transform nb in hexa
*/
#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include <stdarg.h>

int my_hexamaj(va_list list, int nbvir, char *flag)
{
    char *stock;
    int nb2 = 0;
    int size = 0;
    int nb = va_arg(list, int);

    size = size + flag_handler_int(flag, nb, 1, 0);
    stock = malloc(sizeof(char *) * 15);
    for (int i = 0; nb > 0; i++) {
        nb2 = nb % 16;
        if (nb2 + '0' > '9')
            nb2 = nb2 + 7;
        stock[i] = nb2 + '0';
        nb = nb / 16;
        size++;
    }
    my_revstr(stock);
    my_putstr(stock);
    return size;
}

int my_hexamin(va_list list, int nbvir, char *flag)
{
    char *stock;
    int nb2 = 0;
    int size = 0;
    int nb = va_arg(list, int);

    size = size + flag_handler_int(flag, nb, 2, 0);
    stock = malloc(sizeof(char *) * 15);
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

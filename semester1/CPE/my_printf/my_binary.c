/*
** EPITECH PROJECT, 2024
** my_binary.c
** File description:
** flag b
*/
#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include <stdarg.h>

int my_binary(va_list list, int nbvir, char *flag)
{
    char *stock;
    int nb2 = 0;
    int size = 0;
    int nb = va_arg(list, int);

    size = size + flag_handler_int(flag, nb, 4, 0);
    stock = malloc(sizeof(char *) * 15);
    for (int i = 0; nb > 0; i++) {
        nb2 = nb % 2;
        stock[i] = nb2 + '0';
        nb = nb / 2;
        size++;
    }
    my_revstr(stock);
    my_putstr(stock);
    return size;
}

int my_binary_maj(va_list list, int nbvir, char *flag)
{
    char *stock;
    int nb2 = 0;
    int size = 0;
    int nb = va_arg(list, int);

    size = size + flag_handler_int(flag, nb, 5, 0);
    stock = malloc(sizeof(char *) * 15);
    for (int i = 0; nb > 0; i++) {
        nb2 = nb % 2;
        stock[i] = nb2 + '0';
        nb = nb / 2;
        size++;
    }
    my_revstr(stock);
    my_putstr(stock);
    return size;
}

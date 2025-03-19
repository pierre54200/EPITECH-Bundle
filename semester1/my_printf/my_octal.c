/*
** EPITECH PROJECT, 2024
** my_octal
** File description:
** convert and display an int into an unsigned octal
*/
#include "proto.h"
#include <stdlib.h>
#include <stdarg.h>

int my_octal(va_list list, int nbvir, char *flag)
{
    char *stock;
    int nb2 = 0;
    int size = 0;
    int nb = va_arg(list, int);

    size = size + flag_handler_int(flag, nb, 3, 1);
    stock = malloc(sizeof(char *) * 15);
    for (int i = 0; nb > 0; i++) {
        nb2 = nb % 8;
        stock[i] = nb2 + '0';
        nb = nb / 8;
        size++;
    }
    my_revstr(stock);
    my_putstr(stock);
    return size;
}

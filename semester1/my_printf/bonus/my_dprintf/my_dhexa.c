/*
** EPITECH PROJECT, 2024
** hexax.c
** File description:
** transform nb in hexa
*/
#include <stdio.h>
#include <stdlib.h>
#include "dproto.h"

int my_dhexamaj(int nb, char *flag, int fd)
{
    int i = 0;
    char *stock;
    int nb2 = 0;
    int size = 0;

    size = size + dflag_handler_int(flag, nb, 1, fd);
    stock = malloc(sizeof(char *) * 15);
    for (; nb > 0; i++) {
        nb2 = nb % 16;
        if (nb2 + '0' > '9')
            nb2 = nb2 + 7;
        stock[i] = nb2 + '0';
        nb = nb / 16;
    }
    my_drevstr(stock, fd);
    my_dputstr(stock, fd);
    return i + size;
}

int my_dhexamin(int nb, char *flag, int fd)
{
    int i = 0;
    char *stock;
    int nb2 = 0;
    int size = 0;

    size = size + dflag_handler_int(flag, nb, 2, fd);
    stock = malloc(sizeof(char *) * 15);
    for (; nb > 0; i++) {
        nb2 = nb % 16;
        if (nb2 + '0' > '9')
            nb2 = nb2 + 7 + 32;
        stock[i] = nb2 + '0';
        nb = nb / 16;
    }
    my_drevstr(stock, fd);
    my_dputstr(stock, fd);
    return i + size;
}

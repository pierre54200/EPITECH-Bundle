/*
** EPITECH PROJECT, 2024
** my_octal
** File description:
** convert and display an int into an unsigned octal
*/
#include "fproto.h"
#include <stdlib.h>

int my_foctal(int nb, char *flag, int fd)
{
    int i = 0;
    char *stock;
    int nb2 = 0;
    int size = 0;

    size = size + fflag_handler_int(flag, nb, 3, fd);
    stock = malloc(sizeof(char *) * 15);
    for (; nb > 0; i++) {
        nb2 = nb % 8;
        stock[i] = nb2 + '0';
        nb = nb / 8;
    }
    my_frevstr(stock, fd);
    my_fputstr(stock, fd);
    return i + size;
}

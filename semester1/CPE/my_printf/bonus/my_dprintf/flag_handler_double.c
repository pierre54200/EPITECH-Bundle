/*
** EPITECH PROJECT, 2024
** flag_handler.c
** File description:
** handle every flag
*/
#include <stdio.h>
#include "dproto.h"
static int signof(double nb, int fd)
{
    if (nb >= 0) {
        my_dputchar('+', fd);
        return 1;
    }
    return 0;
}

int dflag_handler_double(char *flag, double nb, int test, int fd)
{
    int size = 0;

    for (int i = 0; flag[i] != '\0'; i++) {
        if (flag[i] == '+')
            size = size + signof(nb, fd);
    }
    return size;
}

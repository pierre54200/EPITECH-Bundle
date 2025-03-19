/*
** EPITECH PROJECT, 2024
** flag_handler.c
** File description:
** handle every flag
*/
#include <stdio.h>
#include "proto.h"
static int signof(double nb)
{
    if (nb >= 0) {
        my_putchar('+');
        return 1;
    }
    return 0;
}

int flag_handler_double(char *flag, double nb, int test)
{
    int size = 0;

    for (int i = 0; flag[i] != '\0'; i++) {
        if (flag[i] == '+')
            size = size + signof(nb);
    }
    return size;
}

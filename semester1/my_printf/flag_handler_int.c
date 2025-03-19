/*
** EPITECH PROJECT, 2024
** flag_handler_int.c
** File description:
** handle every flag
*/
#include <stdio.h>
#include "proto.h"
#include <stdarg.h>

static int dashof(int test)
{
    if (test == 1)
        return my_putstr("0X");
    if (test == 2)
        return my_putstr("0x");
    if (test == 3)
        return my_putstr("0");
    if (test == 4)
        return my_putstr("0b");
    if (test == 5)
        return my_putstr("0B");
}

static int signof(int nb)
{
    if (nb >= 0) {
        my_putchar('+');
        return 1;
    }
    return 0;
}

int flag_handler_int(char *flag, int nb, int test, int i)
{
    int size = 0;
    int stock = 0;

    if (flag[i] == '+' && test == 0) {
        size = size + signof(nb);
        return size + flag_handler_int(flag, nb, test, i + 1);
    }
    if (flag[i] == '#' && test > 0) {
        size = size + dashof(test);
        return size + flag_handler_int(flag, nb, test, i + 1);
    }
    if (flag[i] != 0)
        return size + flag_handler_int(flag, nb, test, i + 1);
}

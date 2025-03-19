/*
** EPITECH PROJECT, 2024
** flag_handler_int.c
** File description:
** handle every flag
*/
#include <stdio.h>
#include "fproto.h"
static int dashof(int test, int fd)
{
    if (test == 1)
        return my_fputstr("0X", fd);
    if (test == 2)
        return my_fputstr("0x", fd);
    if (test == 3)
        return my_fputstr("0", fd);
}

static int signof(int nb, int fd)
{
    if (nb >= 0) {
        my_fputchar('+', fd);
        return 1;
    }
    return 0;
}

int fflag_handler_int(char *flag, int nb, int test, int fd)
{
    int size = 0;

    for (int i = 0; flag[i] != '\0'; i++) {
        if (flag[i] == '+' && test == 0)
            size = size + signof(nb, fd);
        if (flag[i] == '#')
            size = size + dashof(test, fd);
    }
    return size;
}
